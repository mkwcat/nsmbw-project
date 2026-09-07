//
//  mkwcat/Assert.hpp
//  nsmbw-project
//

#include <type_traits>

namespace mkwcat {

struct Assert {
    template <unsigned Offset, unsigned Expected>
    struct Test {
        static_assert(Offset == Expected);
    };

    constexpr Assert(
        auto
    ) {}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
    [[no_unique_address]] alignas(0) char empty[0];
#pragma clang diagnostic pop
};

#define SIZE_ASSERT(_SIZE) \
    [[__gnu__::__error__("Attempt to call the SIZE_ASSERT function.")]] void \
    CONCAT(__SizeAssert, __COUNTER__)() { \
        using Class = std::remove_cvref_t<decltype(*this)>; \
        static_assert(__datasizeof(Class) == _SIZE); \
    }

#define OFFSET_ASSERT(_OFFSET) \
    [[no_unique_address]] ::mkwcat::Assert __Assert_##_OFFSET = ::mkwcat::Assert::Test< \
        __builtin_offsetof(::std::remove_pointer_t<decltype(this)>, __Assert_##_OFFSET), \
        _OFFSET>()

static_assert(sizeof(Assert) == 0);

} // namespace mkwcat
