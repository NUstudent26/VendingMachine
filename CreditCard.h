#pragma once
#pragma once
#include <string>

class CreditCard {
public:
    explicit CreditCard(std::string number) : number(std::move(number)) {}
    std::string getNumber() const { return number; }
    bool isValid() const { return number.size() == 16; }
private:
    std::string number;
};