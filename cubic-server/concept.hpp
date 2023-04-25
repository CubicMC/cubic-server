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

#endif // CONCEPT_HPP
