#include "shapeConverter.hpp"

#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

#include "logging/logging.hpp"

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

std::string Shapes::ShapeConverter::fromBlockIdToShape(BlockId blockId) const
{
    if (this->_shapes.find(blockId) == this->_shapes.end()) {
        LERROR("Block id {} not found !", blockId);
        return "empty";
    }
    return this->_shapes.at(blockId);
}
