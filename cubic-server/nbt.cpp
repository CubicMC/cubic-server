//
// Created by toma- on 16/12/2022.
//

#include <unistd.h>

#include "nbt.hpp"

using namespace nbt;

ssize_t write(int fd, const Int &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Int;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const int32_t &value = buf.get_value();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 4);

    return count;
}

ssize_t write(int fd, const Byte &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Byte;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const int8_t &value = buf.get_value();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 1);

    return count;
}

ssize_t write(int fd, const ByteArray &buf)
{
    ssize_t count = 0;
    const TagType tag_array = TagType::ByteArray;
    const TagType tag_element = TagType::Byte;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const std::vector<int8_t> &array = buf.get_values_const();
    const int32_t &array_length = array.size();

    count += write(fd, &tag_array, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &array_length, 4);

    for (int i = 0; i < array_length; ++i) {
        count += write(fd, &tag_element, 1);
        count += write(fd, &array[i], 1);
    };

    return count;
}

/*
ssize_t write(int fd, const Compound &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Compound;
    const char *name = buf.get_name().c_str();
    const unsigned short &name_length = buf.get_name().length();
//    const FastMap<std::string, Base> &values = buf.get_values();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 1);

    return count;
}*/

ssize_t write(int fd, const Double &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Double;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const uint64_t &value = buf.get_value();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 8);

    return count;
}

ssize_t write(int fd, const Float &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Float;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const uint32_t &value = buf.get_value();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 4);

    return count;
}

ssize_t write(int fd, Long const &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Long;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const uint64_t &value = buf.get_value();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 8);

    return count;
}

ssize_t write(int fd, const Short &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::Short;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const int16_t &value = buf.get_value();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value, 2);

    return count;
}

ssize_t write(int fd, const String &buf)
{
    ssize_t count = 0;
    const TagType tag = TagType::String;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const char *value = buf.get_value().c_str();
    const uint16_t &value_length = buf.get_value().length();

    count += write(fd, &tag, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &value_length, 2);
    count += write(fd, value, value_length);

    return count;
}

ssize_t write(int fd, const IntArray &buf)
{
    ssize_t count = 0;
    const TagType tag_array = TagType::IntArray;
    const TagType tag_element = TagType::Int;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const std::vector<int32_t> &array = buf.get_values_const();
    const int32_t &array_length = array.size();

    count += write(fd, &tag_array, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &array_length, 4);

    for (int i = 0; i < array_length; ++i) {
        count += write(fd, &tag_element, 1);
        count += write(fd, &array[i], 4);
    };

    return count;
}

ssize_t write(int fd, const LongArray &buf) {
    ssize_t count = 0;
    const TagType tag_array = TagType::LongArray;
    const TagType tag_element = TagType::Long;
    const char *name = buf.get_name().c_str();
    const uint16_t &name_length = buf.get_name().length();
    const std::vector<int64_t> &array = buf.get_values_const();
    const int32_t &array_length = array.size();

    count += write(fd, &tag_array, 1);
    count += write(fd, &name_length, 2);
    count += write(fd, name, name_length);
    count += write(fd, &array_length, 4);

    for (int i = 0; i < array_length; ++i) {
        count += write(fd, &tag_element, 1);
        count += write(fd, &array[i], 8);
    };

    return count;
}