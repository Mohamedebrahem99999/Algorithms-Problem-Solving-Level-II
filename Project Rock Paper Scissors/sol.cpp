#include "../random.h"
#include "../NumberTheory.h"
#include "../input.h"
#include <ctime>
#include <string>
// #include <windows.h>

// #define BG_RED "\033[41m"
// #define BG_GREEN "\033[42m"
// #define BG_YELLOW "\033[43m"
// #define RESET "\033[0m"

// void enableAnsiColors()
// {
//     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//     DWORD dwMode = 0;
//     GetConsoleMode(hOut, &dwMode);
//     dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//     SetConsoleMode(hOut, dwMode);
// }

enum enChoices
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum enWinner
{
    Computer,
    Player,
    Draw
};

enum enColor
{
    RED,
    YELLOW,
    GREEN
};

struct stGameResults
{
    short Rounds = 0;
    short PlayserWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    std::string WinnerName;
};

struct stRoundInfo
{
    short RoundNumber = 0;
    enChoices PlayerChoice;
    enChoices ComputerChoice;
    enWinner Winner;
    std::string WinnerName;
};

void showHelloMessage()
{
    std::cout << "\n\n________________* Welcome to Rock, Paper, Scissors Game *________________\n\n";
}

bool doesKnow()
{
    std::cout << "Do you know the rules?\n";
    std::cout << "1) Yes\n";
    std::cout << "2) No\n";
    return readNumberInRange(2, 1, "Enter either 1 or 2: ") == 1 ? true : false;
}

void printRules(bool DoesKnow)
{
    if (!DoesKnow)
    {
        std::cout << "\n_______________________Game Rules_______________________\n\n";
        std::cout << "Rock beats Scissors\n";
        std::cout << "Scissors beats Paper\n";
        std::cout << "Paper beats Rock\n";
        std::cout << "\n_______________________Start Game ______________________\n\n";
    }
}

void showRules()
{
    printRules(doesKnow());
}

void printChoices()
{
    std::cout << "_______________________Enter a Choice_______________________\n\n";
    std::cout << "1) Rock\n";
    std::cout << "2) Paper\n";
    std::cout << "3) Scissors\n";
    std::cout << "\n___________________________________________________\n\n";
}

enChoices readUserChoice()
{
    printChoices();
    return (enChoices)readNumberInRange(3, 1);
}

enChoices getComputerChoice()
{
    return (enChoices)generateRandomNumberInRange(3, 1);
}

std::string getChoice(enChoices Choice)
{
    switch (Choice)
    {
    case enChoices::Rock:
        return "Rock";
    case enChoices::Paper:
        return "Paper";
    case enChoices::Scissors:
        return "Scissors";
    default:
        return "Invalid";
    }
}

void setScreenColor(enColor Color)
{
    std::string Colors[] = {"4F", "E0", "A0"};
    std::string ColorStr = "color " + Colors[Color];
    system(ColorStr.c_str());
}

enWinner detectWinner(stRoundInfo RoundInfo)
{
    if (RoundInfo.ComputerChoice == RoundInfo.PlayerChoice)
    {
        setScreenColor(enColor::YELLOW);
        return enWinner::Draw;
    }
        
    switch (RoundInfo.PlayerChoice)
    {
    case enChoices::Rock:
        switch (RoundInfo.ComputerChoice)
        {
        case enChoices::Paper:
            setScreenColor(enColor::RED);
            return enWinner::Computer;
        case enChoices::Scissors:
            setScreenColor(enColor::GREEN);
            return enWinner::Player;
        }

    case enChoices::Paper:
        switch (RoundInfo.ComputerChoice)
        {
        case enChoices::Scissors:
            setScreenColor(enColor::RED);
            return enWinner::Computer;
        case enChoices::Rock:
            setScreenColor(enColor::GREEN);
            return enWinner::Player;
        }

    case enChoices::Scissors:
        switch (RoundInfo.ComputerChoice)
        {
        case enChoices::Rock:
            return enWinner::Computer;
        case enChoices::Paper:
            return enWinner::Player;
        }
    }
}

