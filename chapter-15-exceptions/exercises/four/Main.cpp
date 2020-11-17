#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include "CurveBall.h"
#include "NumberExceptions.h"

void readEvenNumber();
bool isNumeric(std::string_view input);


int main(int argc, char* argv[])
{
    while (true)
    {
        try
        {
            readEvenNumber();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Continue? [Y/n]: ";
            char input;
            std::cin >> input;
            std::cin.ignore();
            if (std::tolower(input) != 'y')
                break;
        }
    }
}

void readEvenNumber()
{
    static std::random_device rd;
    static std::mt19937_64 mt {rd()};
    static std::uniform_int_distribution<int> dist (0, 99);
    int returnNumber {};
    std::string line;
    std::cout << "Enter an even number: ";
    std::getline(std::cin, line, '\n');
    
    int rand_num {dist(mt)};

    if (rand_num < 25)
        throw CurveBall { "Something really odd happened in readEvenNumber(): " 
                          + std::to_string(rand_num)};

    try
    {
        returnNumber = std::stoi(line);
    }
    catch (std::invalid_argument e)
    {
        std::cout << "NAN: " << line << '\n';
        throw NotANumber{line};
    }

    if (returnNumber < 0)
        throw NegativeNumber{returnNumber};

    if (returnNumber % 2 != 0)
        throw OddNumber{returnNumber};
}