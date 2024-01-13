#ifndef CUBICSERVER_MATH_VECTOR3_HPP
#define CUBICSERVER_MATH_VECTOR3_HPP

// #include "types.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>

struct Position;

template<typename T>
class Vector3 {
public:
    constexpr Vector3(T nx, T ny, T nz) noexcept:
        x(nx),
        y(ny),
        z(nz)
    {
    }
    constexpr Vector3(const Vector3<T> &obj) noexcept:
        x(obj.x),
        y(obj.y),
        z(obj.z)
    {
    }
    constexpr Vector3() noexcept = default;
    constexpr ~Vector3() noexcept = default;

    constexpr T distance(const Vector3 &other) const { return std::sqrt(std::pow((other.x - this->x), 2) + std::pow((other.y - this->y), 2) + std::pow((other.z - this->z), 2)); }

    constexpr T magnitude() const { return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z); }

    constexpr Vector3 normalized() const noexcept
    {
        T mag = this->magnitude();
        return Vector3(this->x / mag, this->y / mag, this->z / mag);
    }

    constexpr void normalize() noexcept
    {
        T mag = this->magnitude();

        this->x /= mag;
        this->y /= mag;
        this->z /= mag;
    }

    constexpr T dotProduct(const Vector3 &other) noexcept { return this->x * other.x + this->y * other.y + this->z * other.z; }

    constexpr Vector3 operator+(const Vector3 &other) const noexcept { return Vector3<T>(other.x + this->x, other.y + this->y, other.z + this->z); }

    constexpr Vector3 operator+(const T &other) const noexcept { return Vector3<T>(other + this->x, other + this->y, other + this->z); }

    constexpr Vector3 operator+=(const Vector3 &other) noexcept
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;

        return *this;
    }

    constexpr Vector3 operator+=(const T &other) noexcept
    {
        this->x += other;
        this->y += other;
        this->z += other;

        return *this;
    }

    constexpr Vector3 operator-(const Vector3 &other) const noexcept { return Vector3<T>(other.x - this->x, other.y - this->y, other.z - this->z); }

    constexpr Vector3 operator-(const T &other) const noexcept { return Vector3<T>(other - this->x, other - this->y, other - this->z); }

    constexpr Vector3 operator-=(const Vector3 &other) noexcept
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;

        return *this;
    }

    constexpr Vector3 operator-=(const T &other) noexcept
    {
        this->x -= other;
        this->y -= other;
        this->z -= other;

        return *this;
    }

    constexpr Vector3 operator*(const Vector3 &other) const noexcept { return Vector3<T>(other.x * this->x, other.y * this->y, other.z * this->z); }

    constexpr Vector3 operator*(const T &other) const noexcept { return Vector3<T>(other * this->x, other * this->y, other * this->z); }

    constexpr Vector3 operator*=(const Vector3 &other) noexcept
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;

        return *this;
    }

    constexpr Vector3 operator*=(const T &other) noexcept
    {
        this->x *= other;
        this->y *= other;
        this->z *= other;

        return *this;
    }

    constexpr Vector3 operator/(const Vector3 &other) const noexcept { return Vector3<T>(other.x / this->x, other.y / this->y, other.z / this->z); }

    constexpr Vector3 operator/(const T &other) const noexcept { return Vector3<T>(other / this->x, other / this->y, other / this->z); }

    constexpr Vector3 operator/=(const Vector3 &other) noexcept
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;

        return *this;
    }

    constexpr Vector3 operator/=(const T &other) noexcept
    {
        this->x /= other;
        this->y /= other;
        this->z /= other;

        return *this;
    }

    constexpr Vector3 operator%(const Vector3 &other) const noexcept { return Vector3<T>(other.x % this->x, other.y % this->y, other.z % this->z); }

    constexpr Vector3 operator%(const T &other) const noexcept { return Vector3<T>(other % this->x, other % this->y, other % this->z); }

    constexpr Vector3 operator%=(const Vector3 &other) noexcept
    {
        this->x %= other.x;
        this->y %= other.y;
        this->z %= other.z;

        return *this;
    }

    constexpr Vector3 operator%=(const T &other) noexcept
    {
        this->x %= other;
        this->y %= other;
        this->z %= other;

        return *this;
    }

    constexpr Vector3 &operator=(const Vector3 &other) noexcept
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;

        return *this;
    }

    constexpr Vector3 &operator=(const T &other) noexcept
    {
        this->x = other;
        this->y = other;
        this->z = other;

        return *this;
    }

    constexpr bool operator==(const Vector3 &other) const noexcept { return this->x == other.x && this->y == other.y && this->z == other.z; }

    constexpr bool operator==(const T &other) const noexcept { return this->x == other && this->y == other && this->z == other; }

    constexpr bool operator!=(const Vector3 &other) const noexcept { return this->x != other.x || this->y != other.y || this->z != other.z; }

    constexpr bool operator!=(const T &other) const noexcept { return this->x != other || this->y != other || this->z != other; }

    T x;
    T y;
    T z;

    /**
     * @brief Convert a Vector3 to a Position
     *
     * @return Position
     */
    operator Position() const noexcept;
    operator Position() noexcept;
};

template<>
Vector3<double>::operator Position() const noexcept;

template<>
Vector3<double>::operator Position() noexcept;

template<typename T>
std::ostream &operator<<(std::ostream &o, const Vector3<T> &v)
{
    o << "x : " << v.x << " | "
      << "y : " << v.y << " | "
      << "z : " << v.z;
    return o;
}

#endif // CUBICSERVER_MATH_VECTOR3_HPP
