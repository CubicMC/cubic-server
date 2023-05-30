#ifndef CONCEPT_HPP
#define CONCEPT_HPP

#include <concepts>
#include <functional>
#include <ostream>

// clang-format off

template <typename T>
concept Streamable =
requires(std::ostream &os, const T &value) {
{ os << value } -> std::convertible_to<std::ostream &>;
};

template<typename Derived, typename Base>
concept isBaseOf = std::is_base_of_v<Base, Derived>;

template<typename T>
concept isEnum = std::is_enum_v<T>;

template<typename ret>
struct helperSameFunction;

template<typename ret, typename ...args>
struct helperSameFunction<ret(args...)> {
    using retType = ret;
    using argsType = std::tuple<args...>;
    using function = std::function<ret(args...)>;
};

template<typename From, typename Help>
concept sameFunction = requires (typename Help::argsType args, From from) {
    static_cast<typename Help::function>(std::declval<From>());
    requires std::same_as<
    decltype(std::apply(typename Help::function(), args)),
    decltype(std::apply(from, args))
    >;
};

// clang-format on

#endif // CONCEPT_HPP
