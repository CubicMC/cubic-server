#ifndef CUBICSERVER_MATH_VECTOR2_HPP
#define CUBICSERVER_MATH_VECTOR2_HPP

#include "math/Vector3.hpp"
#include <cmath>
#include <iostream>

template<typename T>
class Vector2 {
public:
    constexpr Vector2(T nx, T nz) noexcept:
        x(nx),
        z(nz)
    {
    }
    constexpr Vector2(const Vector2<T> &other) noexcept:
        x(other.x),
        z(other.z)
    {
    }
    constexpr Vector2(const Vector3<T> &other) noexcept:
        x(other.x),
        z(other.z)
    {
    }
    constexpr Vector2() noexcept = default;
    constexpr ~Vector2() noexcept = default;

    constexpr T distance(const Vector2 &other) const { return std::sqrt(std::pow((other.x - this->x), 2) + std::pow((other.z - this->z), 2)); }

    constexpr T magnitude() const { return std::sqrt(this->x * this->x + this->z * this->z); }

    constexpr Vector2 normalized() const noexcept
    {
        T mag = this->magnitude();
        return Vector2(this->x / mag, this->z / mag);
    }

    constexpr void normalize() noexcept
    {
        T mag = this->magnitude();

        this->x /= mag;
        this->z /= mag;
    }

    constexpr T dotProduct(const Vector2 &other) noexcept { return this->x * other.x + this->z * other.z; }

    constexpr Vector2 operator+(const Vector2 &other) noexcept { return Vector2<T>(other.x + this->x, other.z + this->z); }

    constexpr Vector2 operator+(const T &other) noexcept { return Vector2<T>(other + this->x, other + this->z); }

    constexpr Vector2 operator+=(const Vector2 &other) noexcept
    {
        this->x += other.x;
        this->z += other.z;

        return *this;
    }

    constexpr Vector2 operator+=(const T &other) noexcept
    {
        this->x += other;
        this->z += other;

        return *this;
    }

    constexpr Vector2 operator-(const Vector2 &other) noexcept { return Vector2<T>(other.x - this->x, other.z - this->z); }

    constexpr Vector2 operator-(const T &other) noexcept { return Vector2<T>(other - this->x, other - this->z); }

    constexpr Vector2 operator-=(const Vector2 &other) noexcept
    {
        this->x -= other.x;
        this->z -= other.z;

        return *this;
    }

    constexpr Vector2 operator-=(const T &other) noexcept
    {
        this->x -= other;
        this->z -= other;

        return *this;
    }

    constexpr Vector2 operator*(const Vector2 &other) noexcept { return Vector2<T>(other.x * this->x, other.z * this->z); }

    constexpr Vector2 operator*(const T &other) noexcept { return Vector2<T>(other * this->x, other * this->z); }

    constexpr Vector2 operator*=(const Vector2 &other) noexcept
    {
        this->x *= other.x;
        this->z *= other.z;

        return *this;
    }

    constexpr Vector2 operator*=(const T &other) noexcept
    {
        this->x *= other;
        this->z *= other;

        return *this;
    }

    constexpr Vector2 operator/(const Vector2 &other) noexcept { return Vector2<T>(other.x / this->x, other.z / this->z); }

    constexpr Vector2 operator/(const T &other) noexcept { return Vector2<T>(other / this->x, other / this->z); }

    constexpr Vector2 operator/=(const Vector2 &other) noexcept
    {
        this->x /= other.x;
        this->z /= other.z;

        return *this;
    }

    constexpr Vector2 operator/=(const T &other) noexcept
    {
        this->x /= other;
        this->z /= other;

        return *this;
    }

    constexpr Vector2 operator%(const Vector2 &other) noexcept { return Vector2<T>(other.x % this->x, other.z % this->y, other.z % this->z); }

    constexpr Vector2 operator%(const T &other) noexcept { return Vector2<T>(other % this->x, other % this->z); }

    constexpr Vector2 operator%=(const Vector2 &other) noexcept
    {
        this->x %= other.x;
        this->z %= other.z;

        return *this;
    }

    constexpr Vector2 operator%=(const T &other) noexcept
    {
        this->x %= other;
        this->z %= other;

        return *this;
    }

    constexpr Vector2 &operator=(const Vector2 &other) noexcept
    {
        this->x = other.x;
        this->z = other.z;

        return *this;
    }

    constexpr Vector2 &operator=(const T &other) noexcept
    {
        this->x = other;
        this->z = other;

        return *this;
    }

    constexpr bool operator==(const Vector2 &other) const noexcept { return this->x == other.x && this->z == other.z; }

    constexpr bool operator==(const T &other) noexcept { return this->x == other && this->z == other; }

    constexpr bool operator!=(const Vector2 &other) noexcept { return this->x != other.x || this->z != other.z; }

    constexpr bool operator!=(const T &other) noexcept { return this->x != other || this->z != other; }

    T x;
    T z;
};

template<typename T>
constexpr std::ostream &operator<<(std::ostream &o, const Vector2<T> &v)
{
    o << "x : " << v.x << " | "
      << "z : " << v.z;
    return o;
}

#endif // CUBICSERVER_MATH_VECTOR2_HPP
