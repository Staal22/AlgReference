#pragma once
#include <string>

class IStringable {
public:
    virtual ~IStringable() = default;
    virtual std::string ToString() = 0;
};
