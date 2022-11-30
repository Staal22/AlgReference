#pragma once

class Vector {
public:
   
   float x{};
   float y{};
   float z{};

   Vector operator +(const Vector& lhs);
   Vector operator -(const Vector& lhs);
   Vector operator *(const Vector& lhs);
   Vector operator /(const Vector& lhs);
};
