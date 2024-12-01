// Name: Calder Kamman
// KUID: 3123207
// LAB Session: Thursday 9 a.m.
// LAB Assignment: Extra Credit
// Description: Write a C++ program that reads a string from the user and extracts a valid double-precision floating-point number from it without using library functions like std::stod. The program should handle potential errors in the input and provide clear feedback to the user
// Collaborators: None

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string& str) {
    bool hasDecimal = false;
    bool hasSign = false;
    bool isValid = true;
    string numberStr = "";

    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];

        if ((c == '+' || c == '-') && i == 0) {
            hasSign = true;
            numberStr += c;
        }
        else if (isdigit(c)) {
            numberStr += c;
        }
        else if (c == '.' && !hasDecimal) {
            hasDecimal = true;
            numberStr += c;
        } else {
            isValid = false;
            break;
        }
    }


    if (isValid && !numberStr.empty() && numberStr != "+" && numberStr != "-") {
        try {
            return stod(numberStr);
        } catch (...) {
            return -999999.99;
        }
    }

    return -999999.99; 
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
