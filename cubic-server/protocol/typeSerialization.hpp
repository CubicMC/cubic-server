#ifndef D7286F40_D05F_4DC1_9A04_28C9F7417C4E
#define D7286F40_D05F_4DC1_9A04_28C9F7417C4E

#include "serialization/addPrimaryType.hpp"
#include "serialization/add.hpp"
#include "serialization/popPrimaryType.hpp"
#include "serialization/pop.hpp"

// bitset = std::vector<uint64_t>
// ! could throw if if we access a bit that is not in the bitset
#define BITSET_GET_BIT(bitset, bit) (bitset[bit / 64] & (1ULL << (bit % 64)) == 1)
// ! could throw if if we access a bit that is not in the bitset
#define BITSET_SET_BIT(bitset, bit, value) bitset[bit / 64] = (bitset[bit / 64] & ~(1ULL << (bit % 64))) | (value << (bit % 64))

#endif /* D7286F40_D05F_4DC1_9A04_28C9F7417C4E */
