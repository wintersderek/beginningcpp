// This will ask the user 8 boolean questions and pack each answer into the 
// same unsigned char.  It will then unpack the char to show the values for
// each of the asked questions.

#include <iostream>
#include <string>
#include <bitset>

const std::string kQuestionOne {"Are you over 21?"};
const std::string kQuestionTwo {"Are you under 65?"};
const std::string kQuestionThree {"Do you like beer?"};
const std::string kQuestionFour {"Do you like cilantro?"};
const std::string kQuestionFive {"Do you like cheese?"};
const std::string kQuestionSix {"Do you like wine?"};
const std::string kQuestionSeven {"Do you like computers?"};
const std::string kQuestionEight {"Do you like sex?"};
const char NEW_LINE {'\n'};
const char YES_UPPER {'Y'};
const char YES_LOWER {'y'};
const char NO_UPPER {'N'};
const char NO_LOWER {'n'};

enum class Question
{
    QUESTION_ONE = 1 , QUESTION_TWO, QUESTION_THREE, QUESTION_FOUR, 
    QUESTION_FIVE, QUESTION_SIX, QUESTION_SEVEN, QUESTION_EIGHT
};

void DisplayQuestion(Question question)
{
    switch (question)
    {
    case Question::QUESTION_ONE:
        std::cout << kQuestionOne;
        break;
    case Question::QUESTION_TWO:
        std::cout << kQuestionTwo;
        break;
    case Question::QUESTION_THREE:
        std::cout << kQuestionThree;
        break;
    case Question::QUESTION_FOUR:
        std::cout << kQuestionFour;
        break;
    case Question::QUESTION_FIVE:
        std::cout << kQuestionFive;
        break;
    case Question::QUESTION_SIX:
        std::cout << kQuestionSix;
        break;
    case Question::QUESTION_SEVEN:
        std::cout << kQuestionSeven;
        break;
    case Question::QUESTION_EIGHT:
        std::cout << kQuestionEight;
        break;
    default:
        throw 500;
    }
}

bool AskQuestion(Question question)
{
    DisplayQuestion(question);
    char answer {0};
    std::cin >> answer;
    return (answer == YES_UPPER || answer == YES_LOWER)? true : false;
}

void PackBool(bool answer, unsigned char &current)
{
    current <<= 1;
    if (answer){
        current |= 1;
    } 
}

bool getPackedBool(Question question, unsigned char answers) {
    const unsigned char kTrue {0x01};
    answers >>= (8 - static_cast<int>(question));
    return static_cast<bool>(answers & kTrue);
}

void DisplayBits(unsigned char values)
{
    std::cout << "Current Bits: " << std::bitset<8>(values) << std::endl;
}

void DisplayAnswer(Question question, unsigned char answers){
    std::cout << "The answer to \'";
    DisplayQuestion(question);
    std::cout << "\' is: " << std::boolalpha 
              << getPackedBool(question, answers) << std::noboolalpha 
              << std::endl;
}

int main ()
{
    unsigned char answers {0};

    PackBool(AskQuestion(Question::QUESTION_ONE), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_TWO), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_THREE), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_FOUR), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_FIVE), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_SIX), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_SEVEN), answers);
    //DisplayBits(answers);
    
    PackBool(AskQuestion(Question::QUESTION_EIGHT), answers);
    //DisplayBits(answers);

    while (true){
        int answer_test {0};
        std::cout << "Enter question number to display answer (1-8) or 0 to quit: ";
        std::cin >> answer_test;
        if (answer_test == 0){
            break;
        }

        if (answer_test >= 1 && answer_test <= 8){
            DisplayAnswer(static_cast<Question>(answer_test), answers);
        }
    }

    return 0;
}