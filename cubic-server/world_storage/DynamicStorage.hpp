#ifndef WORLD_STORAGE_DYNAMICSTORAGE_HPP
#define WORLD_STORAGE_DYNAMICSTORAGE_HPP

#include "exceptions.hpp"
#include "world_storage/Palette.hpp"
#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace world_storage {

DEFINE_EXCEPTION(EmptyStorageAccess);

/**
 * @brief  A class that stores values of a given size in an array of a given type
 * It stores several entries within a single StoreType
 * individual entries never span across multiple StoreType
 *
 * It is used to store blocks and biomes in a section
 *
 * @tparam StoreType The type that will be used to store the values
 * @tparam ArraySize The size of the array of StoreType
 */
template<typename StoreType, uint64_t ArraySize>
    requires std::is_fundamental_v<StoreType>
class DynamicStorage {
public:
    typedef std::vector<StoreType> Array;
    typedef typename Array::iterator iterator;
    typedef typename Array::const_iterator const_iterator;
    constexpr static const uint16_t StoreTypeSize = sizeof(StoreType) * 8;

public:
    constexpr explicit DynamicStorage(uint8_t valueSize = 0);

    constexpr void setValueSize(uint8_t valueSize);

    constexpr void set(uint64_t idx, StoreType value);
    [[nodiscard]] constexpr StoreType get(uint64_t idx) const;
    [[nodiscard]] constexpr bool canContainData() const { return _valueSize != 0; }

    [[nodiscard]] constexpr Array &data() { return _store; }
    [[nodiscard]] constexpr const Array &data() const { return _store; }

    [[nodiscard]] constexpr iterator begin() { return _store.begin(); }
    [[nodiscard]] constexpr const_iterator begin() const { return _store.begin(); }

    [[nodiscard]] constexpr iterator end() { return _store.end(); }
    [[nodiscard]] constexpr const_iterator end() const { return _store.end(); }

private:
    Array _store;
    uint8_t _valueSize;
};

template<typename StoreType, uint64_t ArraySize>
    requires std::is_fundamental_v<StoreType>
constexpr DynamicStorage<StoreType, ArraySize>::DynamicStorage(uint8_t valueSize)
{
    if (valueSize > StoreTypeSize)
        throw std::logic_error("valueSize is too big for StoreType");

    _valueSize = valueSize;
    if (valueSize == 0)
        return;
    _store.resize(ArraySize / (StoreTypeSize / valueSize) + (ArraySize % (StoreTypeSize / valueSize) ? 1 : 0));
}

template<typename StoreType, uint64_t ArraySize>
    requires std::is_fundamental_v<StoreType>
constexpr void DynamicStorage<StoreType, ArraySize>::setValueSize(uint8_t valueSize)
{
    if (valueSize == _valueSize)
        return;
    if (valueSize > StoreTypeSize)
        throw std::runtime_error("valueSize is invalid");
    if (valueSize == 0) {
        _store.clear();
        _valueSize = 0;
        return;
    }

    DynamicStorage<StoreType, ArraySize> newStore(valueSize);

    if (_valueSize == 0) {
        *this = newStore;
        return;
    }

    for (uint64_t i = 0; i < ArraySize; ++i)
        newStore.set(i, get(i));

    *this = newStore;
}

template<typename StoreType, uint64_t ArraySize>
    requires std::is_fundamental_v<StoreType>
constexpr void DynamicStorage<StoreType, ArraySize>::set(uint64_t idx, StoreType value)
{
    if (_valueSize == 0)
        return;
    if (idx >= ArraySize)
        throw std::out_of_range("idx is out of range");
    if (value > (uint64_t) ((1 << _valueSize) - 1))
        throw std::out_of_range("value is too big");

    uint64_t entryNumber = idx / (StoreTypeSize / _valueSize);
    int8_t startOffset = (idx % (StoreTypeSize / _valueSize)) * _valueSize;
    StoreType mask = ((1 << _valueSize) - 1);

    value &= mask;
    _store.at(entryNumber) &= ~(mask << startOffset);
    _store.at(entryNumber) |= (value << startOffset);
}

template<typename StoreType, uint64_t ArraySize>
    requires std::is_fundamental_v<StoreType>
constexpr StoreType DynamicStorage<StoreType, ArraySize>::get(uint64_t idx) const
{
    if (_valueSize == 0)
        throw EmptyStorageAccess("Storage is null");
    if (idx >= ArraySize)
        throw std::out_of_range("idx is out of range");
    uint64_t valuePerEntry = StoreTypeSize / _valueSize;
    uint64_t entryNumber = idx / valuePerEntry;
    int8_t startOffset = (idx % valuePerEntry) * _valueSize;
    StoreType mask = ((1 << _valueSize) - 1);

    return (_store.at(entryNumber) >> startOffset) & mask;
}

} // namespace world_storage

#endif // WORLD_STORAGE_DYNAMICSTORAGE_HPP
