#include <iostream>
#include <string>
using namespace std;

int main() {
    string inputName;
    string correctName = "Gilbmet"; // Replace with your actual name

    cout << "Enter your name: ";
    getline(cin, inputName); // Use getline to read the entire line

    if (inputName == correctName) {
        cout << "Your name is correctly spelt." << endl;
    } else {
        cout << "Your name is incorrectly spelt." << endl;
    }

    return 0;
}
