#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number % 2 == 0) {
        int result = number * 3;
        cout << "The result is: " << result << endl;
    }

    return 0;
}
