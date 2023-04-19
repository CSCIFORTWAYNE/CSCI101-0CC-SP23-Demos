#include <iostream>
#include <string>
#include <fstream>
#include <climits>

const int NUM_COLORS = 6;
const int DECK_SIZE = 60;
const int BOARD_SIZE = 115;
const int MAX_PLAYERS = 6;

enum colorType
{
    START = -1,
    RED,
    PURPLE,
    YELLOW,
    GREEN,
    BLUE,
    ORANGE
};
const std::string colorName[] = {"Red", "Purple", "Yellow", "Green", "Blue", "Orange"};
const colorType colors[] = {RED,
                            PURPLE,
                            YELLOW,
                            GREEN,
                            BLUE,
                            ORANGE};
const std::string colorStr[] = {"\033[38;5;196m\033[48;5;88m",
                                "\033[38;5;135m\033[48;5;53m",
                                "\033[38;5;226m\033[48;5;178m",
                                "\033[38;5;118m\033[48;5;2m",
                                "\033[38;5;81m\033[48;5;4m",
                                "\033[38;5;214m\033[48;5;166m"};
const std::string STARTCOLOR = "\033[1m";
const std::string RESETCOLOR = "\033[0m";

struct cardType
{
    colorType color;
    bool isDouble = false;
};

struct playerType
{
    std::string name;
    colorType color;
    int position = 0;
};

struct playerListType
{
    playerType playerList[MAX_PLAYERS];
    int numPlayer;
};

void generateBoard(colorType[], int);
std::string getColorName(colorType); // complete for lecture activity
void printBoard(colorType[], int, playerListType &);
std::string printConsoleColor(colorType);
void setupPlayers(playerListType &);
int getNumPlayers();
playerType createAPlayer(int);
void resetStream();
colorType inputColor();
void printPlayerOnBoard(playerListType &, int, std::string);

int main()
{
    colorType board[BOARD_SIZE];
    generateBoard(board, BOARD_SIZE);
    playerListType playerList;
    setupPlayers(playerList);
    printBoard(board, BOARD_SIZE, playerList);
    return 0;
}

void generateBoard(colorType board[], int spaces)
{
    std::ifstream boardIn;
    boardIn.open("boardSequence.txt");
    board[0] = START;
    for (int i = 1; i < spaces; i++)
    {
        int c;
        boardIn >> c;
        board[i] = colors[c % NUM_COLORS];
    }
    boardIn.close();
}

void printBoard(colorType board[], int spaces, playerListType &pl)
{
    for (int i = 0; i < spaces; i++)
    {
        std::cout << printConsoleColor(board[i]) << "[ ";
        printPlayerOnBoard(pl, i, printConsoleColor(board[i]));
        std::cout << " ]";
        std::cout << RESETCOLOR << " ";
        if ((i + 1) % 5 == 0)
        {
            std::cout << std::endl
                      << std::endl;
        }
    }
}

std::string printConsoleColor(colorType c)
{
    std::string out = STARTCOLOR;
    if (c == START)
    {
        out = RESETCOLOR;
    }
    else
    {
        out += colorStr[c];
    }
    return out;
}

void setupPlayers(playerListType &pl)
{
    pl.numPlayer = getNumPlayers();
    for (int i = 0; i < pl.numPlayer; i++)
    {
        pl.playerList[i] = createAPlayer(i + 1);
        std::cout << "Hello " << pl.playerList[i].name << "! You can now pick a color." << std::endl;
        pl.playerList[i].color = inputColor();
        for (int j = 0; j < i; j++)
        {
            if (pl.playerList[j].color == pl.playerList[i].color)
            {
                std::cout << pl.playerList[j].name << " has already picked that color. Please pick again." << std::endl;
                pl.playerList[i].color = inputColor();
                j = -1;
            }
        }
    }
}

int getNumPlayers()
{
    int numPlayers;
    std::cout << "Enter the number of players between 2 and " << MAX_PLAYERS << ": ";
    std::cin >> numPlayers;
    std::cout << std::endl;
    while (!std::cin || numPlayers < 2 || numPlayers > MAX_PLAYERS)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid value." << std::endl;
        std::cout << "Enter the number of players between 2 and " << MAX_PLAYERS << ": ";
        std::cin >> numPlayers;
        std::cout << std::endl;
    }
    return numPlayers;
}

playerType createAPlayer(int n)
{
    playerType newPlayer;
    std::cout << "Player " << n << " enter your name: ";
    std::getline(std::cin >> std::ws, newPlayer.name);
    newPlayer.position = 0;
    return newPlayer;
}

colorType inputColor()
{
    int num;
    colorType color;
    std::cout << "Choose a color:" << std::endl;
    for (int i = 0; i < NUM_COLORS; i++)
    {
        std::cout << i + 1 << ". " << colorName[i] << std::endl;
    }
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || num - 1 < 0 || num - 1 > NUM_COLORS)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose a color using the number next to the color name." << std::endl;
        std::cin >> num;
        std::cout << std::endl;
    }
    color = colors[num - 1];
    return color;
}

void printPlayerOnBoard(playerListType &pl, int boardSpace, std::string spaceColor)
{
    for (int i = 0; i < pl.numPlayer; i++)
    {
        if (pl.playerList[i].position == boardSpace)
        {
            std::cout << printConsoleColor(pl.playerList[i].color);
            std::cout << i + 1;
            std::cout << spaceColor;
        }
        else
        {
            std::cout << " ";
        }
    }
}

void resetStream()
{

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number." << std::endl;
}
