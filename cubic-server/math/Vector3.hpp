#ifndef CUBICSERVER_VECTOR3_H
#define CUBICSERVER_VECTOR3_H

#include <iostream>
#include <cmath>

template <typename T>
class Vector3
{
public:
    Vector3(T nx, T ny, T nz) noexcept : x(nx), y(ny), z(nz) {}
    Vector3() noexcept = default;
    ~Vector3() noexcept = default;

    T distance(const Vector3 &other) const
    {
        return std::sqrt(std::pow((other.x - this->x), 2) + std::pow((other.y - this->y), 2) + std::pow((other.z - this->z), 2));
    }

    T magnitude() const
    {
        return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    Vector3 normalized() const noexcept
    {
        T mag = this->magnitude();
        return Vector3(this->x / mag, this->y / mag, this->z / mag);
    }

    void normalize() noexcept
    {
        T mag = this->magnitude();

        this->x /= mag;
        this->y /= mag;
        this->z /= mag;
    }

    T dot_product(const Vector3 &other) noexcept
    {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }

    Vector3 operator+(const Vector3 &other) noexcept
    {
        return Vector3<T>(other.x + this->x, other.y + this->y, other.z + this->z);
    }

    Vector3 operator+=(const Vector3 &other) noexcept
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;

        return *this;
    }

    Vector3 operator-(const Vector3 &other) noexcept
    {
        return Vector3<T>(other.x - this->x, other.y - this->y, other.z - this->z);
    }

    Vector3 operator-=(const Vector3 &other) noexcept
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;

        return *this;
    }

    Vector3 operator*(const Vector3 &other) noexcept
    {
        return Vector3<T>(other.x * this->x, other.y * this->y, other.z * this->z);
    }

    Vector3 operator*=(const Vector3 &other) noexcept
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;

        return *this;
    }

    Vector3 operator/(const Vector3 &other) noexcept
    {
        return Vector3<T>(other.x / this->x, other.y / this->y, other.z / this->z);
    }

    Vector3 operator/=(const Vector3 &other) noexcept
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;

        return *this;
    }

    Vector3 operator%(const Vector3 &other) noexcept
    {
        return Vector3<T>(other.x % this->x, other.y % this->y, other.z % this->z);
    }

    Vector3 operator%=(const Vector3 &other) noexcept
    {
        this->x %= other.x;
        this->y %= other.y;
        this->z %= other.z;

        return *this;
    }

    Vector3 operator=(const Vector3 &other) noexcept
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;

        return *this;
    }

    bool operator==(const Vector3 &other) const noexcept
    {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }

    bool operator!=(const Vector3 &other) noexcept
    {
        return this->x != other.x || this->y != other.y || this->z != other.z;
    }

    T x;
    T y;
    T z;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Vector3<T> &v)
{
    o << "x : " << v.x << " | " << "y : " << v.y << " | " << "z : " << v.z;
    return o;
}

#endif //CUBICSERVER_VECTOR3_H
