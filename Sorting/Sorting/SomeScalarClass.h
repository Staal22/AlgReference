#pragma once
#include <iostream>
#include "Interfaces/Stringable.h"

class SomeScalarClass : public IStringable {
public:
    // SomeScalarClass() = default;
    SomeScalarClass();

    SomeScalarClass(float f);

    SomeScalarClass(const SomeScalarClass& a);

    float value{};

    SomeScalarClass* next;

    // used for sorting
    bool operator <(const SomeScalarClass& rhs) const;

    bool operator >(const SomeScalarClass& rhs) const;

    bool operator <=(const SomeScalarClass& rhs) const;

    bool operator == (const SomeScalarClass& rhs) const;
    
    SomeScalarClass operator +(const SomeScalarClass& rhs) const;

    std::string ToString() override;

    // overloading the std::cout << operator! This way we can super easily debug it to console
    // note: we cannot do this directly in the class, becouse when oveloading normally we can only choose the operator and the *right* side of the operator (where left is the class)
    // therefore we have to link it to a seperate overload (hence the friend keyword)
    friend std::ostream& operator<<(std::ostream& os, SomeScalarClass& s);

};

#include "SomeScalarClass.tpp"

