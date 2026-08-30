#include <iostream>
#include <string>

#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"
#include "modulo.h"

using namespace std;

void showMenu()
{
    cout << "\n==============================\n";
    cout << "      BIG INTEGER CALCULATOR\n";
    cout << "==============================\n";

    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulo\n";
    cout << "6. Exit\n";

    cout << "==============================\n";
    cout << "Enter your choice: ";
}

int main()
{
    int choice;

    while (true)
    {
        showMenu();
        cin >> choice;

        if (choice == 6)
        {
            cout << "Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 6)
        {
            cout << "Invalid choice!\n";
            continue;
        }

        string num1, num2;

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        string result;

        switch (choice)
        {
            case 1:
                result = add(num1, num2);
                break;

            case 2:
                result = subtract(num1, num2);
                break;

            case 3:
                result = multiply(num1, num2);
                break;

            case 4:
                result = divide(num1, num2);
                break;

            case 5:
                result = modulo(num1, num2);
                break;
        }

        cout << "\nResult: " << result << "\n";
    }

    return 0;
}
