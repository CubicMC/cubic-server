#ifndef CONCEPT_HPP
#define CONCEPT_HPP

#include "nbt.hpp"

// clang-format off

template <typename T>
concept Streamable =
requires(std::ostream &os, const T &value) {
{ os << value } -> std::convertible_to<std::ostream &>;
};

// clang-format on

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

#endif // CONCEPT_HPP
