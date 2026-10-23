#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
    const int MAX_COLOR_LENGTH = 20;

    char firstColor[MAX_COLOR_LENGTH];
    char secondColor[MAX_COLOR_LENGTH];
    char resultColor[MAX_COLOR_LENGTH] = "";
    bool isValid = true;

    cout << "Enter first primary color (red, blue, yellow): ";
    cin >> setw(MAX_COLOR_LENGTH) >> firstColor;

    cout << "Enter second primary color (red, blue, yellow): ";
    cin >> setw(MAX_COLOR_LENGTH) >> secondColor;

    // Validate first and second colors and determine mixture
    if ((strcmp(firstColor, "red") == 0 && strcmp(secondColor, "blue") == 0) ||
        (strcmp(firstColor, "blue") == 0 && strcmp(secondColor, "red") == 0)) {
        strcpy(resultColor, "purple");
    } 
    else if ((strcmp(firstColor, "red") == 0 && strcmp(secondColor, "yellow") == 0) ||
             (strcmp(firstColor, "yellow") == 0 && strcmp(secondColor, "red") == 0)) {
        strcpy(resultColor, "orange");
    } 
    else if ((strcmp(firstColor, "blue") == 0 && strcmp(secondColor, "yellow") == 0) ||
             (strcmp(firstColor, "yellow") == 0 && strcmp(secondColor, "blue") == 0)) {
        strcpy(resultColor, "green");
    } 
    else if (strcmp(firstColor, secondColor) == 0 &&
            (strcmp(firstColor, "red") == 0 || strcmp(firstColor, "blue") == 0 || strcmp(firstColor, "yellow") == 0)) {
        strcpy(resultColor, firstColor);
    } 
    else {
        isValid = false;
    }

    // Output result
    if (isValid) {
        cout << "Resulting color: " << resultColor << endl;
    } else {
        cout << "Error: You must enter two valid primary colors (red, blue, or yellow)." << endl;
    }

    return 0;
}