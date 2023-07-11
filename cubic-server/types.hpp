#ifndef CUBICSERVER_TYPES_HPP
#define CUBICSERVER_TYPES_HPP

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

struct u128 {
    uint64_t most;
    uint64_t least;

    /**
     * @brief Returns a string version of the UUID
     *
     * @return std::string The string version of the UUID
     */
    std::string toString() const;

    /**
     * @brief Swaps the endianness of the current UUID
     *
     */
    void swapEndianness();

    static u128 fromShortString(const std::string &str);
};

typedef int64_t Seed;

typedef int32_t BlockId;
typedef uint8_t BiomeId;
typedef int32_t ItemId;

// https://wiki.vg/Data_types#Fixed-point_numbers
// https://wiki.vg/index.php?title=Protocol&oldid=17753#Custom_Sound_Effect
// https://wiki.vg/index.php?title=Protocol&oldid=17753#Sound_Effect
// I think I should move this outside the protocol, but where ? '-'
struct FloatingPosition {
    double x;
    double z;
    double y;
};

struct Position {
    typedef int64_t valueType;

    valueType x;
    valueType y;
    valueType z;

    constexpr Position operator*(valueType i) const;
    constexpr Position operator*(const Position &other) const;

    constexpr Position operator/(valueType i) const;
    constexpr Position operator/(const Position &other) const;

    constexpr Position operator%(valueType i) const;
    constexpr Position operator%(const Position &other) const;

    constexpr Position operator+(valueType i) const;
    constexpr Position operator+(const Position &other) const;

    constexpr Position operator-(const Position &other) const;
    constexpr Position operator-(valueType i) const;

    constexpr auto operator<=>(const Position &other) const = default;

    constexpr bool operator>(valueType i) const;
    constexpr bool operator<(valueType i) const;

    constexpr bool operator>=(valueType i) const;
    constexpr bool operator<=(valueType i) const;
};

struct Position2D {
    typedef int32_t valueType;

    constexpr Position2D() = default;
    constexpr Position2D(const valueType &x, const valueType &z):
        x(x),
        z(z)
    {
    }

    valueType x;
    valueType z;

    constexpr Position2D operator*(const valueType &i) const;
    constexpr Position2D operator*(const Position2D &other) const;

    constexpr Position2D operator/(const valueType &i) const;
    constexpr Position2D operator/(const Position2D &other) const;

    constexpr Position2D operator%(const valueType &i) const;
    constexpr Position2D operator%(const Position2D &other) const;

    constexpr Position2D operator+(const valueType &i) const;
    constexpr Position2D operator+(const Position2D &other) const;

    constexpr Position2D operator-(const Position2D &other) const;
    constexpr Position2D operator-(const valueType &i) const;

    constexpr auto operator<=>(const Position2D &other) const = default;

    constexpr bool operator>(valueType i) const;
    constexpr bool operator<(valueType i) const;

    constexpr bool operator>=(valueType i) const;
    constexpr bool operator<=(valueType i) const;
};

struct Rotation {
    float yaw;
    float pitch;
};

// Position
constexpr Position Position::operator*(valueType i) const { return Position {x * i, y * i, z * i}; }
constexpr Position Position::operator*(const Position &other) const { return Position {x * other.x, y * other.y, z * other.z}; }

constexpr Position Position::operator/(valueType i) const { return Position {x / i, y / i, z / i}; }
constexpr Position Position::operator/(const Position &other) const { return Position {x / other.x, y / other.y, z / other.z}; }

constexpr Position Position::operator%(valueType i) const { return Position {x % i, y % i, z % i}; }
constexpr Position Position::operator%(const Position &other) const { return Position {x % other.x, y % other.y, z % other.z}; }

constexpr Position Position::operator+(valueType i) const { return Position {x + i, y + i, z + i}; }
constexpr Position Position::operator+(const Position &other) const { return Position {x + other.x, y + other.y, z + other.z}; }

constexpr Position Position::operator-(const Position &other) const { return Position {x - other.x, y - other.y, z - other.z}; }
constexpr Position Position::operator-(valueType i) const { return Position {x - i, y - i, z - i}; }

constexpr bool Position::operator>(valueType i) const { return x > i && y > i && z > i; }
constexpr bool Position::operator<(valueType i) const { return x < i && y < i && z < i; }

constexpr bool Position::operator>=(valueType i) const { return x >= i && y >= i && z >= i; }
constexpr bool Position::operator<=(valueType i) const { return x <= i && y <= i && z <= i; }

// Position2D

constexpr Position2D Position2D::operator*(const valueType &i) const { return Position2D {x * i, z * i}; }

constexpr Position2D Position2D::operator*(const Position2D &other) const { return Position2D {x * other.x, z * other.z}; }

constexpr Position2D Position2D::operator/(const valueType &i) const { return Position2D {x / i, z / i}; }

constexpr Position2D Position2D::operator/(const Position2D &other) const { return Position2D {x / other.x, z / other.z}; }

constexpr Position2D Position2D::operator%(const valueType &i) const { return Position2D {x % i, z % i}; }

constexpr Position2D Position2D::operator%(const Position2D &other) const { return Position2D {x % other.x, z % other.z}; }

constexpr Position2D Position2D::operator+(const valueType &i) const { return Position2D {x + i, z + i}; }

constexpr Position2D Position2D::operator+(const Position2D &other) const { return Position2D {x + other.x, z + other.z}; }

constexpr Position2D Position2D::operator-(const Position2D &other) const { return Position2D {x - other.x, z - other.z}; }

constexpr Position2D Position2D::operator-(const valueType &i) const { return Position2D {x - i, z - i}; }

constexpr bool Position2D::operator>(valueType i) const { return x > i && z > i; }
constexpr bool Position2D::operator<(valueType i) const { return x < i && z < i; }

constexpr bool Position2D::operator>=(valueType i) const { return x >= i && z >= i; }
constexpr bool Position2D::operator<=(valueType i) const { return x <= i && z <= i; }

template<>
struct std::hash<Position2D> {
    std::size_t operator()(const Position2D &pos) const noexcept
    {
        std::size_t h1 = std::hash<Position2D::valueType> {}(pos.x);
        std::size_t h2 = std::hash<Position2D::valueType> {}(pos.z);
        return h1 ^ (h2 << 1);
    }
};

#endif // CUBICSERVER_TYPES_HPP
