#include <iostream>

using namespace std;


int main()
{
    int num1, num2, num4, num5;
    double num3 = 57.68;
    num1 = 5;
    num2 = 2;
    num3 = static_cast<double>(num1) / num2;
    cout << num3 << endl;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter a second number: ";
    cin >> num2;

    cout << "You entered: " << num1 << " " << num2 << endl;
    return 0;
}