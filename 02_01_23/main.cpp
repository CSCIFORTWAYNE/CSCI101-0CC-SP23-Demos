#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    cout << setprecision(2) << fixed << showpoint;
    int x;
    char y;
    double z;
    string str;

    cout << "Enter a number: ";
    cin >> x;
    cout << endl;

    cout << "Enter a character: ";
    cin >> y;
    // cin.get(y);
    cout << endl;

    cout << "Enter a double: ";
    cin >> z;
    cout << endl;

    cout << "Enter a string: ";
    // cin >> str;

    getline(cin >> ws, str);
    cout << endl;
    cout << left;
    cout << "+-" << setw(10) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(10) << "x"
         << "| " << setw(20) << x << "|" << endl;
    cout << "+-" << setw(10) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(10) << "y"
         << "| " << setw(20) << y << "|" << endl;
    cout << "+-" << setw(10) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(10) << "z"
         << "| " << setw(20) << z << "|" << endl;
    cout << "+-" << setw(10) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(10) << "str"
         << "| " << setw(20) << str << "|" << endl;
    cout << "+-" << setw(10) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;

    z = pow(4, 5);

    string make, model, color;
    int year;

    ifstream car;
    car.open("cars.txt");

    getline(car >> ws,make);
    getline(car >> ws, model);
    car >> year;
    getline(car >> ws, color);

    ofstream carout;
    carout.open("carout.txt");

    carout << "Car #1: " << make << " " << model << " " << year << " " << color << endl;

    getline(car >> ws,make);
    getline(car >> ws, model);
    car >> year;
    getline(car >> ws, color);
    carout << "Car #2: " << make << " " << model << " " << year << " " << color << endl;

    car.close();
    carout.close();

    ifstream win;
    win.open("winners.txt");

    string fname, lname;
    double winnings;
    cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(30) << "Name" << "| " << setw(20) << "Winnings" << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;

    win >> fname >> lname >> winnings;
     cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(30) << fname + " " + lname << "| $" << setw(19) << winnings << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    win >> fname >> lname >> winnings;
cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(30) << fname + " " + lname << "| $" << setw(19) << winnings << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    win >> fname >> lname >> winnings;
cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(30) << fname + " " + lname << "| $" << setw(19) << winnings << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-"
         << "+-" << setw(20) << "-"
         << "+" << endl;
    return 0;
}