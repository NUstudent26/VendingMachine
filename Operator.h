#pragma once
#include <string>
#include "VendingMachine.h"

class Operator {
public:
    explicit Operator(std::string name) : name(std::move(name)) {}

    void restockProducts(VendingMachine& machine, const std::string& productName, int amount) {
        machine.restockProduct(productName, amount);
    }
    double removeMoney(VendingMachine& machine) {
        return machine.collectMoney();
    }
private:
    std::string name;
};