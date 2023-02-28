#ifndef A00E5759_8505_49C7_A2FA_F904C5D1B881
#define A00E5759_8505_49C7_A2FA_F904C5D1B881

#include <cstdint>
#include <string>
#include <sstream>

#include "nbt.hpp"

struct u128 {
    uint64_t most;
    uint64_t least;
};

typedef int64_t Seed;

typedef uint16_t GlobalBlockId;
typedef uint8_t GlobalBiomeId;

// https://wiki.vg/Data_types#Fixed-point_numbers
// https://wiki.vg/index.php?title=Protocol&oldid=17753#Custom_Sound_Effect
// https://wiki.vg/index.php?title=Protocol&oldid=17753#Sound_Effect
// I think I should move this outside the protocol, but where ? '-'
struct FloatingPosition
{
    double x;
    double z;
    double y;
};

struct Position
{
    typedef int64_t value_type;

    value_type x;
    value_type y;
    value_type z;

    constexpr Position operator*(value_type i) const;
    constexpr Position operator*(const Position &other) const;

    constexpr Position operator/(value_type i) const;
    constexpr Position operator/(const Position &other) const;

    constexpr Position operator%(value_type i) const;
    constexpr Position operator%(const Position &other) const;

    constexpr Position operator+(value_type i) const;
    constexpr Position operator+(const Position &other) const;

    constexpr Position operator-(const Position &other) const;
    constexpr Position operator-(value_type i) const;

    constexpr bool operator==(const Position &other) const;

    std::ostream &operator<<(std::ostream &os) const;
};

struct Position2D
{
    typedef int32_t value_type;

    constexpr Position2D() = default;
    constexpr Position2D(const value_type &x, const value_type &z):
        x(x),
        z(z)
    {}

    value_type x;
    value_type z;

    constexpr Position2D operator*(const value_type &i) const;
    constexpr Position2D operator*(const Position2D &other) const;

    constexpr Position2D operator/(const value_type &i) const;
    constexpr Position2D operator/(const Position2D &other) const;

    constexpr Position2D operator%(const value_type &i) const;
    constexpr Position2D operator%(const Position2D &other) const;

    constexpr Position2D operator+(const value_type &i) const;
    constexpr Position2D operator+(const Position2D &other) const;

    constexpr Position2D operator-(const Position2D &other) const;
    constexpr Position2D operator-(const value_type &i) const;

    constexpr bool operator==(const Position2D &other) const;

    std::ostream &operator<<(std::ostream &os) const;
};

struct Rotation
{
    float yaw;
    float pitch;
};

// Position
constexpr Position Position::operator*(value_type i) const
{
    return Position{x * i, y * i, z * i};
}
constexpr Position Position::operator*(const Position &other) const
{
    return Position{x * other.x, y * other.y, z * other.z};
}

constexpr Position Position::operator/(value_type i) const
{
    return Position{x / i, y / i, z / i};
}
constexpr Position Position::operator/(const Position &other) const
{
    return Position{x / other.x, y / other.y, z / other.z};
}

constexpr Position Position::operator%(value_type i) const
{
    return Position{x % i, y % i, z % i};
}
constexpr Position Position::operator%(const Position &other) const
{
    return Position{x % other.x, y % other.y, z % other.z};
}

constexpr Position Position::operator+(value_type i) const
{
    return Position{x + i, y + i, z + i};
}
constexpr Position Position::operator+(const Position &other) const
{
    return Position{x + other.x, y + other.y, z + other.z};
}

constexpr Position Position::operator-(const Position &other) const
{
    return Position{x - other.x, y - other.y, z - other.z};
}
constexpr Position Position::operator-(value_type i) const
{
    return Position{x - i, y - i, z - i};
}

constexpr bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

// Position2D

constexpr Position2D Position2D::operator*(const value_type &i) const
{
    return Position2D{x * i, z * i};
}

constexpr Position2D Position2D::operator*(const Position2D &other) const
{
    return Position2D{x * other.x, z * other.z};
}


constexpr Position2D Position2D::operator/(const value_type &i) const
{
    return Position2D{x / i, z / i};
}

constexpr Position2D Position2D::operator/(const Position2D &other) const
{
    return Position2D{x / other.x, z / other.z};
}


constexpr Position2D Position2D::operator%(const value_type &i) const
{
    return Position2D{x % i, z % i};
}

constexpr Position2D Position2D::operator%(const Position2D &other) const
{
    return Position2D{x % other.x, z % other.z};
}


constexpr Position2D Position2D::operator+(const value_type &i) const
{
    return Position2D{x + i, z + i};
}

constexpr Position2D Position2D::operator+(const Position2D &other) const
{
    return Position2D{x + other.x, z + other.z};
}


constexpr Position2D Position2D::operator-(const Position2D &other) const
{
    return Position2D{x - other.x, z - other.z};
}

constexpr Position2D Position2D::operator-(const value_type &i) const
{
    return Position2D{x - i, z - i};
}


constexpr bool Position2D::operator==(const Position2D &other) const
{
    return x == other.x && z == other.z;
}

template<>
struct std::hash<Position2D>
{
    std::size_t operator()(Position2D const& pos) const noexcept
    {
        std::size_t h1 = std::hash<Position2D::value_type>{}(pos.x);
        std::size_t h2 = std::hash<Position2D::value_type>{}(pos.z);
        return h1 ^ (h2 << 1);
    }
};

#endif /* A00E5759_8505_49C7_A2FA_F904C5D1B881 */
