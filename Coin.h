#pragma once
#include <string>

class Coin {
public:
    explicit Coin(double value) : value(value) {}
    double getValue() const { return value; }
    std::string toString() const {
        char buf[32];
        snprintf(buf, sizeof(buf), "$%.2f coin", value);
        return std::string(buf);
    }
private:
    double value;
};