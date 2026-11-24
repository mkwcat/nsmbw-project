#pragma once

#include "member_pointer.hpp"

namespace slu {

// Delegate compatible with Mario Kart Wii's UI handlers interface

template <class FunctionType>
class delegate {
    static_assert(false, "Invalid template parameters provided to Delegate");
};

template <class FunctionType>
using delegate_ref = const delegate<FunctionType>&;

// Specify function with Delegate<FunctionType>
template <class ReturnType, class... Args>
class delegate<ReturnType(Args...)> {
public:
    using function_type = ReturnType(Args...);

    template <class ClassType>
    using member_function_type = ReturnType (ClassType::*)(Args...);

public:
    constexpr delegate(
        function_type* function
    )
        : m_object_union(function) {}

    virtual ReturnType operator()(
        Args... args
    ) const {
        return (*m_object_union.m_function)(args...);
    }

protected:
    union object_union {
        function_type* m_function;
        void*          m_object;
    } m_object_union;

    constexpr delegate()
        : m_object_union(nullptr) {}

    void set_object(
        void* object
    ) {
        m_object_union.m_object = object;
    }
};

// Specify member function with Delegate<MemberFunctionType>
template <class ClassType, class ReturnType, class... Args>
class delegate<ReturnType (ClassType::*)(Args...)> : public delegate<ReturnType(Args...)> {
public:
    using base_delegate        = delegate<ReturnType(Args...)>;
    using member_function_type = ReturnType (ClassType::*)(Args...);

public:
    constexpr delegate(
        ClassType* object, member_function_type function
    ) {
        base_delegate::set_object(object);
        m_member_function = function;
    }

    virtual ReturnType operator()(
        Args... args
    ) const override {
        return static_cast<ClassType*>(base_delegate::m_object_union.m_object)
            ->m_member_function(args...);
    }

protected:
    member_function_type m_member_function;
#ifdef CLANGD
    [[no_unique_address]] slu::ptmf_size_pad<> m_ptmf_pad;
#endif
};

// Pass the function pointer directly through the template
template <auto Method, class FunctionType = decltype(Method)>
class invoker_delegate;

// InvokerDelegate for instance method
template <class ClassType, auto Method, class ReturnType, class... Args>
class invoker_delegate<Method, ReturnType (ClassType::*)(Args...)>
    : public delegate<ReturnType(Args...)> {
public:
    using base_delegate = delegate<ReturnType(Args...)>;
    using is_const      = std::bool_constant<false>;

    constexpr invoker_delegate(
        ClassType* object
    ) {
        base_delegate::set_object(object);
    }

    virtual ReturnType operator()(
        Args... args
    ) const override {
        return (base_delegate::m_object_union.m_object->*Method)(args...);
    }
};

// InvokerDelegate for const instance method
template <class ClassType, auto Method, class ReturnType, class... Args>
class invoker_delegate<Method, ReturnType (ClassType::*)(Args...) const>
    : public delegate<ReturnType(Args...)> {
public:
    using base_delegate = delegate<ReturnType(Args...)>;
    using is_const      = std::bool_constant<true>;

    constexpr invoker_delegate(
        const ClassType* object
    ) {
        base_delegate::set_object(const_cast<ClassType*>(object));
    }

    virtual ReturnType operator()(
        Args... args
    ) const override {
        return (static_cast<ClassType*>(base_delegate::m_object_union.m_object)->*Method)(args...);
    }
};

// InvokerDelegate for static method
template <const auto Method, class ReturnType, class... Args>
class invoker_delegate<Method, ReturnType(Args...)> : public delegate<ReturnType(Args...)> {
public:
    constexpr invoker_delegate() = default;

    constexpr invoker_delegate(
        const void* p
    ) {}

    virtual ReturnType operator()(
        Args... args
    ) const override {
        return Method(args...);
    }
};

// LambdaDelegate; supports template parameter deduction
template <class Callable>
class lambda_delegate : public invoker_delegate<&Callable::operator()> {
public:
    using function_type      = decltype(&Callable::operator());
    using invoker            = invoker_delegate<&Callable::operator()>;
    using is_member_function = std::is_member_function_pointer<function_type>;

    constexpr lambda_delegate()
        requires(!is_member_function::value)
    = default;

    [[gnu::always_inline]]
    constexpr lambda_delegate(
        const Callable& object
    )
        requires(is_member_function::value && invoker::is_const::value)
        : invoker(&object) {
        invoker::set_object(const_cast<Callable*>(&object)); // Needed due to compiler bug
    }

    [[gnu::always_inline]]
    constexpr lambda_delegate(
        Callable& object
    )
        requires(is_member_function::value && !invoker::is_const::value)
        : invoker(&object) {
        invoker::set_object(&object); // Needed due to compiler bug
    }

    [[gnu::always_inline]]
    constexpr lambda_delegate(
        Callable&& object
    )
        requires(is_member_function::value && !invoker::is_const::value)
        : invoker(&object) {
        invoker::set_object(&object); // Needed due to compiler bug
    }
};

} // namespace slu
