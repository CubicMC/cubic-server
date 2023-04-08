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

template <typename T>
concept is_nbt = std::is_base_of_v<nbt::Base, T>;

#endif // CONCEPT_HPP
