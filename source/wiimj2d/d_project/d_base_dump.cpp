// d_base_dump.cpp
// nsmbw-project

#include "d_base_dump.h"

#include "d_profile/d_all_base_headers.h"
#include "d_profile/d_profile.h"
#include "d_system/d_base.h"
#include <cassert>
#include <cstring>
#include <string_view>
#include <type_traits>
#include <utility>

namespace dBaseDump {

template <std::size_t N, std::size_t N2>
consteval bool compare(
    const char (&s1)[N], const char (&s2)[N2]
) {
    if constexpr (N != N2) {
        return false;
    } else {
        for (int i = 0; i < N - 1; i++) {
            if (s1[i] != s2[i] && s2[i] != '?') {
                return false;
            }
        }
        return true;
    }
}

template <std::size_t N, std::size_t N2>
consteval bool hasPrefix(
    const char (&s1)[N], const char (&s2)[N2]
) {
    if constexpr (N < N2) {
        return false;
    } else {
        for (int i = 0; i < N2 - 1; i++) {
            if (s1[i] != s2[i] && s2[i] != '?') {
                return false;
            }
        }
        return true;
    }
}

class Analysis_c {
public:
    static constexpr std::size_t MAX_TOKENS = 512;

    enum class Token_e : u8 {
        KEY_OBJECT,
        KEY_INT,
        KEY_UINT,
        KEY_PTR,
        KEY_INLINE_PTR,
        KEY_BOOL,
        KEY_FLOAT,
        END,
    };

    enum class Size_e : u8 {
        BYTE,
        SHORT,
        WORD,
        DOUBLE,
    };

    struct DecodedToken_s {
        Token_e token;
        u8      size;
    };

    consteval Size_e getSize(
        u8 size
    ) {
        switch (size) {
        case sizeof(u8):
            return Size_e::BYTE;
        case sizeof(u16):
            return Size_e::SHORT;
        case sizeof(u32):
            return Size_e::WORD;
        case sizeof(u64):
            return Size_e::DOUBLE;
        default:
            std::unreachable();
        }
    }

    template <std::size_t N>
    consteval std::size_t findString(
        const char (&str)[N]
    ) {
        assert(N <= 256);

        for (std::size_t i = 0; i != mPosStrings;) {
            u8 size = static_cast<u8>(mStrings[i++]);
            if (size != N - 1) {
                i += size;
                continue;
            }

            for (std::size_t j = 0; mStrings[i + j] == str[j]; j++) {
                if (j == N - 2) {
                    return i - 1;
                }
            }
            i += size;
        }
        return std::string_view::npos;
    }

    template <std::size_t N>
    consteval std::size_t addString(
        const char (&name)[N]
    ) {
        assert(N <= 256);

        // Insert the name into the string table
        if constexpr (N > 3) {
            // Find if the string already exists
            if (std::size_t found = findString(name); found != std::string_view::npos) {
                return found;
            }
        }

        mStrings[mPosStrings++] = static_cast<char>(N - 1);
        for (std::size_t i = 0; i < N - 1; i++) {
            mStrings[mPosStrings++] = name[i];
        }
        return -1u;
    }

    consteval void push(
        Token_e token, const auto& name, const void* offset, u8 size, u8 arrayCount
    ) {
        Size_e      sizeEnum  = getSize(size);
        std::size_t clonePos  = addString(name);

        mTokens[mPosTokens++] = (static_cast<u8>(token) << 5) | (static_cast<u8>(sizeEnum) << 3) |
                                (1 << 2) | ((clonePos != -1u) << 1);
        mTokens[mPosTokens++]   = arrayCount - 1;
        mOffsets[mPosOffsets++] = offset;
        if (clonePos != -1u) {
            mTokens[mPosTokens++] = clonePos >> 8;
            mTokens[mPosTokens++] = clonePos & 0xFF;
        }
    }

