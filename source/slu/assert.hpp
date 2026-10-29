//
//  slu/assert.hpp
//  supplemental-language-utilities
//

namespace slu {

struct assert_object {
    template <__SIZE_TYPE__ Offset, __SIZE_TYPE__ Expected>
    struct Test {
        static_assert(Offset == Expected);
    };

    constexpr assert_object(
        auto
    ) {}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
    [[no_unique_address]] alignas(0) char empty[0];
#pragma clang diagnostic pop
};

#define SIZE_ASSERT(_SIZE) \
    [[__gnu__::__error__("Attempt to call the SIZE_ASSERT function.")]] \
    void CONCAT(__SizeAssert, __COUNTER__)() { \
        using Class = __remove_cvref(decltype(*this)); \
        static_assert(__datasizeof(Class) == _SIZE); \
    }

#define OFFSET_ASSERT(_OFFSET) \
    [[no_unique_address]] \
    ::slu::assert_object __Assert_##_OFFSET = ::slu::assert_object::Test< \
        __builtin_offsetof(__remove_pointer(decltype(this)), __Assert_##_OFFSET), _OFFSET>()

static_assert(sizeof(assert_object) == 0);

} // namespace slu
