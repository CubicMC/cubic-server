#ifndef D3810A78_CAF6_41E0_8DD7_3868B560E694
#define D3810A78_CAF6_41E0_8DD7_3868B560E694

#include <cassert>
#include <cstdint>
#include <nbt.h>
#include <string>
#include <type_traits>
#include <vector>

namespace nnbt {

struct Tag {
    nbt_tag_t *data;

    static Tag fromRaw(nbt_tag_t *n) { return Tag {.data = n}; }

    template<typename T>
    Tag add(T &to_add, const char *name)
    {
        assert(data);
        assert(data->type == NBT_TYPE_COMPOUND || data->type == NBT_TYPE_LIST);

        nbt_tag_t *new_data = nullptr;

        if constexpr (std::is_same_v<T, int32_t>)
            nbt_new_tag_int(to_add);
        else if constexpr (std::is_same_v<T, int64_t>)
            nbt_new_tag_long(to_add);
        else if constexpr (std::is_same_v<T, int16_t>)
            nbt_new_tag_short(to_add);
        else if constexpr (std::is_same_v<T, int8_t>)
            nbt_new_tag_byte(to_add);
        else if constexpr (std::is_same_v<T, float>)
            nbt_new_tag_float(to_add);
        else if constexpr (std::is_same_v<T, double>)
            nbt_new_tag_double(to_add);
        else if constexpr (std::is_same_v<T, std::vector<int8_t>>)
            nbt_new_tag_byte_array(to_add.data(), to_add.size());
        else if constexpr (std::is_same_v<T, std::vector<int32_t>>)
            nbt_new_tag_int_array(to_add.data(), to_add.size());
        else if constexpr (std::is_same_v<T, std::vector<int64_t>>)
            nbt_new_tag_long_array(to_add.data(), to_add.size());
        else if constexpr (std::is_same_v<T, std::string>)
            nbt_new_tag_string(to_add.c_str(), to_add.size());
        else
            static_assert(
                !(std::is_same_v<T, std::string> || std::is_same_v<T, std::vector<int64_t>> || std::is_same_v<T, std::vector<int32_t>>, std::is_same_v<T, std::vector<int8_t>>,
                  std::is_same_v<T, double>, std::is_same_v<T, float>, std::is_same_v<T, int8_t>, std::is_same_v<T, int16_t>, std::is_same_v<T, int64_t>,
                  std::is_same_v<T, int32_t>)
            );

        if (name)
            nbt_set_tag_name(new_data, name, strlen(name));

        if (data->type == NBT_TYPE_COMPOUND)
            nbt_tag_compound_append(this->data, new_data);
        else if (data->type == NBT_TYPE_LIST)
            nbt_tag_list_append(this->data, new_data);
        return Tag {.data = new_data};
    };

    Tag addList(nbt_tag_type_t type, const char *name)
    {
        assert(data);
        assert(data->type == NBT_TYPE_COMPOUND || data->type == NBT_TYPE_LIST);

        nbt_tag_t *new_data = nbt_new_tag_list(type);
        if (name)
            nbt_set_tag_name(new_data, name, strlen(name));

        if (data->type == NBT_TYPE_COMPOUND)
            nbt_tag_compound_append(this->data, new_data);
        else if (data->type == NBT_TYPE_LIST)
            nbt_tag_list_append(this->data, new_data);
        return Tag {.data = new_data};
    }

    Tag addCompound(const char *name)
    {
        assert(data);
        assert(data->type == NBT_TYPE_COMPOUND || data->type == NBT_TYPE_LIST);

        nbt_tag_t *new_data = nbt_new_tag_compound();
        if (name)
            nbt_set_tag_name(new_data, name, strlen(name));

        if (data->type == NBT_TYPE_COMPOUND)
            nbt_tag_compound_append(this->data, new_data);
        else if (data->type == NBT_TYPE_LIST)
            nbt_tag_list_append(this->data, new_data);
        return Tag {.data = new_data};
    }

    void destroy()
    {
        if (data)
            nbt_free_tag(data);
        data = nullptr;
    }
};

}

#endif /* D3810A78_CAF6_41E0_8DD7_3868B560E694 */
