#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool validateUnits(string units)
{
    transform(units.begin(), units.end(), units.begin(), ::toupper);
    bool valid = !(units != "B" && units != "KB" && units != "MB" && units != "GB" && units != "TB");
    return valid;
}

int main()
{
    long long memSize;
    string units;

    cout << "Enter the memory size: ";
    cin >> memSize;
    cout << endl;
    while (!cin || memSize < 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        cout << "The value entered is invalid. Please enter a number greater than 0." << endl;
        cout << "Enter the memory size: ";
        cin >> memSize;
        cout << endl;
    }
    cout << "Enter the memory units (B, KB, MB, GB, TB): ";
    cin >> units;
    cout << endl;
    transform(units.begin(), units.end(), units.begin(), ::toupper);
    while (!validateUnits(units))
    {
        cout << "Your entry is not a valid memory unit. Valid units are B, KB, MB, GB, TB." << endl;
        cout << "Enter the memory units (B, KB, MB, GB, TB): ";
        cin >> units;
        cout << endl;
        transform(units.begin(), units.end(), units.begin(), ::toupper);
    }

    if (units == "TB")
    {
        memSize = memSize * pow(2, 40);
    }
    else if (units == "GB")
    {
        memSize = memSize * pow(2, 30);
    }
    else if (units == "MB")
    {
        memSize = memSize * pow(2, 20);
    }
    else if (units == "KB")
    {
        memSize = memSize * pow(2, 10);
    }

    cout << "The minimum MAR needed is " << ceil(log2(memSize)) << " bits." << endl;

    return 0;
}