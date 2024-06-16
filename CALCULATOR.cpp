#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero!";
                return 1; // Exit the program with an error codee
            }
            break;
        default:
            cout << "invalid operation!";
            return 1; // Exit the program with an error code
    }

    cout << "Result: " << result << endl;

    return 0; // Exit the program successfullly
}
