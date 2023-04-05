#include <iostream>
#include <string>
#include <climits>

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

std::string colorToString(colorType);
colorType inputColor(std::string);
void resetStream();

// create an input and output function for your enum

int main()
{
    colorType color = BLUE;
    std::cout << colorToString(color) << " = " << color << std::endl;
    color = inputColor("Choose your favorite color");
    std::cout << "Your favorite color is " << colorToString(color) << std::endl;
    color = inputColor("Choose your neighbor's favorite color");
    std::cout << "Your neighbor's favorite color is " << colorToString(color) << std::endl;
    std::string a = "hello ";
    std::string b = "there ";
    std::cout << a << b << colorToString(color) << std::endl;

    // create a cereal variable use your functions to do input and output of the variable.

    return 0;
}

std::string colorToString(colorType theColor)
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

colorType inputColor(std::string prompt)
{
    int colorInt;
    colorType theColor;
    std::cout << prompt << std::endl;
    for (int i = 0; i <= PURPLE; i++)
    {
        std::cout << i + 1 << ". " << colorToString(static_cast<colorType>(i)) << std::endl;
    }
    std::cin >> colorInt;
    while (!std::cin || colorInt - 1 < BLUE || colorInt - 1 > PURPLE)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose a color from the list." << std::endl;
        std::cin >> colorInt;
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
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number!" << std::endl;
}