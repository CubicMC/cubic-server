#include "nlohmann/json.hpp"
#include <cstdint>
#include <string>
#include <vector>

namespace Items {
    // Using int32_t because it's the same size as a varint
    typedef int32_t ItemId;

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
            ItemId fromItemToProtocolId(std::string name) const;
            /**
             * @brief Convert a protocol id to an item name
             * @param id The protocol id to convert
             * @return std::string The name of the item
             */
            std::string fromProtocolIdToItem(ItemId id) const;
            /**
             * @brief Initialize the item converter with the items from the given json file
             * @param path The path to the json file
             */
            void initialize(const std::string path = "registries.json");

        private:
            std::vector<InternalItem> _items; // The internal representation of the items
    };
}
