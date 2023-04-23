#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <array>
#include <cstdint>

template<size_t N>
class Inventory {
public:

private:
    std::array<uint32_t, N> items;
};


#endif // INVENTORY_HPP
