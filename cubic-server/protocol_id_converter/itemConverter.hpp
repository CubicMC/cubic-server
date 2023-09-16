#ifndef CUBICSERVER_PROTOCOLIDCONVERTER_ITEMCONVERTER_HPP
#define CUBICSERVER_PROTOCOLIDCONVERTER_ITEMCONVERTER_HPP

#include <string>
#include <vector>

#include "types.hpp"

namespace Items {
/**
 * @brief Internal representation of an item (only used in the ItemConverter class)
 */
struct InternalItem {
    std::string name;
    uint16_t protocolId;
};
/**
 * @brief Global palette of items used to convert from protocol id to item and vice versa
 */
class ItemConverter {
public:
    ItemConverter() {};
    ~ItemConverter() {};

    /**
     * @brief Convert an item name to a protocol id
     * @param name The name of the item
     * @return ItemId The protocol id of the item
     */
    ItemId fromItemToProtocolId(const std::string &name) const;

    /**
     * @brief Convert a protocol id to an item name
     * @param id The protocol id to convert
     * @return std::string The name of the item
     */
    std::string fromProtocolIdToItem(ItemId id) const;

    /**
     * @brief Initialize the item converter with the items from the given json file
     * @param path The path to the json file
     * @return bool True if the initialization was successful, false otherwise
     */
    bool initialize(const std::string &path = "registries.json");

private:
    std::vector<InternalItem> _items; // The internal representation of the items
};
}

#endif // CUBICSERVER_PROTOCOLIDCONVERTER_ITEMCONVERTER_HPP
