#include <iostream>
#include <limits>
#include "Coin.h"
#include "CreditCard.h"
#include "Product.h"
#include "User.h"
#include "VendingMachine.h"
#include "Operator.h"

using namespace std;

void printMenu() {
    cout << "\n   - Vending Machine -\n"  
        << "1. Show products\n"
        << "2. Select a product\n"
        << "3. Insert a coin\n"
        << "4. Swipe credit card\n"
        << "5. Purchase\n"
        << "6. Cancel transaction\n"
        << "7. [Operator] Restock a product\n"
        << "8. [Operator] Collect money\n"
        << "0. Exit\n"
        << "Choose an option: ";
}

int main() {
    VendingMachine machine;
    machine.addProduct(Product("Soda", 1.25, 2));
    machine.addProduct(Product("Chips", 1.75, 0));
    machine.addProduct(Product("Candy", 1.00, 5));

    Operator op("Sam");
    int choice = -1;

    while (choice != 0) {
        printMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a number. Try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            machine.displayProducts();
            break;

        case 2: {
            cout << "Enter product name: ";
            string name;
            cin >> name;
            machine.selectProduct(name);
            break;
        }

        case 3: {
            cout << "Enter coin value : ";
            double value;
            cin >> value;
            machine.acceptCoins(Coin(value));
            break;
        }

        case 4: {
            cout << "Enter 16-digit card number: ";
            string number;
            cin >> number;
            machine.swipeCard(CreditCard(number));
            break;
        }

        case 5: {
            PurchaseResult result = machine.purchase();
            cout << "Result: " << resultToString(result) << endl;
            break;
        }

        case 6:
            machine.cancel();
            break;

        case 7: {
            cout << "Enter product name to restock: ";
            string name;
            cin >> name;
            cout << "Enter quantity to add: ";
            int amount;
            cin >> amount;
            op.restockProducts(machine, name, amount);
            break;
        }

        case 8:
            op.removeMoney(machine);
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Not a valid option. Try again.\n";
        }
    }

    return 0;
}