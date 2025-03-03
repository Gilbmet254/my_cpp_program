#include <iostream>
using namespace std;

int main() {
    int itemCode, quantity;
    float unitPrice, subtotal, grandTotal = 0;
    char anotherItem;

    do {
        cout << "Enter item code: ";
        cin >> itemCode;
        cout << "Enter unit price: ";
        cin >> unitPrice;
        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity > 4) {
            cout << "Error: Cannot buy more than 4 units of the same item.\n";
            continue;
        }

        subtotal = unitPrice * quantity;
        grandTotal += subtotal;

        cout << "\nSNo.\tItem Code\tUnit Price\tQuantity\tSubtotal\n";
        cout << "1\t" << itemCode << "\t\t" << unitPrice << "\t\t" << quantity << "\t\t" << subtotal << endl;

        cout << "Do you want to add another item? (y/n): ";
        cin >> anotherItem;
    } while (anotherItem == 'y' || anotherItem == 'Y');

    cout << "\nGrand Total: " << grandTotal << endl;

    return 0;
}
