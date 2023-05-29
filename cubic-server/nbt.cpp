#include "nbt.hpp"
#include <optional>

using namespace nbt;

static std::optional<std::string> parseName(uint8_t *&at, const uint8_t *end)
{
    std::string value = "";

    if (at + 1 > end)
        return std::nullopt;

    uint16_t nameSize = (*at << 8) | at[1];
    at += 2;

    if (nameSize == 0)
        return std::optional<std::string>("");
    if (at + nameSize - 1 > end)
        return std::nullopt;

    for (auto i = 0; i < nameSize; i++)
        value.push_back(*at++);
    return std::optional<std::string>(value);
}

// Yeah that is bad I know, but it's that or I copy paste :)
#define GET_NAME()                     \
    std::string name = "";             \
    if (includeName) {                 \
        auto tmp = parseName(at, end); \
        if (!tmp)                      \
            return nullptr;            \
        name = tmp.value();            \
    }

std::shared_ptr<Byte> nbt::parseByte(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Byte)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 0)
        return nullptr;

    int8_t value = *at++;

    return std::make_shared<Byte>(name, value);
}

std::shared_ptr<Short> nbt::parseShort(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Short)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 1)
        return nullptr;

    int16_t value = 0;
    for (int i = 0; i < 2; i++)
        value = (value << 8) | *at++;

    return std::make_shared<Short>(name, value);
}

std::shared_ptr<Int> nbt::parseInt(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Int)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 3)
        return nullptr;

    int32_t value = 0;
    for (int i = 0; i < 4; i++)
        value = (value << 8) | *at++;

    return std::make_shared<Int>(name, value);
}

std::shared_ptr<Long> nbt::parseLong(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Long)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 7)
        return nullptr;

    int64_t value = 0;
    for (int i = 0; i < 8; i++)
        value = (value << 8) | *at++;

    return std::make_shared<Long>(name, value);
}

std::shared_ptr<Float> nbt::parseFloat(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Float)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 3)
        return nullptr;

    union {
        float toReturn;
        uint32_t value;
    } val;
    val.value = 0;

    for (int i = 3; i >= 0; i--)
        val.value |= ((uint32_t) (*at++)) << (i * 8);

    return std::make_shared<Float>(name, val.toReturn);
}

std::shared_ptr<Double> nbt::parseDouble(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Double)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 7)
        return nullptr;

    union {
        double toReturn;
        uint64_t value;
    } val;
    val.value = 0;

    for (int i = 7; i >= 0; i--)
        val.value |= ((uint64_t) (*at++)) << (i * 8);

    return std::make_shared<Double>(name, val.toReturn);
}

std::shared_ptr<ByteArray> nbt::parseByteArray(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::ByteArray)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 3)
        return nullptr;

    int32_t size = 0;
    for (int i = 0; i < 4; i++)
        size = (size << 8) | *at++;

    if (end - at < size - 1)
        return nullptr;

    std::vector<int8_t> data;
    data.reserve(size);
    for (int i = 0; i < size; i++) {
        int8_t val = *at++;
        data.push_back(val);
    }

    return std::make_shared<ByteArray>(name, data);
}

std::shared_ptr<String> nbt::parseString(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::String)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 1)
        return nullptr;

    uint16_t size = (*at << 8) | at[1];
    at += 2;

    if (end - at < size - 1)
        return nullptr;

    std::string data;
    for (int i = 0; i < size; i++) {
        char val = *at++;
        data.push_back(val);
    }

    return std::make_shared<String>(name, data);
}

