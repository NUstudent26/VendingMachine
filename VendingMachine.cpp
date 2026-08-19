#include "VendingMachine.h"
#include <iostream>
#include <iomanip>

using namespace std;

VendingMachine::VendingMachine()
    : moneyBox(0.0), selectedProduct(nullptr), insertedAmount(0.0), cardPaid(false) {
}

void VendingMachine::addProduct(const Product& p) {
    products.emplace(p.getName(), p);
}

void VendingMachine::displayProducts() const {
    cout << "Available products:" << endl;
    for (const auto& kv : products) {
        cout << "  " << kv.second.toString() << endl;
    }
}

bool VendingMachine::selectProduct(const string& name) {
    auto it = products.find(name);
    if (it == products.end()) {
        cout << "No such product: " << name << endl;
        return false;
    }
    selectedProduct = &it->second;
    cout << "Selected product: " << name << endl;
    return true;
}

void VendingMachine::acceptCoins(const Coin& coin) {
    insertedCoins.push_back(coin);
    insertedAmount += coin.getValue();
    cout << "Inserted " << coin.toString()
        << " (total so far: $" << fixed << setprecision(2) << insertedAmount << ")" << endl;
}

void VendingMachine::swipeCard(const CreditCard& card) {
    if (card.isValid()) {
        cardPaid = true;
        cout << "Card accepted." << endl;
    }
    else {
        cout << "Card declined." << endl;
    }
}

void VendingMachine::cancel() {
    cout << "Transaction cancelled by user." << endl;
    returnCoins();
}

PurchaseResult VendingMachine::purchase() {
    if (selectedProduct == nullptr) {
        return PurchaseResult::NO_PRODUCT_SELECTED;
    }
    if (selectedProduct->isSoldOut()) {
        returnCoins();
        return PurchaseResult::SOLD_OUT;
    }
    if (!cardPaid && insertedAmount < selectedProduct->getPrice()) {
        returnCoins();
        return PurchaseResult::INSUFFICIENT_PAYMENT;
    }
    dispenseProduct();
    return PurchaseResult::DISPENSED;
}

void VendingMachine::restockProduct(const string& name, int amount) {
    auto it = products.find(name);
    if (it != products.end()) {
        it->second.restock(amount);
        cout << "Restocked " << name << " by " << amount << " unit(s)" << endl;
    }
}

double VendingMachine::collectMoney() {
    double collected = moneyBox;
    moneyBox = 0.0;
    cout << "Operator collected $" << fixed << setprecision(2) << collected << endl;
    return collected;
}

void VendingMachine::dispenseProduct() {
    moneyBox += cardPaid ? selectedProduct->getPrice() : insertedAmount;
    selectedProduct->decrementQuantity();
    cout << "Dispensing: " << selectedProduct->getName() << endl;
    resetTransaction();
}

void VendingMachine::returnCoins() {
    cout << "Returning " << insertedCoins.size() << " coin(s), total $"
        << fixed << setprecision(2) << insertedAmount << endl;
    resetTransaction();
}

void VendingMachine::resetTransaction() {
    selectedProduct = nullptr;
    insertedAmount = 0.0;
    insertedCoins.clear();
    cardPaid = false;
}