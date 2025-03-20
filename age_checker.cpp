#include <iostream>
using namespace std;

int main() {
    int age;

    cout << "Enter your age: ";
    cin >> age;

    if (age >= 20 && age <= 25) {
        cout << "You are an adult" << endl;
    } else {
        cout << "That age has not been considered" << endl;
    }

    return 0;
}
