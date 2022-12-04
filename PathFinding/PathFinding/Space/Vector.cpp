#include "Vector.h"

Vector::Vector() {
    X = Y = Z = 0;
}

Vector::Vector(float scalar) {
    X = Y = Z = scalar;
}

Vector::Vector(float x, float y) {
    X = x;
    Y = y;
    Z = 0;
}

Vector::Vector(float x, float y, float z): Vector(x,y) {
    Z = z;
}

Vector::Vector(const Vector& copy) {
    X = copy.X;
    Y = copy.Y;
    Z = copy.Z;
}

Vector Vector::operator+(const Vector& rhs) const {
    return Vector(X + rhs.X,Y + rhs.Y,Z + rhs.Z);
}

Vector Vector::operator-(const Vector& rhs) const {
    return Vector(X - rhs.X,Y - rhs.Y,Z - rhs.Z);
}

Vector Vector::operator*(const Vector& rhs) const {
    return Vector(X * rhs.X,Y * rhs.Y,Z * rhs.Z);
}

Vector Vector::operator/(const Vector& rhs) const {
    return Vector(X / rhs.X,Y / rhs.Y,Z / rhs.Z);
}

Vector Vector::operator*(const float& rhs) const {
    return Vector(X * rhs,Y * rhs,Z * rhs);
}

Vector Vector::operator/(const float& rhs) const {
    return Vector(X / rhs,Y / rhs,Z / rhs);
}

float Vector::Distance(const Vector& v1, const Vector& v2) {
    return (v1 - v2).Length();
}

float Vector::Length() const {
    return std::sqrt(X*X + Y*Y + Z*Z);
}

Vector Vector::Normalized() const {
    return (*this) / Length();
}
