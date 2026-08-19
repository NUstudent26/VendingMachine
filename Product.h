#pragma once
#include <string>

class Product {
public:
    Product(std::string name, double price, int quantity)
        : name(std::move(name)), price(price), quantity(quantity) {
    }

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    bool isSoldOut() const { return quantity <= 0; }
    void decrementQuantity() { if (quantity > 0) quantity--; }
    void restock(int amount) { quantity += amount; }

    std::string toString() const {
        char buf[64];
        snprintf(buf, sizeof(buf), "%-8s $%.2f (qty: %d)", name.c_str(), price, quantity);
        return std::string(buf);
    }
private:
    std::string name;
    double price;
    int quantity;
};