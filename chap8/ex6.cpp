/*
Write a program that asks the user for a list of grades, and it then outputs
statistics about all the entered grades.
    - write a function that queries the user for grades.  It should stop asking
      for grades once the user enters a negative number.
    - write a function that sorts the grades entered
    - write a function that outputs the statistics of the grade list.  Each
      statistic should be its own function.
        - 5 highest grades (use same function to print the 5 as array)
        - 5 lowest grades (use same function to print the 5 as array)
        - average grade
        - median grade 
        - standard deviation and variance of the grades
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

std::vector<unsigned> get_grades();
void sort_grades(std::vector<unsigned> &grades);
void sort_grades(std::vector<unsigned> &grades, size_t start, size_t end);
void print_highest(const std::vector<unsigned> &grades);
void print_lowest(const std::vector<unsigned> &grades);
void print_array(const unsigned grades[], size_t count);
void print_average(const std::vector<unsigned> &grades);
void print_median(const std::vector<unsigned> &grades);
void print_standard_deviation(const std::vector<unsigned> &grades);
void print_grades(const std::vector<unsigned>& grades);

int main()
{
    std::vector<unsigned> grades{get_grades()};

    if (grades.size() > 0)
    {
        sort_grades(grades);
        //print_grades(grades);
        print_highest(grades);
        print_lowest(grades);
        print_average(grades);
        print_median(grades);
        print_standard_deviation(grades);
    }
    else
    {
        std::cout << "No grades were entered!";
    }

    std::cout << std::endl;
    return 0;
}

std::vector<unsigned> get_grades()
{
    std::vector<unsigned> result{};
    int value{};

    std::cout << "Enter a grade 0 to 100 or negative to stop entering:\n";

    do
    {
        std::cin >> value;
        if (value >= 0)
        {
            result.push_back(static_cast<unsigned>(value));
        }
    } while (value >= 0);

    return result;
}

void sort_grades(std::vector<unsigned> &grades)
{
    sort_grades(grades, 0, (grades.size() - 1));
}

void sort_grades(std::vector<unsigned> &grades, size_t start, size_t end)
{
    // Only sort for more than one item
    if (!(start < end))
    {
        return;
    }

    // Swap the first and the middle 
    std::swap(grades[start], grades[(start + end) / 2]);

    // Put all values less than start directly after start
    size_t current {start};
    for (size_t i {start + 1}; i <= end; i++)
    {
        if (grades[i] < grades[start])
        {
            std::swap(grades[++current], grades[i]);
        }
    }

    // Swap start and current to make all values less than start to be on
    // the left side of start.
    std::swap(grades[start], grades[current]);

    // Sort the set of values on the left
    if (current > start)
    {
        sort_grades(grades, start, (current-1));
    }

    // Sort the set of values on the right
    if (current < end)
    {
        sort_grades(grades, (current + 1), end);
    }
}

void print_highest(const std::vector<unsigned> &grades)
{
    // Create an array of 5
    const size_t size {5};
    unsigned values[size] {};

    // assign the 5 highest to the array
    for (size_t i {0}; i < size; ++i)
    {
        values[i] = grades[(grades.size() - 1) - i];

        if (static_cast<int>(grades.size() - 1 -i) <= 0)
        {
            break;
        }
    }
    
    // print array
    std::cout << "The top grades are:\n";
    print_array(values, size);
}

void print_lowest(const std::vector<unsigned> &grades)
{
    const size_t size {5};
    unsigned values[size] {};

    for (size_t i {0}; i < size; ++i)
    {
        values[i] = grades[i];
        if (i + 1 >= grades.size())
        {
            break;
        }
    }
    std::cout << "The bottom grades are:\n";
    print_array(values, size);
}

void print_array(const unsigned grades[], size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << std::setw(5) << grades[i];
    }
    std::cout << "\n";
}

void print_average(const std::vector<unsigned> &grades)
{
    int sum {};
    for(auto& g : grades)
    {
        sum += g;
    }
    std::cout << "Average: " << (sum / grades.size()) << "\n"; 
}

void print_median(const std::vector<unsigned> &grades)
{
    unsigned median {};

    if (grades.size() % 2 == 0)
    {
        // Median is the mean (average) of the two middle values.
        median = ( grades[((grades.size() / 2) - 1)] + 
                   grades[grades.size() / 2] ) / 2;
    }
    else
    {
        //Median is the middle when there are odd number of values.
        median = grades[((grades.size() / 2) + 1)];
    }
    
    

    
}

void print_standard_deviation(const std::vector<unsigned> &grades)
{
}

void print_grades(const std::vector<unsigned> &grades)
{
    for(auto& u : grades)
    {
        std::cout << u << "\n";
    }
}