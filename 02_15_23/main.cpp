#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << endl;
    if (!cin)
    {
        cout << "You entered something that not an integer." << endl;
        return 0;
    }
    if (0 <= num && num <= 10)
        cout << num << " is within 0 and 10." << endl;
    else
        cout << num << " is not within 0 and 10." << endl;

    if (num == 5)
    {
        cout << "I'm here!" << endl;
    }
    bool found;
    found = true;
    return 0;

    /* int win = 83;
    int user = 0;
    char ch;
    cout << "Enter a number: ";
    cin >> user;
    cout << endl;
    cout << "Enter a character: ";
    cin >> ch;
    cout << endl;

    if (win >= user)
    {

        cout << "I won!!" << endl;
        if (ch <= 'A')
        {
            cout << "You Lose!!" << endl;
        }
    }
    else if (ch >= 'A')
    {
        cout << "I'll get you next time!" << endl;
    }
    cout << "Thanks for playing!" << endl
         << endl;
    if (fabs(1.0 - (3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0)) < 0.000001)
    {
        cout << "The floating point numbers are equal" << endl;
    }
    else
    {
        cout << 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 << endl;
    }
    cout << endl; */

    return 0;
}