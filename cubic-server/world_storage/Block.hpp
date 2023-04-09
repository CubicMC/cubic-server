#ifndef WORLD_STORAGE_BLOCK_HPP
#define WORLD_STORAGE_BLOCK_HPP

#include <string>
#include <unordered_map>

namespace world_storage {

// TODO: PTDR
class Block {
public:
    Block();
    Block(const std::string &name, std::unordered_map<std::string, std::string> properties = {});
    std::string toString() const;
    std::string name;
    std::unordered_map<std::string, std::string> properties;
};

} // namespace world_storage

#endif // WORLD_STORAGE_BLOCK_HPP
