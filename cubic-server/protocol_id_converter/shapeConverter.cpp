#include "shapeConverter.hpp"

#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

#include "logging/logging.hpp"

const BoundingBox Shapes::ShapeConverter::BLOCK_SHAPE({1, 1, 1});
const BoundingBox Shapes::ShapeConverter::EMPTY_SHAPE({0, 0, 0});

bool Shapes::ShapeConverter::initialize(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        LERROR("File {} not found !", path);
        return false;
    }
    nlohmann::json file = nlohmann::json::parse(std::ifstream(path));
    for (auto block : file.items()) {
        this->_shapes[stoi(block.key())] = block.value();
    }
    return true;
}

