#pragma once
#include <complex>


struct Vector {
    float X;
    float Y;
    float Z;

    // CONSTRUCTORS
	// ------------------------------------------------------
    Vector();

    Vector(float scalar);

    Vector(float x, float y);

    Vector(float x, float y, float z);

    Vector(const Vector& copy);

    // OPERATORS
	// ------------------------------------------------------
	// Vector
    Vector operator+(const Vector& rhs) const;

    Vector operator-(const Vector& rhs) const;

    Vector operator*(const Vector& rhs) const;

    Vector operator/(const Vector& rhs) const;

	// float
    Vector operator*(const float& rhs) const;

    Vector operator/(const float& rhs) const;

    static float Distance(const Vector& v1, const Vector& v2);

    float Length() const;

    Vector Normalized() const;
};

