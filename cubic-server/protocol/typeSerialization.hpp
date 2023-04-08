#ifndef D7286F40_D05F_4DC1_9A04_28C9F7417C4E
#define D7286F40_D05F_4DC1_9A04_28C9F7417C4E

#include "serialization/add.hpp"
#include "serialization/addPrimaryType.hpp"
#include "serialization/pop.hpp"
#include "serialization/popPrimaryType.hpp"

// bitset = std::vector<uint64_t>
// ! could throw if if we access a bit that is not in the bitset
constexpr bool BITSET_GET_BIT(const std::vector<uint64_t> &bitset, uint32_t bit) { return (bitset[bit / 64] & (1ULL << (bit % 64))) == 1; }

// ! could throw if if we access a bit that is not in the bitset
constexpr void BITSET_SET_BIT(std::vector<uint64_t> &bitset, uint32_t bit, bool value) { bitset[bit / 64] = (bitset[bit / 64] & ~(1ULL << (bit % 64))) | (value << (bit % 64)); }

#endif /* D7286F40_D05F_4DC1_9A04_28C9F7417C4E */
