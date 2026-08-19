#pragma once
#include <string>

class User {
public:
    explicit User(std::string name) : name(std::move(name)) {}
    std::string getName() const { return name; }
private:
    std::string name;
};