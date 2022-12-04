#pragma once


std::ostream& operator<<(std::ostream& os, SomeScalarClass& s)
{
    os << s.value;
    return os;
}

SomeScalarClass::SomeScalarClass()
{
    value = 0;
    next = nullptr;
}

SomeScalarClass::SomeScalarClass(float f):SomeScalarClass()
{
    value = f;
}

SomeScalarClass::SomeScalarClass(const SomeScalarClass& a): SomeScalarClass()   // copy constructor
{
    value = a.value;
}

bool SomeScalarClass::operator<(const SomeScalarClass& rhs) const
{
    return value < rhs.value;
}

bool SomeScalarClass::operator>(const SomeScalarClass& rhs) const
{
    return value > rhs.value;
}

bool SomeScalarClass::operator<=(const SomeScalarClass& rhs) const
{
    return value <= rhs.value;
}
bool SomeScalarClass::operator==(const SomeScalarClass& rhs) const
{
    return value == rhs.value;
}

SomeScalarClass SomeScalarClass::operator+(const SomeScalarClass& rhs) const
{
    return SomeScalarClass(value + rhs.value);
}

std::string SomeScalarClass::ToString()
{
    size_t a = std::to_string(value).find(".");
    return std::to_string(value).substr(0, a + 2);
}
