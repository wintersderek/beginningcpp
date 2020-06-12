/*
Define a function that determines if a number is prime.
    -
*/

#include <iostream>
#include <iomanip>
#include <vector>

using VST = std::vector<size_t>;

bool isPrime(size_t number);
void generateVector(VST& numbers, size_t end, size_t begin=1);
void findPrimes(VST& numbers, VST& found);
void printVST(VST& numbers);

int main ()
{
    size_t target {};
    std::cout << "Enter the target to find primes till: ";
    std::cin >> target;

    VST numbers {};
    generateVector(numbers, target);

    VST primes {};
    findPrimes(numbers, primes);


    printVST(primes);
    
    std::cout << std::endl;
    
    return 0;
}

void printVST(VST& numbers)
{
    for (size_t i {0}; i < numbers.size(); i++)
    {
        std::cout << std::setw(8) << numbers[i];

        if ((i + 1) % 10 == 0)
        {
            std::cout << "\n";
        }
    }
}

void findPrimes(VST& numbers, VST& found)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if(isPrime(numbers[i]))
            found.push_back(numbers[i]);
    }
}

void generateVector(VST& numbers, size_t end, size_t begin)
{
    for (size_t i {begin}; i <= end; i++)
    {
        numbers.push_back(i);
    }
}

bool isPrime(size_t number)
{
    bool result {false};

    if (number > 1)
    {
        result = true;

        if (number > 2)
        {
            if (number % 2 == 0)
            {
                result = false;
            }
            else
            {
                for (size_t i {3}; i < number; i += 2)
                {
                    if (number % i == 0)
                    {
                        result = false;
                        break;
                    }
                }
            }
        }
    }
    return result;
}