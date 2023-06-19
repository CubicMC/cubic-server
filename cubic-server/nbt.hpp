#ifndef CUBICSERVER_NBT_HPP
#define CUBICSERVER_NBT_HPP

#include "concept.hpp"
#include "exceptions.hpp"
#include "options.hpp"
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace nbt {

DEFINE_EXCEPTION(TypeMismatch);
DEFINE_EXCEPTION(BufferEOF);
DEFINE_EXCEPTION(UnknownType);

enum class TagType {
    End,
    Byte,
    Short,
    Int,
    Long,
    Float,
    Double,
    ByteArray,
    String,
    List,
    Compound,
    IntArray,
    LongArray
};

class Base : public std::enable_shared_from_this<Base> {
public:
    static constexpr auto type = TagType::End;

public:
    constexpr Base(std::string name, TagType type):
        _name(std::move(name)),
        _type(type) {};
    constexpr Base(const char name[], TagType type):
        _name(name),
        _type(type) {};
    virtual ~Base() { }

    NODISCARD constexpr const std::string &getName() const { return _name; };

    NODISCARD constexpr TagType getType() const { return _type; }

    template<isBaseOf<Base> T>
    NODISCARD constexpr std::shared_ptr<T> as()
    {
        if (T::type != _type)
            throw TypeMismatch("Type mismatch");
        return std::dynamic_pointer_cast<T>(shared_from_this());
    }

    template<isBaseOf<Base> T>
    NODISCARD constexpr std::shared_ptr<const T> as() const
    {
        if (T::type != _type)
            throw TypeMismatch("Type mismatch");
        return std::dynamic_pointer_cast<T>(shared_from_this());
    }

    NODISCARD constexpr virtual std::vector<uint8_t> serialize() const
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr virtual void serialize(std::vector<uint8_t> &data, bool includeName = true) const = 0;

    constexpr virtual void preSerialize(std::vector<uint8_t> &data, bool includeName) const
    {
        if (!includeName)
            return;
        // Serialize the type
        data.push_back((uint8_t) _type);
        // Serialize the name length
        data.push_back(_name.length() >> 8);
        data.push_back(_name.length() & 0xFF);
        // Serialize the name
        for (const auto &i : _name)
            data.push_back(i);
    }

protected:
    const std::string _name;
    const TagType _type;
};

class Int : public Base {
public:
    static constexpr auto type = TagType::Int;

public:
    explicit constexpr Int(const std::string &name, int32_t value = 0):
        Base(name, TagType::Int),
        _value(value) {};
    ~Int() override = default;

    NODISCARD constexpr int32_t getValue() const { return _value; }

    constexpr void setValue(int32_t value) { _value = value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        for (int i = 0; i < 4; i++)
            data.push_back((_value >> (24 - i * 8)) & 0xFF);
    }

private:
    int32_t _value;
};

class Byte : public Base {
public:
    static constexpr auto type = TagType::Byte;

public:
    explicit constexpr Byte(std::string name, int8_t value = 0):
        Base(std::move(name), TagType::Byte),
        _value(value) {};
    ~Byte() override = default;

    NODISCARD constexpr int8_t getValue() const { return _value; }

    constexpr void setValue(int8_t value) { _value = value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        data.push_back(_value);
    }

private:
    int8_t _value;
};

class ByteArray : public Base {
public:
    static constexpr auto type = TagType::ByteArray;

public:
    explicit constexpr ByteArray(std::string name, std::vector<int8_t> value = std::vector<int8_t>()):
        Base(std::move(name), TagType::ByteArray),
        _value(std::move(value)) {};
    explicit constexpr ByteArray(std::string &&name, std::vector<int8_t> &&value = std::vector<int8_t>()):
        Base(std::move(name), TagType::ByteArray),
        _value(std::move(value)) {};
    ~ByteArray() override = default;

    NODISCARD constexpr std::vector<int8_t> &getValues() { return _value; }

    NODISCARD constexpr const std::vector<int8_t> &getValues() const { return _value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        // Serialize the length
        for (int i = 0; i < 4; i++)
            data.push_back((_value.size() >> (24 - i * 8)) & 0xFF);
        // Serialize the data
        for (auto i : _value)
            data.push_back(i);
    }

private:
    std::vector<int8_t> _value;
};

class Compound : public Base {
public:
    static constexpr auto type = TagType::Compound;

public:
    constexpr Compound(std::string name, std::vector<std::shared_ptr<Base>> &&value = std::vector<std::shared_ptr<Base>>()):
        Base(std::move(name), TagType::Compound),
        _value(std::move(value)) {};
    constexpr Compound(std::string name, std::vector<std::shared_ptr<Base>> &value):
        Base(std::move(name), TagType::Compound),
        _value(std::move(value)) {};
    constexpr Compound(std::string name, std::initializer_list<std::shared_ptr<Base>> value):
        Base(std::move(name), TagType::Compound),
        _value(value) {};
    constexpr Compound(const char *name, std::initializer_list<std::shared_ptr<Base>> value):
        Base(name, TagType::Compound),
        _value(value) {};
    ~Compound() override = default;

    inline void addValue(std::shared_ptr<Base> value) { _value.push_back(value); }

    constexpr size_t size() const { return _value.size(); }

    /**
     * @brief Checks if an NBT Tag exists
     *
     * @param str The name of the wanted NBT Tag
     * @return true The wanted NBT Tag exists in the Compound
     * @return false The wanted NBT Tag does not exist in the Compound
     */
    constexpr bool hasValue(const std::string &str) const
    {
        for (auto &&i : _value)
            if (i->getName() == str)
                return true;
        return false;
    }

    /**
     * @brief Get an NBT Tag from name
     *
     * @param str Name of the wanted NBT Tag
     * @return Base* The wanted NBT Tag (nullptr if not found)
     */
    inline std::shared_ptr<Base> getValue(const std::string &str)
    {
        for (auto &&i : _value)
            if (i->getName() == str)
                return i;
        return nullptr;
    }

    /**
     * @brief Get an NBT Tag from name
     *
     * @param str Name of the wanted NBT Tag
     * @return const Base* The wanted NBT Tag (nullptr if not found)
     */
    inline const std::shared_ptr<Base> getValue(const std::string &str) const
    {
        for (auto &&i : _value)
            if (i->getName() == str)
                return i;
        return nullptr;
    }

    template<isBaseOf<nbt::Base> T>
    constexpr std::shared_ptr<T> getValueAs(const std::string_view &str)
    {
        for (auto &&i : _value) {
            if (i->getName() != str)
                continue;
            if (i->getType() == T::type)
                return std::dynamic_pointer_cast<T>(i);
            throw TypeMismatch("Provided type does not match the type of the NBT Tag");
        }
        return nullptr;
    }

    constexpr std::vector<std::shared_ptr<Base>> &getValues() { return _value; }

    constexpr const std::vector<std::shared_ptr<Base>> &getValues() const { return _value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        // if (!includeName) {
        //     // Serialize the length of the list in 4 bytes
        //     for (int i = 0; i < 4; i++)
        //         data.push_back(((_value.size() + 1) >> (24 - i * 8)) & 0xFF);
        // }
        for (const auto &i : _value) {
            // i->serialize(data);
            i->serialize(data);
        }
        // Ends the TAG_Compound with a TAG_End
        data.push_back(0);
    }

private:
    std::vector<std::shared_ptr<Base>> _value;
};

class Double : public Base {
public:
    static constexpr auto type = TagType::Double;

public:
    explicit constexpr Double(std::string name, double value = 0):
        Base(std::move(name), TagType::Double),
        _value(value) {};
    ~Double() override = default;

    NODISCARD constexpr double getValue() const { return _value; }

    constexpr void setValue(double value) { _value = value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        union {
            double f;
            uint8_t u[8];
        } d;
        d.f = _value;
        for (int i = 7; i >= 0; i--)
            data.push_back(d.u[i]);
    }

private:
    double _value;
};

class Float : public Base {
public:
    static constexpr auto type = TagType::Float;

public:
    explicit constexpr Float(std::string name, float value = 0):
        Base(std::move(name), TagType::Float),
        _value(value) {};
    ~Float() override = default;

    NODISCARD constexpr float getValue() const { return _value; }

    constexpr void setValue(float value) { _value = value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        union {
            float f;
            uint8_t u[4];
        } d;
        d.f = _value;
        for (int i = 3; i >= 0; i--)
            data.push_back(d.u[i]);
    }

private:
    float _value;
};

class Long : public Base {
public:
    static constexpr auto type = TagType::Long;

public:
    explicit constexpr Long(std::string name, int64_t value = 0):
        Base(std::move(name), TagType::Long),
        _value(value) {};
    ~Long() override = default;

    NODISCARD constexpr int64_t getValue() const { return _value; }

    constexpr void setValue(int64_t value) { _value = value; }

    constexpr int64_t operator|(int64_t value) const { return _value | value; }

    constexpr void operator|=(int64_t value) { _value |= value; }

    constexpr void operator=(int64_t value) { this->setValue(value); }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        for (int i = 0; i < 8; i++)
            data.push_back((_value >> (56 - i * 8)) & 0xFF);
    }

private:
    int64_t _value;
};

