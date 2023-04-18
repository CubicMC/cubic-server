#ifndef CUBICSERVER_PROTOCOL_TYPESERIALIZATION_HPP
#define CUBICSERVER_PROTOCOL_TYPESERIALIZATION_HPP

#include <cstdint>
#include <vector>

// bitset = std::vector<uint64_t>
// ! could throw if if we access a bit that is not in the bitset
constexpr bool BITSET_GET_BIT(const std::vector<uint64_t> &bitset, uint32_t bit) { return (bitset[bit / 64] & (1ULL << (bit % 64))) == 1; }

// ! could throw if if we access a bit that is not in the bitset
constexpr void BITSET_SET_BIT(std::vector<uint64_t> &bitset, uint32_t bit, bool value) { bitset[bit / 64] = (bitset[bit / 64] & ~(1ULL << (bit % 64))) | (value << (bit % 64)); }

#endif // CUBICSERVER_PROTOCOL_TYPESERIALIZATION_HPP
