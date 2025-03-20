#include <iostream>
using namespace std;

int main() {
    float weight, height, bmi;

    cout << "Enter your weight in kg: ";
    cin >> weight;

    cout << "Enter your height in meters: ";
    cin >> height;

    bmi = weight / (height * height);

    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Weight Status: Underweight" << endl;
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "Weight Status: Healthy Weight" << endl;
    } else if (bmi >= 25.0 && bmi <= 29.9) {
        cout << "Weight Status: Overweight" << endl;
    } else {
        cout << "Weight Status: Obesity" << endl;
    }

    return 0;
}