class Short : public Base {
public:
    static constexpr auto type = TagType::Short;

public:
    explicit constexpr Short(std::string name, int16_t value = 0):
        Base(std::move(name), TagType::Short),
        _value(value) {};
    ~Short() override = default;

    NODISCARD constexpr int16_t getValue() const { return _value; }

    constexpr void setValue(int16_t value) { _value = value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        data.push_back(_value >> 8);
        data.push_back(_value & 0xFF);
    }

private:
    int16_t _value;
};

class String : public Base {
public:
    static constexpr auto type = TagType::String;

public:
    explicit constexpr String(std::string name, std::string value = ""):
        Base(std::move(name), TagType::String),
        _value(std::move(value)) {};

    ~String() override = default;

    NODISCARD constexpr const std::string &getValue() const { return _value; }

    constexpr void setValue(std::string value) { _value = std::move(value); }

    constexpr void setValue(std::string &&value) { _value = std::move(value); }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        // Serialize the length of the string
        data.push_back(_value.length() >> 8);
        data.push_back(_value.length() & 0xFF);
        // Serialize the string
        for (auto i : _value) {
            data.push_back(i);
        }
    }

private:
    std::string _value;
};

class IntArray : public Base {
public:
    static constexpr auto type = TagType::IntArray;

public:
    explicit constexpr IntArray(std::string name, std::vector<int32_t> value = std::vector<int32_t>()):
        Base(std::move(name), TagType::IntArray),
        _value(std::move(value)) {};
    ~IntArray() override = default;

