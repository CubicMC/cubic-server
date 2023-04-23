#ifndef CONFIGURATION_SCHEMA_HPP
#define CONFIGURATION_SCHEMA_HPP

#include <string>

namespace configuration {
class Schema {
public:
    Schema() = default;

    Schema &required();
    Schema &defaultValue(const std::string &value);
};
} // namespace configuration

#endif //CONFIGURATION_SCHEMA_HPP