    consteval void push(
        Token_e token, const auto& name, const void* offset, u8 size
    ) {
        Size_e      sizeEnum  = getSize(size);
        std::size_t clonePos  = addString(name);

        mTokens[mPosTokens++] = (static_cast<u8>(token) << 5) | (static_cast<u8>(sizeEnum) << 3) |
                                ((clonePos != -1u) << 1);
        mOffsets[mPosOffsets++] = offset;
        if (clonePos != -1u) {
            mTokens[mPosTokens++] = clonePos >> 8;
            mTokens[mPosTokens++] = clonePos & 0xFF;
        }
    }

    consteval void push(
        Token_e token, const auto& name
    ) {
        std::size_t clonePos  = addString(name);

        mTokens[mPosTokens++] = (static_cast<u8>(token) << 5) | ((clonePos != -1u) << 1);
        if (clonePos != -1u) {
            mTokens[mPosTokens++] = clonePos >> 8;
            mTokens[mPosTokens++] = clonePos & 0xFF;
        }
    }

    consteval void push(
        Token_e token
    ) {
        mTokens[mPosTokens++] = (static_cast<u8>(token) << 5);
    }

    template <class T, class... Args>
    consteval void pushAuto(
        const Args&... args
    ) {
        Token_e token;
        if constexpr (std::is_same_v<std::remove_cvref_t<T>, bool>) {
            token = Token_e::KEY_BOOL;
        } else if constexpr (std::is_integral_v<T> || std::is_enum_v<T>) {
            if constexpr (std::is_signed_v<T>) {
                token = Token_e::KEY_INT;
            } else {
                token = Token_e::KEY_UINT;
            }
        } else if constexpr (std::is_floating_point_v<T>) {
            token = Token_e::KEY_FLOAT;
        } else if constexpr (std::is_pointer_v<T>) {
            token = Token_e::KEY_PTR;
        } else {
            std::unreachable();
        }
        return push(token, args...);
    }

    template <class T>
    consteval void pushArray(
        const auto& name, const void* offset
    ) {
        using ElemType                      = std::remove_cvref_t<std::remove_all_extents_t<T>>;
        constexpr std::size_t c_array_count = sizeof(T) / sizeof(ElemType);
        if (c_array_count > 256 || std::is_class_v<ElemType>) {
            return push(Token_e::KEY_INLINE_PTR, name, offset, 1);
        }
        assert(c_array_count != 0);
        return pushAuto<ElemType>(name, offset, sizeof(ElemType), c_array_count);
    }

    static consteval bool isAccepted(
        const auto& name
    ) {
        return !hasPrefix(name, "__Fill") && !hasPrefix(name, "dProf::Info<");
    }

    static consteval void dumpAnalyze(
        Analysis_c& self, const auto& format
    ) {
        // " {\n" ignored
        if (compare(format, "}\n")) {
            self.push(Analysis_c::Token_e::END);
        }
    }

    static consteval void dumpAnalyze(
        Analysis_c& self, const auto& format, const auto& arg0
    ) {
        if (compare(format, "%s")) {
            // Top-level object
            self.push(Analysis_c::Token_e::KEY_OBJECT, arg0);
        }
        if (compare(format, "%s}\n")) {
            if (self.mSkipDepth) {
                self.mSkipDepth--;
                return;
            }
            self.push(Analysis_c::Token_e::END);
        }
    }

    static consteval void dumpAnalyze(
        Analysis_c& self, const auto& format, const auto& arg0, const auto& arg1
    ) {
        if (compare(format, "%s%s")) {
            // Base object
            if (self.mSkipDepth || !isAccepted(arg1)) {
                self.mSkipDepth++;
                return;
            }
            self.push(Analysis_c::Token_e::KEY_OBJECT, arg1);
        }
    }

    static consteval void dumpAnalyze(
        Analysis_c& self, const auto& format, const auto& arg0, const auto& arg1, const auto& arg2
    ) {
        if (compare(format, "%s%s %s =")) {
            // Object key
            if (self.mSkipDepth || !isAccepted(arg2)) {
                self.mSkipDepth++;
                return;
            }
            self.push(Analysis_c::Token_e::KEY_OBJECT, arg2);
        }
    }

