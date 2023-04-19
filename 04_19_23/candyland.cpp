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

int main()
{
    colorType board[BOARD_SIZE];
    generateBoard(board, BOARD_SIZE);
    playerListType playerList;
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
        // players go here
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
