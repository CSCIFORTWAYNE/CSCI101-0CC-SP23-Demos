#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int main()
{
    int count = 0;
    int totalDays;
    int day;
    int sum = 0;
    cout << "How many days do you want to average? ";
    cin >> totalDays;
    cout << endl;
    while (!cin || totalDays <= 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You entered something that is not a number." << endl;
        }
        else
        {
            cout << "The total number of days must be greater than 0." << endl;
        }
        cout << "How many days do you want to average? ";
        cin >> totalDays;
        cout << endl;
    }

    while (count < totalDays) // convert to a for loop
    {
        cout << "Enter the calories burned for day " << count + 1 << ": ";
        cin >> day;
        while (!cin || day < 1)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "You entered something that is not a number." << endl;
            }
            else
            {
                cout << "The number of calories burned must be greater than 0." << endl;
            }
            cout << "Enter the calories burned for day " << count + 1 << ": ";
            cin >> day;
        }
        cout << endl;
        sum += day; // sum = sum + day;
        count++;    // count = count + 1;
    }
    cout << "The average number of calories burned is " << static_cast<double>(sum) / totalDays << "." << endl;
    int num;
    while (num != 3)
    {
        cout << "Welcome to Calculation!" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Options" << endl;
        cout << "3. Quit" << endl;
        cin >> num;
        cout << endl;

        while (!cin || num > 3 || num < 1)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "You entered something that is not a number." << endl;
            }
            else
            {
                cout << "You entered an option not on the menu." << endl;
            }
            cin >> num;
            cout << endl;
        }
        cout << num << endl;
    }
    ifstream input;
    input.open("input.txt");
    if (!input.is_open())
    {
        cout << "Unable to open file." << endl;
    }
    int largest = 0, secondLargest = 0;
    while (!input.eof())
    {
        input >> num;
        sum += num;
        count++;
        cout << num << endl;
        if (num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
        else if (num > secondLargest)
        {
            secondLargest = num;
        }
    }
    cout << "The average of everything in the file is " << static_cast<double>(sum) / count << endl;

    return 0;
}