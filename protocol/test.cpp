#include "ClientPackets.hpp"
#include "ServerPackets.hpp"
#include "PacketUtils.hpp"
#include <variant>
#include <map>

enum class TagType : uint8_t {
    TAG_END = 0x00,
    TAG_BYTE = 0x01,
    TAG_SHORT = 0x02,
    TAG_INT = 0x03,
    TAG_LONG = 0x04,
    TAG_FLOAT = 0x05,
    TAG_DOUBLE = 0x06,
    TAG_BYTE_ARRAY = 0x07,
    TAG_STRING = 0x08,
    TAG_LIST = 0x09,
    TAG_COMPOUND = 0x0A,
    TAG_INT_ARRAY = 0x0B,
    TAG_LONG_ARRAY = 0x0C,
};

typedef std::nullptr_t TagEnd;
typedef int8_t TagByte;
typedef int16_t TagShort;
typedef int32_t TagInt;
typedef int64_t TagLong;
typedef float TagFloat;
typedef double TagDouble;
typedef std::vector<TagByte> TagByteArray;
typedef std::string TagString;

typedef std::map<TagString, Tag> TagCompound;
typedef std::vector<TagInt> TagIntArray;
typedef std::vector<TagLong> TagLongArray;

class Tag : public std::variant<TagEnd, TagByte, TagShort, TagInt, TagLong, TagFloat, TagDouble, TagByteArray, TagString, TagList, TagCompound, TagIntArray, TagLongArray> {
public:
    Tag(std::vector<uint8_t> &buffer);
    void serialize(std::vector<uint8_t> &buffer);
    void deserialize(uint8_t *at, uint8_t *eof, TagType type);
private:
    template <typename T>
    Tag &operator=(T other);
};

Tag::Tag(std::vector<uint8_t> &buffer)
{
    uint8_t *at = buffer.data();
    uint8_t *eof = buffer.data() + buffer.size() - 1;
    TagType type = (TagType)protocol::popByte(at, eof);
    this->deserialize(at, eof, type);
}

constexpr void Tag::deserialize(uint8_t *at, uint8_t *eof, TagType type) {
    switch (type) {
        case TagType::TAG_END:
            *this = TagEnd();
            break;
        case TagType::TAG_BYTE:
            *this = decode<TagByte>(protocol::popByte(at, eof));
            break;
        case TagType::TAG_SHORT:
            this->emplace<TagShort>(protocol::popUnsignedShort(at, eof));
            break;
        case TagType::TAG_INT:
            this->emplace<TagInt>(protocol::popInt(at, eof));
            break;
        case TagType::TAG_LONG:
            this->emplace<TagLong>(protocol::popLong(at, eof));
            break;
        case TagType::TAG_FLOAT:
            this->emplace<TagFloat>(protocol::popFloat(at, eof));
            break;
        case TagType::TAG_DOUBLE:
            this->emplace<TagDouble>(protocol::popDouble(at, eof));
            break;
        case TagType::TAG_BYTE_ARRAY:
            this->emplace<TagByteArray>(protocol::popByteArray(protocol::popInt(at, eof), at, eof));
            break;
        case TagType::TAG_STRING:
            this->emplace<TagString>(protocol::popString(at, eof));
            break;
        case TagType::TAG_LIST:
            this->emplace<TagList>(readList(buffer));
            break;
        case TagType::TAG_COMPOUND:
            this->emplace<TagCompound>(readCompound(buffer));
            break;
        case TagType::TAG_INT_ARRAY:
            this->emplace<TagIntArray>(readIntArray(buffer));
            break;
        case TagType::TAG_LONG_ARRAY:
            this->emplace<TagLongArray>(readLongArray(buffer));
            break;
        default:
            throw std::runtime_error("Invalid tag type");
    }
}

class TagList : public std::variant<std::vector<TagEnd>, std::vector<TagByte>, std::vector<TagShort>, std::vector<TagInt>, std::vector<TagLong>, std::vector<TagFloat>, std::vector<TagDouble>, std::vector<TagString>, std::vector<TagByteArray>, std::vector<TagIntArray>, std::vector<TagLongArray>, std::vector<TagList>, std::vector<TagCompound>> {

};

template <typename T> T decode(std::vector<uint8_t> &buffer) {
    return T(buffer);
}