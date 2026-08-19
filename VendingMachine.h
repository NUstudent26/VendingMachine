#pragma once
#include <map>
#include <string>
#include <vector>
#include "Product.h"
#include "Coin.h"
#include "CreditCard.h"
#include "PurchaseResult.h"

class VendingMachine {
public:
    VendingMachine();

    void addProduct(const Product& p);
    void displayProducts() const;
    bool selectProduct(const std::string& name);
    void acceptCoins(const Coin& coin);
    void swipeCard(const CreditCard& card);
    void cancel();
    PurchaseResult purchase();
    void restockProduct(const std::string& name, int amount);
    double collectMoney();

private:
    void dispenseProduct();
    void returnCoins();
    void resetTransaction();

    std::map<std::string, Product> products;
    double moneyBox;
    Product* selectedProduct;
    double insertedAmount;
    std::vector<Coin> insertedCoins;
    bool cardPaid;
};