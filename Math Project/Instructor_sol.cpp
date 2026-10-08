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

void printResult(enPassOrFail PassOrFail)
{
    PassOrFail == enPassOrFail::pass ? std::cout << "Passed\n" : std::cout << "Failed\n";
}

struct stQuestion
{
    int Operand1, Operand2, Result;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer;
    int PlayerAnswer;
    bool AnswerResult;
};

struct stQuiz
{
    short NumberOfQuesions;
    stQuestion* QuestionList;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    short NumberOfRightAnswers = 0;
    short NumberOfWronAnswers = 0;
    bool isPass;
    stQuiz (short NumberOfQuesions, enOperationType OperationType, enQuestionLevel QuestionLevel)
    {
        this->NumberOfQuesions = NumberOfQuesions;
        this-> OperationType = OperationType;
        this->QuestionLevel = QuestionLevel;
        QuestionList = new stQuestion[NumberOfQuesions];
    }

    stQuiz(const stQuiz &other)
    {
        NumberOfQuesions = other.NumberOfQuesions;
        OperationType = other.OperationType;
        QuestionLevel = other.QuestionLevel;
        QuestionList = new stQuestion[NumberOfQuesions];
        NumberOfRightAnswers = other.NumberOfRightAnswers;
        NumberOfWronAnswers = other.NumberOfWronAnswers;
        isPass = other.isPass;

        for (short i = 0; i < NumberOfQuesions; i++)
            QuestionList[i] = other.QuestionList[i];
        
    }

  stQuiz& operator=(const stQuiz& other)
{
    if (this == &other) return *this;

    delete[] QuestionList;

    NumberOfQuesions      = other.NumberOfQuesions;
    OperationType         = other.OperationType;
    QuestionLevel         = other.QuestionLevel;
    NumberOfRightAnswers  = other.NumberOfRightAnswers;
    NumberOfWronAnswers   = other.NumberOfWronAnswers;
    isPass                = other.isPass;

    QuestionList = new stQuestion[NumberOfQuesions];
    for (short i = 0; i < NumberOfQuesions; i++)
        QuestionList[i] = other.QuestionList[i];

    return *this;
}

    ~stQuiz()
    {
        delete[] QuestionList;
    }

};

void getQuestionResult(stQuestion &Operation)
{
    Operation.CorrectAnswer =
        (Operation.OperationType == enOperationType::Sub) ? Operation.Operand1 - Operation.Operand2 :
        (Operation.OperationType == enOperationType::Mul) ? Operation.Operand1 * Operation.Operand2 :
        (Operation.OperationType == enOperationType::Div) ? Operation.Operand1 / Operation.Operand2 :
        Operation.Operand1 + Operation.Operand2;
}

void generateEasyQ(stQuestion& Operation)
{
    Operation.Operand1 = generateRandomNumberInRange(EASY_MAX, EASY_MIN);
    Operation.Operand2 = generateRandomNumberInRange(EASY_MAX, EASY_MIN);
}

void generateMidQ(stQuestion& Operation)
{
    Operation.Operand1 = generateRandomNumberInRange(HARD_MAX, HARD_MIN);
    Operation.Operand2 = generateRandomNumberInRange(EASY_MAX, EASY_MIN);
}

void generateHardQ(stQuestion& Operation)
{
    Operation.Operand1 = generateRandomNumberInRange(HARD_MAX, HARD_MIN);
    Operation.Operand2 = generateRandomNumberInRange(HARD_MAX, HARD_MIN);
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

stQuestion generateQuestion(enQuestionLevel QuestionLevel,enOperationType OperationType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::mix)
        QuestionLevel = (enQuestionLevel)generateRandomNumberInRange(3, 1);
    if (OperationType == enOperationType::Mix)
        OperationType = (enOperationType)generateRandomNumberInRange(4, 1);

    switch (QuestionLevel)
    {
    case enQuestionLevel::easy:
        generateEasyQ(Question);
        break;
    case enQuestionLevel::mid:
        generateMidQ(Question);
        break;
    case enQuestionLevel::hard:
        generateHardQ(Question);
        break;
    default:
        generateEasyQ(Question);
        break;
    }

    Question.OperationType = OperationType;
    getQuestionResult(Question);
    return Question;
}

