/*
Verify user input of a valid integer range
    - It should accept a lower and upper bound
    - It should accept a Message for the prompt
    - It should continue to prompt until valid data is entered
    - The program should ask the user for their birthday (month, day,
      year).
    - Account for february 29 leap years
    - Display the output as Month dd, yyyy
*/
#include <iostream>
#include <string_view>
#include <string>

bool isValidLeapYear(int year);
int validate_input(int lower, int upper, std::string_view prompt);
int get_month();
int get_year();
int get_day(int month, int year);
void display_date(int month, int year, int day);

enum class Month {
    January = 1,
    February,
    March, 
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main ()
{
    int month {get_month()};
    int year {get_year()};
    int day {get_day(month, year)};

    display_date(month, year, day);
    std::cout << std::endl;
    return 0;
}

void display_date(int month, int year, int day)
{
    std::string month_text {};
    const char* months[] {"January", "February", "March", "April", "May",
                          "June", "July", "August", "September", "October",
                          "November", "December"};

    std::cout << "\n" << months[month - 1] << " " << day << ", " << year;
}

int get_day(int month, int year)
{
    std::string day_message {"Enter your birth day of month [1- "};
    int days {};

    // Get the valid range of values for day
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        days = (isValidLeapYear(year))? 29: 28;
        break;
    default:
        days = 31;
        break;
    }

    day_message += std::to_string(days);
    day_message += "]:";
    
    return validate_input(1, days, day_message);
}

int get_month()
{
    const char* month_message {"Enter your birth month [1-12]:"};
    const int lower {1};
    const int upper {12};
    return validate_input(lower, upper, month_message);
}

int get_year()
{
    const char* year_message {"Enter your birth year [1920 - 2020]:"};
    const int lower {1920};
    const int upper {2020};
    return validate_input(lower, upper, year_message);
}

int validate_input(int lower, int upper, std::string_view prompt)
{
    int result {};

    while (true)
    {
        std::cout << prompt << "\n";
        std::cin >> result;
        if (lower <= result && upper >= result)
        {
            break;
        }
    }
    return result;
}

bool isValidLeapYear(int year)
{
    return (year % 100 == 0) ?
                (year % 400 == 0) :
                    (year % 4 == 0);
}