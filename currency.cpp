#include <iostream>
using namespace std;

int main() {
    float amount, rate, kshs;
    string currency;

    cout << "Enter the currency: ";
    cin >> currency;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Enter the exchange rate (1 " << currency << " to Kshs): ";
    cin >> rate;

    kshs = amount * rate;
    cout << amount << " " << currency << " = " << kshs << " Kshs" << endl;

    return 0;
}
