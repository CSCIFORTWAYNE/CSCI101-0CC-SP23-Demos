#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool validateUnits(string units);
int secret(int x);
void resetStream(istream &in);
void inputInt(istream &in, int &x, string prompt);
int count();

int main()
{
    long long memSize;
    string units;
    int mem;

    inputInt(cin, mem, "Enter the memory size:");

    while (mem < 0)
    {

        cout << "The value entered is invalid. Please enter a number greater than 0." << endl;
        inputInt(cin, mem, "Enter the memory size:");
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
        memSize = mem * pow(2, 40);
    }
    else if (units == "GB")
    {
        memSize = mem * pow(2, 30);
    }
    else if (units == "MB")
    {
        memSize = mem * pow(2, 20);
    }
    else if (units == "KB")
    {
        memSize = mem * pow(2, 10);
    }
    else
    {
        memSize = mem;
    }

    cout << "The minimum MAR needed is " << ceil(log2(memSize)) << " bits." << endl;
    int y = 3;
    y = secret(y);

    for (int i = 0; i < 10; i++)
    {
        cout << count() << endl;
    }

    return 0;
}

bool validateUnits(string units)
{
    transform(units.begin(), units.end(), units.begin(), ::toupper);
    bool valid = !(units != "B" && units != "KB" && units != "MB" && units != "GB" && units != "TB");
    return valid;
}

int secret(int x)
{
    if (x > 5)
        return 2 * x;

    return x;
}

void resetStream(istream &in)
{
    in.clear();
    in.ignore(INT_MAX, '\n');
    cout << "You entered something that is not a number!" << endl;
}

void inputInt(istream &in, int &x, string prompt)
{
    if (prompt != "")
    {
        cout << prompt << " ";
    }
    in >> x;
    while (!in)
    {
        resetStream(in);
        if (prompt != "")
        {
            cout << prompt << " ";
        }
        in >> x;
    }
}

int count()
{
    static int numTimes = 0;
    // do something that increases the value of numTimes by 1;
    return numTimes;
}