std::string getWinnerName(enWinner Winner)
{
    std::string arrWinnerName[3] = {"Computer", "Player", "NoWinner"};
    return arrWinnerName[Winner];
}

void printChoices(enChoices ComputerChoice, enChoices UserChoice)
{
    std::cout << "\n";
    std::cout << "Computer Choice is " << getChoice(ComputerChoice) << "\n";
    std::cout << "Player Choice is " << getChoice(UserChoice) << "\n\n";
}

void printRoundResults(stRoundInfo RoundInfo)
{
    std::cout << "\n";
    std::cout << "___________________Round Results___________________\n\n";
    std::cout << "Round Number: "<< RoundInfo.RoundNumber << "\n";
    printChoices(RoundInfo.ComputerChoice,RoundInfo.PlayerChoice);
    std::cout << "Round winner is " << RoundInfo.WinnerName << "\n";
    std::cout << "___________________________________________________\n\n";
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
    return PlayerWinTimes > ComputerWinTimes ? enWinner::Player :
    PlayerWinTimes < ComputerWinTimes ? enWinner::Computer:
    enWinner::Draw;
}

stGameResults playGame(short HowManyRounds)
{
    short ComputerWinTimes = 0, PlayserWinTimes = 0, DrawTimes = 0;
    stRoundInfo RoundInfo;
    for (short Round = 1; Round <= HowManyRounds; Round++)
    {
        RoundInfo.RoundNumber = Round;
        RoundInfo.ComputerChoice = getComputerChoice();
        RoundInfo.PlayerChoice = readUserChoice();
        RoundInfo.Winner = detectWinner(RoundInfo);
        RoundInfo.WinnerName = getWinnerName(RoundInfo.Winner);
        switch (RoundInfo.Winner)
        {
        case enWinner::Computer:
            ComputerWinTimes++;
            break;
        case enWinner::Player:
            PlayserWinTimes++;
            break;
        default:
            DrawTimes++;
            break;
        }
        printRoundResults(RoundInfo);
    }
    
    return {
        HowManyRounds,
        PlayserWinTimes,
        ComputerWinTimes,
        DrawTimes,
        WhoWonTheGame(PlayserWinTimes,ComputerWinTimes),
        getWinnerName(WhoWonTheGame(PlayserWinTimes,ComputerWinTimes))
    };
}

void showFinalResults(stGameResults GameResults)
{
    std::cout << "\n_____________________Game Results_____________________\n\n";
    std::cout << "Game Rounds: " << GameResults.Rounds << "\n";
    std::cout << "Computer Won " << GameResults.ComputerWinTimes << " times\n";
    std::cout << "Player Won " << GameResults.PlayserWinTimes << " times\n";
    std::cout << "Draw happened " << GameResults.DrawTimes << " times\n";
    std::cout << "Final Winner " << GameResults.WinnerName << "\n";
    std::cout << "\n_______________________________________________________\n\n";
}

void printGameOver()
{
    std::cout << "\n_____________________Game Over_____________________\n\n";
}

bool doPlayAgain()
{
    std::cout << "Do you want to Play Again?: \n";
    std::cout << "1) Yes\n";
    std::cout << "2) No\n";
    return readNumberInRange(2, 1, "Enter either 1 or 2: ") == 1 ? true : false;
}

void resetScreen()
{
    system("cls");
    system("color OF");
}

int main()
{
    srand((unsigned)time(NULL));
    stGameResults GameResults;
    showHelloMessage();
    showRules();
    while (true)
    {
        int HowManyRounds = readPositiveNumber("Enter the number of rounds to play: ");
        GameResults = playGame(HowManyRounds);
        printGameOver();
        showFinalResults(GameResults);
        // setWinnerScreen();
        if (!doPlayAgain())
            break;
    }
}