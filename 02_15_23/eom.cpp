#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int empWin1, empWin2, empWin3;
    double discount1, discount2, discount3;

    ifstream eom;
    eom.open("EOM.txt");
    if (!eom.is_open())
    {
        cout << "The file was unable to be opened. Program will exit." << endl;
        return 0;
    }
    eom >> empWin1 >> discount1;
    eom >> empWin2 >> discount2;
    eom >> empWin3 >> discount3;

    int userEmpNum;
    double appliedDiscount;

    cout << "Enter your employee number to see if you get a discount: ";
    cin >> userEmpNum;
    cout << endl;

    if (!cin)
    {
        cout << "You did not enter a number! The program will now exit." << endl;
        return 0;
    }
    if (userEmpNum < 10000 || userEmpNum > 99999)
    {
        cout << "You entered a number that is out of range! Employee numbers are 5 digits (between 10000 and 99999). Program will now exit." << endl;
        return 0;
    }
    if (userEmpNum == empWin1)
    {
        appliedDiscount = discount1;
    }
    else if () // second winner
    {
    }
    else if () // third winner
    {
    }
    else
    {
        cout << "Sorry you did not win a discount this month. Try again next month." << endl;
        return 0;
    }
    double totalBill = 0;
    cout << "You have won a discount of " << appliedDiscount * 100 << "%.";
    cout << "Enter the total bill: ";
    cin >> totalBill;
    // two if statements for validation first is there input failure second is the total bill greater than 0
    // The total should be greater than 0. The program will now exit.
    // You did not enter a number! The program will now exit.
    double discountAmount = totalBill * appliedDiscount;
    cout << "Your discount will take $" << discountAmount << " off your bill." << endl;
    cout << "Your new total is $" << totalBill - discountAmount << "." << endl;

    return 0;
}