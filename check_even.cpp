#include <iostream>
using namespace std;

int main() {
    int number;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> number;

    // Check if the number is even
    if (number % 2 == 0) {
        cout << "The number is even: " << number << endl;
    }

    return 0;
}
