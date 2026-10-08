#include "../random.h"
#include "../NumberTheory.h"
#include "../input.h"
#include <cstdlib>
#include <ctime>
#include <string>
int EASY_MAX = 9;
int EASY_MIN = 1;
int HARD_MAX = 99;
int HARD_MIN = 10;
enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5
};
enum enQuestionLevel
{
    easy = 1,
    mid = 2,
    hard = 3,
    mix = 4
};
enum enPassOrFail
{
    pass,
    fail
};

struct stQuestion
{
    int Operand1, Operand2, Result;
    char Operator;
};

char getOperator(enOperationType QuestionType)
{
    switch (QuestionType)
    {
    case enOperationType::Add:
        return '+';
    case enOperationType::Sub:
        return '-';
    case enOperationType::Div:
        return '/';
    case enOperationType::Mul:
        return '*';
    default:
        return '+';
    }
    return '+';
}

void getQuestionResult(stQuestion &Operation)
{
    Operation.Result =
        (Operation.Operator == '+') ? Operation.Operand1 + Operation.Operand2 :
        (Operation.Operator == '-') ? Operation.Operand1 - Operation.Operand2 :
        (Operation.Operator == '*')   ? Operation.Operand1 * Operation.Operand2 :
        Operation.Operand1 / Operation.Operand2;
}

stQuestion generateEasyQ()
{
    stQuestion Operation;
    Operation.Operand1 = generateRandomNumberInRange(EASY_MAX, EASY_MIN);
    Operation.Operand2 = generateRandomNumberInRange(EASY_MAX, EASY_MIN);
    return Operation;
}

stQuestion generateMidQ()
{
    stQuestion Operation;
    Operation.Operand1 = generateRandomNumberInRange(HARD_MAX, HARD_MIN);
    Operation.Operand2 = generateRandomNumberInRange(EASY_MAX, EASY_MIN);
    return Operation;
}

stQuestion generateHardQ()
{
    stQuestion Operation;
    Operation.Operand1 = generateRandomNumberInRange(HARD_MAX, HARD_MIN);
    Operation.Operand2 = generateRandomNumberInRange(HARD_MAX, HARD_MIN);
    return Operation;
}

stQuestion getQ(enQuestionLevel QuestionLevel, enOperationType QuestionType)
{
    if (QuestionLevel == enQuestionLevel::mix)
        QuestionLevel = (enQuestionLevel)generateRandomNumberInRange(3, 1);
    if (QuestionType == enOperationType::Mix)
        QuestionType = (enOperationType)generateRandomNumberInRange(4, 1);
    stQuestion Operation;
    switch (QuestionLevel)
    {
    case enQuestionLevel::easy:
        Operation = generateEasyQ();
        break;
    case enQuestionLevel::mid:
        Operation = generateMidQ();
        break;
    case enQuestionLevel::hard:
        Operation = generateHardQ();
        break;
    default:
        Operation = generateEasyQ();
        break;
    }

    Operation.Operator = getOperator(QuestionType);
    getQuestionResult(Operation);
    return Operation;
}

void generateQuestion(stQuestion &Operation)
{
    std::cout << Operation.Operand1;
    std::cout << Operation.Operator << "\n";
    std::cout << Operation.Operand2 << "\n";
    std::cout << "______________\n";
}

int readUserAnswer()
{
    int UserResult;
    while (true)
    {
        std::cout << "Enter Result: ";
        std::cin >> UserResult;
        if (!std::cin.fail())
            return UserResult;
        std::cout << "Invalid Input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void generateQuestions(int TotalNumberOfQuestion, enQuestionLevel QuestionLevel, enOperationType QuestionType, int &NumberOfCorrectAns, int &NumberOfWrongAns)
{
    stQuestion Operation;
    int UserResult;
    for (int QuestionNumber = 0; QuestionNumber < TotalNumberOfQuestion; QuestionNumber++)
    {
        std::cout << "Question [" + std::to_string(QuestionNumber) + "/" + std::to_string(TotalNumberOfQuestion) + "]\n";
        std::cout << "______________\n";
        Operation = getQ(QuestionLevel, QuestionType);
        generateQuestion(Operation);
        UserResult = readUserAnswer();
        if (UserResult == Operation.Result)
        {
            NumberOfCorrectAns++;
            std::cout << "\033[42mCorrect\033[0m\n";
            
            
        }
        else
        {
            NumberOfWrongAns++;
            std::cout << "\a\033[1;31mWrong\033[0m\n";
        }
    }
}

enPassOrFail doPass(int NumberOfCorrectAnswers, int NumberOfWrongAnswers)
{
    return ((NumberOfCorrectAnswers > NumberOfWrongAnswers) ? enPassOrFail::pass : enPassOrFail::fail);
}

void printResult(enPassOrFail PassOrFail)
{
    PassOrFail == enPassOrFail::pass ? std::cout << "Passed\n" : std::cout << "Failed\n";
}

bool playAgain()
{
    bool PlayAgain;
    PlayAgain = readNumberInRange(1,0, "Do you want to play again?(1: yes, 0: no): ");
    return (bool) PlayAgain;
}

void playMathGame()
{
    int HowManyQuestions = readPositiveNumber("How Many Questions Do You Want To Answer? ");
    int QuestionLevel = readNumberInRange(4, 1, "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ");
    int QuestionType = readNumberInRange(5, 1, "Enter Question Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ");
    int NumberOfCorrectAns = 0, NumberOfWrongAns = 0;
    generateQuestions(HowManyQuestions, (enQuestionLevel)QuestionLevel, (enOperationType)QuestionType, NumberOfCorrectAns, NumberOfWrongAns);
    printResult(doPass(NumberOfCorrectAns, NumberOfWrongAns));
}


void startGame()
{
    do {
        system("clear");
        playMathGame();
    }while(playAgain());
}

int main()
{
    srand((unsigned)time(NULL));
    startGame();
}