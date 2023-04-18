#ifndef CUBICSERVER_MATH_VECTOR2_HPP
#define CUBICSERVER_MATH_VECTOR2_HPP

#include <cmath>
#include <iostream>

template<typename T>
class Vector2 {
public:
    Vector2(T nx, T ny) noexcept:
        x(nx),
        y(ny)
    {
    }
    Vector2() noexcept = default;
    ~Vector2() noexcept = default;

    T distance(const Vector2 &other) const { return std::sqrt(std::pow((other.x - this->x), 2) + std::pow((other.y - this->y), 2)); }

    T magnitude() const { return std::sqrt(this->x * this->x + this->y * this->y); }

    Vector2 normalized() const noexcept
    {
        T mag = this->magnitude();
        return Vector2(this->x / mag, this->y / mag);
    }

    void normalize() noexcept
    {
        T mag = this->magnitude();

        this->x /= mag;
        this->y /= mag;
    }

    T dotProduct(const Vector2 &other) noexcept { return this->x * other.x + this->y * other.y; }

    Vector2 operator+(const Vector2 &other) noexcept { return Vector2<T>(other.x + this->x, other.y + this->y); }

    Vector2 operator+(const T &other) noexcept { return Vector2<T>(other + this->x, other + this->y); }

    Vector2 operator+=(const Vector2 &other) noexcept
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    Vector2 operator+=(const T &other) noexcept
    {
        this->x += other;
        this->y += other;

        return *this;
    }

    Vector2 operator-(const Vector2 &other) noexcept { return Vector2<T>(other.x - this->x, other.y - this->y); }

    Vector2 operator-(const T &other) noexcept { return Vector2<T>(other - this->x, other - this->y); }

    Vector2 operator-=(const Vector2 &other) noexcept
    {
        this->x -= other.x;
        this->y -= other.y;

        return *this;
    }

    Vector2 operator-=(const T &other) noexcept
    {
        this->x -= other;
        this->y -= other;

        return *this;
    }

    Vector2 operator*(const Vector2 &other) noexcept { return Vector2<T>(other.x * this->x, other.y * this->y); }

    Vector2 operator*(const T &other) noexcept { return Vector2<T>(other * this->x, other * this->y); }

    Vector2 operator*=(const Vector2 &other) noexcept
    {
        this->x *= other.x;
        this->y *= other.y;

        return *this;
    }

    Vector2 operator*=(const T &other) noexcept
    {
        this->x *= other;
        this->y *= other;

        return *this;
    }

    Vector2 operator/(const Vector2 &other) noexcept { return Vector2<T>(other.x / this->x, other.y / this->y); }

    Vector2 operator/(const T &other) noexcept { return Vector2<T>(other / this->x, other / this->y); }

    Vector2 operator/=(const Vector2 &other) noexcept
    {
        this->x /= other.x;
        this->y /= other.y;

        return *this;
    }

    Vector2 operator/=(const T &other) noexcept
    {
        this->x /= other;
        this->y /= other;

        return *this;
    }

    Vector2 operator%(const Vector2 &other) noexcept { return Vector2<T>(other.x % this->x, other.y % this->y, other.z % this->z); }

    Vector2 operator%(const T &other) noexcept { return Vector2<T>(other % this->x, other % this->y); }

    Vector2 operator%=(const Vector2 &other) noexcept
    {
        this->x %= other.x;
        this->y %= other.y;

        return *this;
    }

    Vector2 operator%=(const T &other) noexcept
    {
        this->x %= other;
        this->y %= other;

        return *this;
    }

    Vector2 &operator=(const Vector2 &other) noexcept
    {
        this->x = other.x;
        this->y = other.y;

        return *this;
    }

    Vector2 &operator=(const T &other) noexcept
    {
        this->x = other;
        this->y = other;

        return *this;
    }

    bool operator==(const Vector2 &other) const noexcept { return this->x == other.x && this->y == other.y; }

    bool operator==(const T &other) noexcept { return this->x == other && this->y == other; }

    bool operator!=(const Vector2 &other) noexcept { return this->x != other.x || this->y != other.y; }

    bool operator!=(const T &other) noexcept { return this->x != other || this->y != other; }

    T x;
    T y;
};

template<typename T>
std::ostream &operator<<(std::ostream &o, const Vector2<T> &v)
{
    o << "x : " << v.x << " | "
      << "y : " << v.y;
    return o;
}

#endif // CUBICSERVER_MATH_VECTOR2_HPP