void generateQuizQuestions(stQuiz& Quiz)
{
    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuesions; QuestionNumber++)
    {
        Quiz.QuestionList[QuestionNumber] = generateQuestion(Quiz.QuestionLevel, Quiz.OperationType);
    }
}

std::string getOperator(enOperationType QuestionType)
{
    switch (QuestionType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Div:
        return "/";
    case enOperationType::Mul:
        return "*";
    default:
        return "Mix";
    }
}

void AskQuesion(stQuiz Quiz,int QuestionNumber)
{
    stQuestion Question = Quiz.QuestionList[QuestionNumber];
    std::cout << "Question [" + std::to_string(QuestionNumber) + "/" + std::to_string(Quiz.NumberOfQuesions) + "]\n";
    std::cout << "______________\n";
    std::cout << Question.Operand1;
    std::cout << getOperator(Question.OperationType) << "\n";
    std::cout << Question.Operand2 << "\n";
    std::cout << "______________\n";
}

void correctQuestionAnswer(stQuiz &Quiz,int QuestionNumber)
{
    stQuestion Question = Quiz.QuestionList[QuestionNumber];
    Question.AnswerResult = Quiz.QuestionList[QuestionNumber].CorrectAnswer == Quiz.QuestionList[QuestionNumber].PlayerAnswer;
    if (Question.AnswerResult)
    {
        Quiz.NumberOfRightAnswers++;
        std::cout << "\033[42mCorrect\033[0m\n";
    }
    else
    {
        Quiz.NumberOfWronAnswers++;
        std::cout << "\a\033[1;31mWrong\033[0m\n";
        std::cout << "The Right Answer = ";
        std::cout << Question.CorrectAnswer << "\n";
    }
}

void AskAndCorrectQuesionListAnswers(stQuiz& Quiz)
{
    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuesions; QuestionNumber++)
    {
        AskQuesion(Quiz,QuestionNumber);
        Quiz.QuestionList[QuestionNumber].PlayerAnswer = readUserAnswer();
        correctQuestionAnswer(Quiz,QuestionNumber);
    }
    Quiz.isPass = Quiz.NumberOfRightAnswers >= Quiz.NumberOfWronAnswers; 
}

std::string getFinalResultText(bool isPass)
{
    return isPass? "PASS :-" : "Fail :-(";
}
std::string getQuestionLevelText(enQuestionLevel QuestionLevel)
{
    std::string arrQuestionLevelText[4] = {"Easy", "Mid", "Hard","Mix"};
    return arrQuestionLevelText[QuestionLevel -1];
}
void printQuizResult(stQuiz Quiz)
{
    std::cout << "\n";
    std::cout << "_________________" << "\n";
    std::cout << "Final Results is " << getFinalResultText(Quiz.isPass);
    std::cout << "\n_________________" << "\n";
    std::cout << "Number Of Questions " << Quiz.NumberOfQuesions << "\n";
    std::cout << "Question Level = " << getQuestionLevelText(Quiz.QuestionLevel) << "\n";
    std::cout << "Operation Type = " << getOperator(Quiz.OperationType) << "\n";
    std::cout << "Number of Right Answers = " << Quiz.NumberOfRightAnswers << "\n";
    std::cout << "Number of Wrong Answers = " << Quiz.NumberOfWronAnswers << "\n";
    std::cout << "\n_________________" << "\n";
}

bool playAgain()
{
    bool PlayAgain;
    PlayAgain = readNumberInRange(1,0, "Do you want to play again?(1: yes, 0: no): ");
    return (bool) PlayAgain;
}

void playMathGame()
{
    
    int NumberOfQuesions = readPositiveNumber("How Many Questions Do You Want To Answer? ");
    enQuestionLevel QuestionLevel = (enQuestionLevel)readNumberInRange(4, 1, "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ");
    enOperationType OperationType = (enOperationType)readNumberInRange(5, 1, "Enter Question Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ");
    stQuiz Quiz(NumberOfQuesions, OperationType, QuestionLevel);
    
    generateQuizQuestions(Quiz);
    AskAndCorrectQuesionListAnswers(Quiz);
    printQuizResult(Quiz);
    delete[] Quiz.QuestionList;
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