/*
Exercise 8: enter numbers as a string concatenated together.  Parse and Sum
    - Enter arbitrary amount of number each terminated by enter
    - Concatenate each number to a string
    - Terminate entering numbers with the #
    - Parse the string, summing the numbers, average numbers also.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

void get_number_string(std::string* values);
bool is_valid_number(std::string number);

int main () 
{
    std::string number_string;
    
    get_number_string(&number_string);

    std::cout << "Number String: " << number_string << std::endl;

    char space {' '};
    size_t start {number_string.find_first_not_of(space)};

    if (start != std::string::npos)
    {
        unsigned int count {};
        double sum {};

        while (start != std::string::npos)
        {
            size_t end {number_string.find(space, (start + 1))};
            if (end == std::string::npos)
            {
                end = number_string.length();
            }

            sum += std::stod(number_string.substr(start, (end - start)));
            ++count;

            //start = number_string.find(space, (end + 1));
            start = number_string.find_first_not_of(space, (end + 1));
        }
        
        std::cout << std::left << std::setw(10) << "Sum" << std::right
                  << std::setw(10) << "Average" << "\n" << std::left
                  << std::setw(10) << sum << std::right << std::setw(10)
                  << (sum / count) << std::endl;
    }
    else
    {
        std::cout << "No numbers entered for sum & average." << std::endl;
    }
    
    return 0;
}

void get_number_string(std::string* values)
{
    // Build a string of numbers separated by space from user input
    while (true)
    {
        std::cout << "Enter a number: ";
        std::string value;
        std::getline(std::cin, value);

        // See if we should terminate asking for numbers
        if (value == "#")
        {
            break;
        }

        // Validate input is only a number
        if (is_valid_number(value))
        {
            *values += ' ';
            *values += value;
        }
        else
        {
            std::cout << value << " is not a valid number." << std::endl;
        }
        
    }
}

bool is_valid_number(std::string number)
{
    const char space {' '};
    const char period {'.'};
    bool result {false}; //Assume the value is invalid

    size_t start {number.find_first_not_of(space)};

    if (number.length() > 0 && start != std::string::npos)
    {
        size_t end {number.find_last_not_of(space)};
        if (end == std::string::npos)
        {
            // Want to test characters in the string like an array.
            end = (number.length() - 1);
        }
        
        bool has_fraction {false};
        result = true;

        for (size_t i = start; i <= end; i++)
        {
            if (number[i] == period)
            {
                if (has_fraction)
                {
                    // Error: a number can only have a single decimal place
                    result = false;
                    break;
                }
                has_fraction = true;
            }
            else
            {
                // Determine if value is numeric
                if (!std::isdigit(number[i]))
                {
                    result = false;
                    break;
                }
            }
        }
        
    }

    return result;
}