    template <class T>
    static consteval void dumpAnalyze(
        Analysis_c& self, const auto& format, const auto& arg0, const auto& arg1, const auto& arg2,
        const T& value
    ) {
        if (self.mSkipDepth || !isAccepted(arg2)) {
            return;
        }

        if constexpr (std::is_array_v<std::remove_pointer_t<T>>) {
            if (compare(format, "%s%s %s = *%p\n")) {
                return self.pushArray<std::remove_pointer_t<T>>(
                    arg2, ::__builtin_addressof(*value)
                );
            }
        } else if (compare(format, "%s%s %s = %?\n") || compare(format, "%s%s %s = %l?\n") ||
                   compare(format, "%s%s %s = %ll?\n")) {
            return self.pushAuto<T>(arg2, ::__builtin_addressof(value), sizeof(value));
        }
    }

    template <class T>
    consteval void analyze(
        const T* obj
    ) {
        ::__builtin_dump_struct(obj, dumpAnalyze, *this);
    }

    std::size_t mPosStrings      = 0;
    char        mStrings[0x8000] = {};
    std::size_t mPosTokens       = 0;
    u8          mTokens[0x2000]  = {};
    std::size_t mPosOffsets      = 0;
    const void* mOffsets[0x1000] = {};
    int         mSkipDepth       = 0;
};

struct Structure_s {
    u16  posStrings;
    u16  posTokens;
    u16  posOffsets;
    bool derivedFromActor;
    bool derivedFromEnemy;
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-var-template"
template <class T> extern const T UNDEF_00000000;

template <
    std::size_t SizeStrings, std::size_t SizeTokens, std::size_t SizeOffsets,
    std::size_t SizeStructures>
struct AnalysisResult_s {
    std::array<char, SizeStrings>           strings;
    std::array<u8, SizeTokens>              tokens;
    std::array<const void*, SizeOffsets>    offsets;
    std::array<Structure_s, SizeStructures> structures;
};

template <class... Objects> class StructureProviderIf_c {
public:
    static constexpr std::size_t cCount = sizeof...(Objects);

    template <class T = void>
    static constexpr std::size_t cPos = [] {
        if constexpr (std::is_void_v<T> || !std::is_class_v<T>) {
            return cCount;
        } else {
            std::size_t i   = 0;
            std::size_t pos = 0;
            (void) ((std::is_same_v<T, Objects> ? (pos = i, true) : (i++, false)) || ...);
            return pos;
        }
    }();

private:
    static constexpr auto analyze() {
        std::pair<Analysis_c, std::array<Structure_s, cCount>> result;
        //
        std::size_t index = 0;
        ((result.second[index++] =
              {.posStrings       = static_cast<u16>(result.first.mPosStrings),
               .posTokens        = static_cast<u16>(result.first.mPosTokens),
               .posOffsets       = static_cast<u16>(result.first.mPosOffsets),
               .derivedFromActor = std::is_base_of_v<dActor_c, Objects>,
               .derivedFromEnemy = std::is_base_of_v<dEn_c, Objects>},
          result.first.analyze(&UNDEF_00000000<Objects>)),
         ...);
        return result;
    }

public:
    static constinit inline const auto s_result = [] {
        constexpr auto cAnalysis = analyze();
        return AnalysisResult_s<
            cAnalysis.first.mPosStrings, cAnalysis.first.mPosTokens, cAnalysis.first.mPosOffsets,
            cAnalysis.second.size()>{
            .strings =
                [&cAnalysis] {
                    std::array<char, cAnalysis.first.mPosStrings> strings;
                    std::copy(
                        cAnalysis.first.mStrings,
                        cAnalysis.first.mStrings + cAnalysis.first.mPosStrings, strings.begin()
                    );
                    return strings;
                }(),
            .tokens =
                [&cAnalysis] {
                    std::array<u8, cAnalysis.first.mPosTokens> tokens;
                    std::copy(
                        cAnalysis.first.mTokens,
                        cAnalysis.first.mTokens + cAnalysis.first.mPosTokens, tokens.begin()
                    );
                    return tokens;
                }(),
            .offsets =
                [&cAnalysis] {
                    std::array<const void*, cAnalysis.first.mPosOffsets> offsets;
                    std::copy(
                        cAnalysis.first.mOffsets,
                        cAnalysis.first.mOffsets + cAnalysis.first.mPosOffsets, offsets.begin()
                    );
                    return offsets;
                }(),
            .structures = cAnalysis.second
        };
    }();
};

using StructureProvider_c = StructureProviderIf_c<
#define PROFILE(id, name, ...) __VA_OPT__(__VA_ARGS__, )
#include "d_profile/d_profile_table.inc"
#undef PROFILE
    dActor_c, dEn_c>;

void dumpStructure(
    std::FILE* out, const void* ptr, u16 structure
) {
    if (structure == StructureProvider_c::cCount) {
        std::fprintf(out, "no information\r\n");
        return;
    }

    std::fprintf(out, "\r\n");

    const Structure_s&   info            = StructureProvider_c::s_result.structures[structure];
    const char* const    strings         = StructureProvider_c::s_result.strings.data();
    const char*          s               = strings + info.posStrings;
    const u8*            t               = &StructureProvider_c::s_result.tokens[info.posTokens];
    const void* const*   o               = &StructureProvider_c::s_result.offsets[info.posOffsets];

    int                  indent          = 0;
    static const char    c_indentStr[17] = "                ";
    static constexpr int c_indentWidth   = 2;

    while (true) {
        // Required info on every token
        const u8                  tokenByte = *t++;
        const Analysis_c::Token_e token     = static_cast<Analysis_c::Token_e>(tokenByte >> 5);
        const Analysis_c::Size_e  size      = static_cast<Analysis_c::Size_e>((tokenByte >> 3) & 3);

        // Flags about this token
        const bool hasValue =
            token != Analysis_c::Token_e::KEY_OBJECT && token != Analysis_c::Token_e::END;
        const bool hasName       = token != Analysis_c::Token_e::END;
        const bool hasReusedName = tokenByte & 1_bit;
        const bool isArray       = tokenByte & 2_bit;

        // Read the optional data
        const int   arrayCount   = isArray ? 1 + *t++ : 1;
        const void* offset =
            hasValue ? reinterpret_cast<const u8*>(ptr) + reinterpret_cast<u32>(*o++) : nullptr;

        const char* name;
        if (hasReusedName) {
            const u16 nameOffset = (t[0] << 8) | t[1];
            t += 2;
            name = strings + nameOffset;
        } else if (hasName) {
            name = s;
            s += 1 + s[0];
        }

        if (token == Analysis_c::Token_e::KEY_OBJECT) {
            std::fprintf(out, "%.*s%.*s { \r\n", indent, c_indentStr, *name, name + 1);
            indent += c_indentWidth;
        } else if (token == Analysis_c::Token_e::END) {
            indent = std::max(0, indent - c_indentWidth);
            std::fprintf(out, "%.*s}\r\n", indent, c_indentStr);
        }

        if (indent < c_indentWidth) {
            break;
        }

        if (!hasValue || !hasName) {
            continue;
        }

        std::fprintf(
            out, "%.*s%.*s%s", indent, c_indentStr, *name, name + 1, !isArray ? " = " : " = {"
        );
        const bool           breakEachElement = arrayCount > 8;
        static constexpr int breakAt          = 8;
        int                  breakCounter     = breakAt;

        for (int elem = 0; elem < arrayCount; elem++) {
            if (breakEachElement && breakCounter++ == breakAt) {
                std::fprintf(out, "\r\n%.*s", indent + c_indentWidth, c_indentStr);
                breakCounter = 0;
            }
            const bool hasComma = breakEachElement || elem + 1 < arrayCount;

            if (token == Analysis_c::Token_e::KEY_INLINE_PTR) {
                std::fprintf(out, "*%p%s", offset, hasComma ? "," : "");
                // Offset has no adjustment
                continue;
            }

            if (token == Analysis_c::Token_e::KEY_FLOAT) {
                double value;
                if (size == Analysis_c::Size_e::DOUBLE) {
                    const f64* ptr = reinterpret_cast<const f64*>(offset);
                    value          = *ptr++;
                    offset         = ptr;
                } else {
                    const f32* ptr = reinterpret_cast<const f32*>(offset);
                    value          = *ptr++;
                    offset         = ptr;
                }
                std::fprintf(out, "*%f%s", value, hasComma ? "," : "");
                continue;
            }

            u64        value;
            const bool isSigned = token == Analysis_c::Token_e::KEY_INT;
            switch (size) {
            case Analysis_c::Size_e::BYTE: {
                const u8* ptr = reinterpret_cast<const u8*>(offset);
                value         = *ptr++;
                offset        = ptr;
                if (isSigned) {
                    value = static_cast<s64>(static_cast<s8>(value));
                }
                break;
            }
            case Analysis_c::Size_e::SHORT: {
                const u16* ptr = reinterpret_cast<const u16*>(offset);
                value          = *ptr++;
                offset         = ptr;
                if (isSigned) {
                    value = static_cast<s64>(static_cast<s16>(value));
                }
                break;
            }
            case Analysis_c::Size_e::WORD: {
                const u32* ptr = reinterpret_cast<const u32*>(offset);
                value          = *ptr++;
                offset         = ptr;
                if (isSigned) {
                    value = static_cast<s64>(static_cast<s32>(value));
                }
                break;
            }
            case Analysis_c::Size_e::DOUBLE: {
                const u64* ptr = reinterpret_cast<const u64*>(offset);
                value          = *ptr++;
                offset         = ptr;
                break;
            }
            }

            switch (token) {
            case Analysis_c::Token_e::KEY_INT:
                std::fprintf(out, "%lld%s", value, hasComma ? "," : "");
                break;

            case Analysis_c::Token_e::KEY_UINT:
                std::fprintf(out, "%llu%s", value, hasComma ? "," : "");
                break;

            case Analysis_c::Token_e::KEY_PTR:
                std::fprintf(out, "0x%08llx%s", value, hasComma ? "," : "");
                break;

            case Analysis_c::Token_e::KEY_BOOL:
                std::fprintf(out, "%s%s", value ? "true" : "false", hasComma ? "," : "");
                break;

            default:
                std::unreachable();
            }
        }

        if (breakEachElement) {
            std::fprintf(out, "\r\n%.*s}\r\n", indent, c_indentStr);
        } else if (isArray) {
            std::fprintf(out, "}\r\n");
        } else {
            std::fprintf(out, "\r\n");
        }
    }
}

static constinit const u16 c_profileToStructure[] = {
#define PROFILE(id, name, type) [id] = static_cast<u16>(StructureProvider_c::cPos<type>),
#include "d_profile/d_profile_table.inc"
#undef PROFILE
};

void dump(
    std::FILE* out, const dBase_c* base
) {
    std::fprintf(
        out, "-----%08lX: %03d: '%s'-----\r\n", reinterpret_cast<std::size_t>(base),
        base->mProfName, dProf::getName(base->mProfName)
    );

    dProfName staticName = dProf::toStatic(base->mProfName);
    dumpStructure(out, static_cast<const void*>(base), c_profileToStructure[staticName]);
}

void dumpAll(
    std::FILE* out
) {
    for (const fBase_c* base = fManager_c::getNextBase(); base != nullptr;
         base                = fManager_c::getNextBase(base)) {
        dump(out, static_cast<const dBase_c*>(base));
    }
}

[[gnu::constructor]]
void testDump() {
    std::fprintf(stdout, "test dump\n");
    dumpAll(stdout);
}

} // namespace dBaseDump
