//
//  slu/identity.hpp
//  supplemental-language-utilities
//

#pragma once

#include <array>
#include <cstring>
#include <string_view>
#include <utility>

namespace slu {

template <auto V>
struct value_identity {
    static constexpr auto value = V;
    using value_type            = decltype(V);
};

template <class T>
constexpr std::string_view type_name() {
    static constexpr auto start_length = [](const char* pf) -> std::pair<std::size_t, std::size_t> {
        std::size_t length = std::strlen(pf);

        std::size_t start  = sizeof "const char *slu::type_name() [T = " - 1;
        if (pf[start + 0] == 'U' && pf[start + 1] == 'I' && pf[start + 2] == ':' &&
            pf[start + 3] == ':') {
            start += 4;
        }
        length -= start;
        length -= sizeof "]" - 1;

        return {start, length};
    }(__PRETTY_FUNCTION__);

    static constexpr auto name = [](const char* pf) {
        std::array<char, start_length.second + 1> name;
        for (std::size_t i = 0; i < start_length.second; i++) {
            name[i] = pf[start_length.first + i];
        }
        name[start_length.second] = 0;
        return name;
    }(__PRETTY_FUNCTION__);

    return {name.begin(), name.size() - 1};
}

} // namespace slu