    NODISCARD constexpr std::vector<int32_t> &getValues() { return _value; }

    NODISCARD constexpr const std::vector<int32_t> &getValues() const { return _value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        // Serialize the length of the data
        for (int i = 0; i < 4; i++)
            data.push_back((_value.size() >> (24 - i * 8)) & 0xFF);
        // Serialize the ints
        for (auto d : _value) {
            for (int i = 0; i < 4; i++)
                data.push_back((d >> (24 - i * 8)) & 0xFF);
        }
    }

private:
    std::vector<int32_t> _value;
};

class LongArray : public Base {
public:
    static constexpr auto type = TagType::LongArray;

public:
    explicit constexpr LongArray(std::string name, std::vector<int64_t> value = std::vector<int64_t>()):
        Base(std::move(name), TagType::LongArray),
        _value(std::move(value)) {};
    ~LongArray() override = default;

    NODISCARD constexpr std::vector<int64_t> &getValues() { return _value; }

    NODISCARD constexpr const std::vector<int64_t> &getValues() const { return _value; }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        // Serialize the length of the data
        for (int i = 0; i < 4; i++)
            data.push_back((_value.size() >> (24 - i * 8)) & 0xFF);
        // Serialize the longs
        for (auto d : _value) {
            for (int i = 0; i < 8; i++)
                data.push_back((d >> (56 - i * 8)) & 0xFF);
        }
    }

