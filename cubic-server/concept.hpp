#ifndef CONCEPT_HPP
#define CONCEPT_HPP

#include "nbt.hpp"
#include <functional>
#include <concepts>

// clang-format off

template <typename T>
concept Streamable =
requires(std::ostream &os, const T &value) {
{ os << value } -> std::convertible_to<std::ostream &>;
};

template<typename T>
concept IsNbt = std::is_base_of_v<nbt::Base, T>;

template<typename Child, typename Base>
concept IsBaseOf = std::is_base_of_v<Base, Child>;

template<typename Derived, typename Base>
concept is_base_of = std::is_base_of_v<Base, Derived>;

template<typename Enum, typename T>
concept is_enum = std::is_enum_v<Enum> && std::is_same_v<std::underlying_type_t<Enum>, T>;

template<typename T, typename... Args>
concept is_one_of = sizeof...(Args) != 0 && (std::is_same_v<T, Args> || ...);

template<typename T, typename... Args>
concept is_one_or_convertible_to_one_of = sizeof...(Args) != 0 && (std::is_convertible_v<T, Args> || ...);

template<typename ret>
struct helperSameFunction;

template<typename ret, typename ...args>
struct helperSameFunction<ret(args...)> {
    using retType = ret;
    using argsType = std::tuple<args...>;
    using function = std::function<ret(args...)>;
};

template<typename From, typename Help>
concept sameFunction = requires (Help::argsType args, From from) {
    static_cast<Help::function>(std::declval<From>());
    requires std::same_as<
    decltype(std::apply(typename Help::function(), args)),
    decltype(std::apply(from, args))
    >;
};

// clang-format on

#endif // CONCEPT_HPP
