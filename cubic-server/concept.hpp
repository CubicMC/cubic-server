#ifndef CONCEPT_HPP
#define CONCEPT_HPP

#include "nbt.hpp"

template <typename T>
concept is_nbt = std::is_base_of_v<nbt::Base, T>;

#endif // CONCEPT_HPP