private:
    std::vector<int64_t> _value;
};

class List : public Base {
public:
    static constexpr auto type = TagType::List;

public:
    explicit constexpr List(std::string name, std::vector<std::shared_ptr<Base>> &&value = std::vector<std::shared_ptr<Base>>()):
        Base(std::move(name), TagType::List),
        _value(std::move(value)) {};
    explicit constexpr List(std::string name, std::vector<std::shared_ptr<Base>> &value):
        Base(std::move(name), TagType::List),
        _value(value) {};
    explicit constexpr List(std::string name, std::initializer_list<std::shared_ptr<Base>> value):
        Base(std::move(name), TagType::List),
        _value(value) {};
    ~List() override = default;

    NODISCARD constexpr std::vector<std::shared_ptr<Base>> &getValues() noexcept { return _value; }

    NODISCARD constexpr const std::vector<std::shared_ptr<Base>> &getValues() const noexcept { return _value; }

    inline void push_back(std::shared_ptr<Base> value) { _value.push_back(value); }

    NODISCARD constexpr size_t size() const noexcept { return _value.size(); }

    NODISCARD constexpr std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    template<isBaseOf<nbt::Base> T>
    constexpr std::shared_ptr<T> getValueAs(size_t index) const
    {
        if (index >= _value.size())
            throw std::out_of_range("nbt::List index out of range");
        if (_value[index]->getType() != T::type)
            throw TypeMismatch("nbt::List contains a different type");
        return std::dynamic_pointer_cast<T>(_value[index]);
    }

    void serialize(std::vector<uint8_t> &data, bool includeName = true) const override
    {
        Base::preSerialize(data, includeName);
        TagType current = TagType::End;
        // serialize the type of the first componant of the list
        if (_value.size() == 0) {
            data.push_back((uint8_t) TagType::End);
            return;
        }
        data.push_back((uint8_t) _value[0]->getType());

        // Serialize the length of the data as int32
        for (int i = 0; i < 4; i++)
            data.push_back((_value.size() >> (24 - i * 8)) & 0xFF);
        // Serialize the nbt
        for (const auto &i : _value) {
            if (current == TagType::End)
                current = i->getType();
            if (current != i->getType())
                throw TypeMismatch("nbt::List contains more than one type");
            // i->serialize(data, false);
            i->serialize(data, false);
        }
    }

private:
    std::vector<std::shared_ptr<Base>> _value;
};

#define NBT_MAKE(nbt_type, ...) std::shared_ptr<nbt::Base>(new nbt_type(__VA_ARGS__))
#define NBT_MAKE_AS(nbt_type, ...) NBT_MAKE(nbt_type, __VA_ARGS__)->as<nbt_type>()

std::shared_ptr<Byte> parseByte(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<Short> parseShort(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<Int> parseInt(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<Long> parseLong(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<Float> parseFloat(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<Double> parseDouble(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<ByteArray> parseByteArray(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<String> parseString(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<List> parseList(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<Compound> parseCompound(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<IntArray> parseIntArray(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);
std::shared_ptr<LongArray> parseLongArray(uint8_t *&at, const uint8_t *end, bool includeName = true, bool inList = false);

std::shared_ptr<Base> parse(uint8_t *&at, const uint8_t *end);

}

#endif // CUBICSERVER_NBT_HPP
