#include <iostream>
#include <iomanip> // For formatting output
#include <vector>  // For dynamic storage of items
using namespace std;

int main() {
    int itemCode, quantity;
    float unitPrice, subtotal, grandTotal = 0;
    char anotherItem;

    // Vectors to store item details
    vector<int> itemCodes;
    vector<float> unitPrices;
    vector<int> quantities;
    vector<float> subtotals;

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

        // Store item details in vectors
        itemCodes.push_back(itemCode);
        unitPrices.push_back(unitPrice);
        quantities.push_back(quantity);
        subtotals.push_back(subtotal);

        cout << "Do you want to add another item? (y/n): ";
        cin >> anotherItem;
    } while (anotherItem == 'y' || anotherItem == 'Y');

    // Print the receipt
    cout << "\n\n========== RECEIPT ==========\n";
    cout << "SNo.\tItem Code\tUnit Price\tQuantity\tSubtotal\n";
    cout << "------------------------------------------------------------\n";

    for (size_t i = 0; i < itemCodes.size(); i++) {
        cout << i + 1 << "\t" 
             << itemCodes[i] << "\t\t" 
             << fixed << setprecision(2) << unitPrices[i] << "\t\t" 
             << quantities[i] << "\t\t" 
             << subtotals[i] << "\n";
    }

    cout << "------------------------------------------------------------\n";
    cout << "Grand Total: " << fixed << setprecision(2) << grandTotal << "\n";
    cout << "=============================\n";

    return 0;
}
