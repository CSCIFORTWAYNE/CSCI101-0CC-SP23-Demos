#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <climits>

const int MAX_CANDIDATES = 10;

struct candidateType
{
    std::string name;
    int votes;
    double percent;
};

struct ballotType
{
    candidateType candidates[MAX_CANDIDATES];
    int numCandidate;
};

void printCandidate(candidateType);
void printCandidate(std::ostream &, candidateType);
candidateType getVotes(candidateType);
void resetStream();

int main()
{
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;
    std::ifstream infile;
    std::string filename;
    std::cout << "Enter the name of the file without the .txt: ";
    std::getline(std::cin >> std::ws, filename);
    std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    infile.open(filename + ".txt");

    if (!infile.is_open())
    {
        std::cout << "The file " << filename << ".txt could not be opened." << std::endl;
        return 0;
    }
    ballotType theBallot;
    theBallot.numCandidate = 0;
    int total = 0;
    int winner = 0;
    while (!infile.eof() && theBallot.numCandidate < MAX_CANDIDATES)
    {
        infile >> theBallot.candidates[theBallot.numCandidate++].name;
    }

    for (int i = 0; i < theBallot.numCandidate; i++)
    {
        theBallot.candidates[i] = getVotes(theBallot.candidates[i]);
        total = total + theBallot.candidates[i].votes;
    }

    for (int i = 0; i < theBallot.numCandidate; i++)
    {
        theBallot.candidates[i].percent = theBallot.candidates[i].votes / static_cast<double>(total);
    }
    std::cout << std::left << std::setw(10) << "Candidate" << std::right << "   " << std::setw(10) << "Votes Received"
              << "   " << std::setw(15) << "% of Total Votes" << std::endl;

    for (int i = 0; i < theBallot.numCandidate; i++)
    {
        printCandidate(theBallot.candidates[i]);
    }
    std::cout << std::left;
    std::cout << std::setw(19) << "Total" << total << std::endl;

    for (int i = 1; i < theBallot.numCandidate; i++)
    {
        if (theBallot.candidates[i].votes > theBallot.candidates[winner].votes)
        {
            winner = i;
        }
    }
    std::cout << "The Winner of the Election is " << theBallot.candidates[winner].name << "." << std::endl;
    /* candidateType first;
    candidateType second;
    infile >> first.name;

    std::cout << "The first candidate is " << first.name << std::endl;

    second = first;
    std::cout << "The second candidate is " << second.name << std::endl;

    printCandidate(first);
    printCandidate(std::cout, first);

    std::ofstream out;
    out.open("output.txt");
    printCandidate(out, second); */

    return 0;
}

void printCandidate(candidateType c)
{
    std::cout << std::left << std::setw(10) << c.name
              << std::right << "   " << std::setw(10) << c.votes << "   " << std::setw(15)
              << c.percent * 100 << "%" << std::endl;
}

void printCandidate(std::ostream &out, candidateType c)
{
    out << std::left << std::setw(10) << c.name
        << std::right << "   " << std::setw(10) << c.votes << "   " << std::setw(15)
        << c.percent * 100 << "%" << std::endl;
}

candidateType getVotes(candidateType c)
{
    std::cout << "Enter the number of votes received by " << c.name << ": ";
    std::cin >> c.votes;
    std::cout << std::endl;
    while (!std::cin || c.votes < 0)
    {
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "The votes should be greater than 0" << std::endl;
        }
        std::cout << "Enter the number of votes received by " << c.name << ": ";
        std::cin >> c.votes;
        std::cout << std::endl;
    }
    return c;
}

void resetStream()
{

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number." << std::endl;
}