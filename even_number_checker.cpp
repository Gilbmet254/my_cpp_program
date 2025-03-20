#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    if (!(number % 2)) {
        cout << "That number is an even number" << endl;
    } else {
        cout << "That number is not an even number" << endl;
    }

    return 0;
}
