#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Named constants to avoid magic numbers
    const double CONVERSION_FACTOR = 703.0;
    const double UNDERWEIGHT_THRESHOLD = 18.5;
    const double OPTIMAL_MAX_THRESHOLD = 25.0;
    const double MIN_VALID_INPUT = 0.0;

    double weight = 0.0;
    double height = 0.0;
    double bmi = 0.0;
    string status = "";

    cout << "Enter weight in pounds: ";
    cin >> weight;

    cout << "Enter height in inches: ";
    cin >> height;

    // Input validation
    if (weight <= MIN_VALID_INPUT || height <= MIN_VALID_INPUT) {
        cout << "Invalid input. Weight and height must be positive values." << endl;
    } else {
        // Store calculation in result variable before displaying
        bmi = (weight * CONVERSION_FACTOR) / (height * height);

        if (bmi < UNDERWEIGHT_THRESHOLD) {
            status = "Underweight";
        } else if (bmi <= OPTIMAL_MAX_THRESHOLD) {
            status = "Optimal weight";
        } else {
            status = "Overweight";
        }

        cout << fixed << setprecision(2);
        cout << "BMI: " << bmi << endl;
        cout << "Status: " << status << endl;
    }

    return 0;
}