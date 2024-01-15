#ifndef SHAPE_CONVERTER_HPP
#define SHAPE_CONVERTER_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#include "collision/BoundingBox.hpp"
#include "types.hpp"

namespace Shapes {
/**
 * @brief Global palette of shapes used to convert from block id to shape
 */
class ShapeConverter {
public:
    ShapeConverter() {};
    ~ShapeConverter() {};

    /**
     * @brief Convert a block id to a shape
     * @param blockId The block id to convert
     * @return The shape of the block
     */
    std::string fromBlockIdToShape(BlockId blockId) const;

    /**
     * @brief Initialize the shape converter with the shapes from the given json file
     * @param path The path to the json file
     * @return bool True if the initialization was successful, false otherwise
     */
    bool initialize(const std::string &path = "shapes.json");

private:
    std::unordered_map<uint16_t, std::string> _shapes; // The internal representation of the shapes
};
};
#endif // SHAPE_CONVERTER_HPP
