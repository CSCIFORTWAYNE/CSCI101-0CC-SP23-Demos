#include <iostream>
#include <string>
#include <climits>

using namespace std;

/* const int BLUE = 0;
const int RED = 1;
const int GREEN = 2;
const int YELLOW = 3;
const int PURPLE = 0; */
enum colorType
{
    BLUE,
    RED,
    GREEN,
    YELLOW,
    PURPLE
};

// create an enum of breakfast cereal with at least 4 values

string colorToString(colorType);
colorType inputColor(string);
void resetStream();

// create an input and output function for your enum

int main()
{
    colorType color = BLUE;
    cout << colorToString(color) << " = " << color << endl;
    color = inputColor("Choose your favorite color");
    cout << "Your favorite color is " << colorToString(color) << endl;
    color = inputColor("Choose your neighbor's favorite color");
    cout << "Your neighbor's favorite color is " << colorToString(color) << endl;
    string a = "hello ";
    string b = "there ";
    cout << a << b << colorToString(color) << endl;

    // create a cereal variable use your functions to do input and output of the variable.

    return 0;
}

string colorToString(colorType theColor)
{
    switch (theColor)
    {
    case BLUE:
        return "Blue";
    case RED:
        return "Red";
    case GREEN:
        return "Green";
    case YELLOW:
        return "Yellow";
    case PURPLE:
        return "Purple";
    default:
        return "Unknown";
    }
}

colorType inputColor(string prompt)
{
    int colorInt;
    colorType theColor;
    cout << prompt << endl;
    for (int i = 0; i <= PURPLE; i++)
    {
        cout << i + 1 << ". " << colorToString(static_cast<colorType>(i)) << endl;
    }
    cin >> colorInt;
    while (!cin || colorInt - 1 < BLUE || colorInt - 1 > PURPLE)
    {
        if (!cin)
        {
            resetStream();
        }
        cout << "Please choose a color from the list." << endl;
        cin >> colorInt;
    }
    switch (colorInt - 1)
    {
    case BLUE:
        theColor = BLUE;
        break;
    case RED:
        theColor = RED;
        break;
    case GREEN:
        theColor = GREEN;
        break;
    case YELLOW:
        theColor = YELLOW;
        break;
    case PURPLE:
        theColor = PURPLE;
        break;
    default:
        theColor = BLUE;
    }

    return theColor;
}

void resetStream()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "You entered something that is not a number!" << endl;
}