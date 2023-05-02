#ifndef CONFIGURATION_CONVERSION_HPP
#define CONFIGURATION_CONVERSION_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace configuration::_details {

template<typename T>
struct Convertor {
    T operator()(const std::string &value);
    std::vector<T> operator()(const std::vector<std::string> &values);

    T operator()(const auto &value);
    template<typename U>
    std::vector<T> operator()(const std::vector<U> &values);
};

template<>
struct Convertor<std::string> {
    std::string operator()(const char value[]) { return value; }
    std::string operator()(const std::string &value) { return value; }
    std::string operator()(const std::nullptr_t) { return "null"; }
    std::string operator()(const auto &value) { return std::to_string(value); }
    std::string operator()(bool value) { return value ? "true" : "false"; }
};

template<>
struct Convertor<std::nullptr_t> {
    std::nullptr_t operator()(auto) { return nullptr; }
};

template<>
struct Convertor<bool> {
    bool operator()(const std::string &value) { return value == "true"; }
    bool operator()(const auto &value) { return Convertor<bool>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<float> {
    float operator()(const std::string &value) { return std::stof(value); }
    float operator()(const auto &value) { return Convertor<float>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<double> {
    double operator()(const std::string &value) { return std::stod(value); }
    double operator()(const auto &value) { return Convertor<double>()(value); }
};

template<>
struct Convertor<int8_t> {
    int8_t operator()(const std::string &value) { return static_cast<int8_t>(std::stoi(value)); }
    int8_t operator()(const auto &value) { return Convertor<int8_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<int16_t> {
    int16_t operator()(const std::string &value) { return static_cast<int16_t>(std::stoi(value)); }
    int16_t operator()(const auto &value) { return Convertor<int16_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<int32_t> {
    int32_t operator()(const std::string &value) { return std::stoi(value); }
    int32_t operator()(const auto &value) { return Convertor<int32_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<int64_t> {
    int64_t operator()(const std::string &value) { return std::stol(value); }
    int64_t operator()(const auto &value) { return Convertor<int64_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<uint8_t> {
    uint8_t operator()(const std::string &value) { return static_cast<uint8_t>(std::stoi(value)); }
    uint8_t operator()(const auto &value) { return Convertor<uint8_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<uint16_t> {
    uint16_t operator()(const std::string &value) { return static_cast<uint16_t>(std::stoi(value)); }
    uint16_t operator()(const auto &value) { return Convertor<uint16_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<uint32_t> {
    uint32_t operator()(const std::string &value) { return static_cast<uint32_t>(std::stoi(value)); }
    uint32_t operator()(const auto &value) { return Convertor<uint32_t>()(Convertor<std::string>()(value)); }
};

template<>
struct Convertor<uint64_t> {
    uint64_t operator()(const std::string &value) { return std::stoul(value); }
    uint64_t operator()(const auto &value) { return Convertor<uint64_t>()(Convertor<std::string>()(value)); }
};

template<typename T>
struct Convertor<std::vector<T>> {
    std::vector<T> operator()(const std::vector<std::string> &values)
    {
        std::vector<T> convertedValues;
        auto convertor = Convertor<T>();
        convertedValues.reserve(values.size());
        for (const auto &value : values)
            convertedValues.push_back(convertor(value));
        return convertedValues;
    }

    template<typename U>
    std::vector<std::string> operator()(const std::vector<U> &values)
    {
        std::vector<std::string> convertedValues;
        auto convertor = Convertor<std::string>();
        convertedValues.reserve(values.size());
        for (const auto &value : values)
            convertedValues.push_back(convertor(value));
        return convertedValues;
    }
};

} // namespace configuration::_details

#endif // CONFIGURATION_Convertor_HPP