std::shared_ptr<List> nbt::parseList(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::List)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (at > end)
        return nullptr;

    uint8_t type = *at++;

    if (end - at < 3)
        return nullptr;

    int32_t size = 0;
    for (int i = 0; i < 4; i++)
        size = (size << 8) | *at++;

    std::vector<std::shared_ptr<Base>> data;
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Base> val = nullptr;
        // AUGH
        switch (type) {
        case (uint8_t) TagType::Byte:
            val = parseByte(at, end, false, true);
            break;
        case (uint8_t) TagType::Short:
            val = parseShort(at, end, false, true);
            break;
        case (uint8_t) TagType::Int:
            val = parseInt(at, end, false, true);
            break;
        case (uint8_t) TagType::Long:
            val = parseLong(at, end, false, true);
            break;
        case (uint8_t) TagType::Float:
            val = parseFloat(at, end, false, true);
            break;
        case (uint8_t) TagType::Double:
            val = parseDouble(at, end, false, true);
            break;
        case (uint8_t) TagType::ByteArray:
            val = parseByteArray(at, end, false, true);
            break;
        case (uint8_t) TagType::String:
            val = parseString(at, end, false, true);
            break;
        case (uint8_t) TagType::List:
            val = parseList(at, end, false, true);
            break;
        case (uint8_t) TagType::Compound:
            val = parseCompound(at, end, false, true);
            break;
        case (uint8_t) TagType::IntArray:
            val = parseIntArray(at, end, false, true);
            break;
        case (uint8_t) TagType::LongArray:
            val = parseLongArray(at, end, false, true);
            break;
        default:
            return nullptr;
        }
        if (!val)
            return nullptr;
        data.emplace_back(std::move(val));
    }

    return std::make_shared<List>(name, std::move(data));
}

std::shared_ptr<Compound> nbt::parseCompound(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::Compound)
            return nullptr;

        at++;
    }
    GET_NAME()

    std::vector<std::shared_ptr<Base>> data;
    for (;;) {
        if (at > end)
            return nullptr;
        if (*at == (uint8_t) TagType::End) {
            at++;
            break;
        }
        std::shared_ptr<Base> val = parse(at, end);
        if (!val)
            return nullptr;
        data.emplace_back(std::move(val));
    }

    return std::make_shared<Compound>(name, std::move(data));
}

std::shared_ptr<IntArray> nbt::parseIntArray(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::IntArray)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 3)
        return nullptr;

    int32_t size = 0;
    for (int i = 0; i < 4; i++)
        size = (size << 8) | *at++;

    if (end - at < size * 4 - 1)
        return nullptr;

    std::vector<int32_t> data;
    for (int i = 0; i < size; i++) {
        int32_t val = 0;
        for (int y = 0; y < 4; y++)
            val = (val << 8) | *at++;
        data.push_back(val);
    }

    return std::make_shared<IntArray>(name, std::move(data));
}

std::shared_ptr<LongArray> nbt::parseLongArray(uint8_t *&at, const uint8_t *end, bool includeName, bool inList)
{
    if (at > end)
        return nullptr;

    if (!inList) {
        if (*at != (uint8_t) TagType::LongArray)
            return nullptr;

        at++;
    }
    GET_NAME()

    if (end - at < 3)
        return nullptr;

    int32_t size = 0;
    for (int i = 0; i < 4; i++)
        size = (size << 8) | *at++;

    if (end - at < size * 8 - 1)
        return nullptr;

    std::vector<int64_t> data;
    for (int i = 0; i < size; i++) {
        int64_t val = 0;
        for (int y = 0; y < 8; y++)
            val = (val << 8) | *at++;
        data.push_back(val);
    }

    return std::make_shared<LongArray>(name, std::move(data));
}

std::shared_ptr<Base> nbt::parse(uint8_t *&at, const uint8_t *end)
{
    if (at > end)
        return nullptr;

    uint8_t type = *at;
    switch (type) {
    case (uint8_t) TagType::Byte:
        return parseByte(at, end);
    case (uint8_t) TagType::Short:
        return parseShort(at, end);
    case (uint8_t) TagType::Int:
        return parseInt(at, end);
    case (uint8_t) TagType::Long:
        return parseLong(at, end);
    case (uint8_t) TagType::Float:
        return parseFloat(at, end);
    case (uint8_t) TagType::Double:
        return parseDouble(at, end);
    case (uint8_t) TagType::ByteArray:
        return parseByteArray(at, end);
    case (uint8_t) TagType::String:
        return parseString(at, end);
    case (uint8_t) TagType::List:
        return parseList(at, end);
    case (uint8_t) TagType::Compound:
        return parseCompound(at, end);
    case (uint8_t) TagType::IntArray:
        return parseIntArray(at, end);
    case (uint8_t) TagType::LongArray:
        return parseLongArray(at, end);
    default:
        return nullptr;
    }
}
