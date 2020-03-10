// Demonstrate use of conditional operator
#include <iostream>

enum class ValueRange {
    twenty, thirty, hundred, over
};

int main () {
    int value {0};
    ValueRange range {};
    std::cout << "Enter an integer: ";
    std::cin >> value;

    std::cout << "\n\n";

    range = (value <= 20) ? ValueRange::twenty :
            (value > 20 && value <= 30)? ValueRange::thirty :
            (value > 30 && value <= 100) ? ValueRange::hundred : 
                ValueRange::over;

    switch (range)
    {
    case ValueRange::twenty:
        std::cout << "Value less than or equal to 20.";
        break;
    case ValueRange::thirty:
        std::cout << "Value is greater than 20 and less than or equal to 30.";
        break;
    case ValueRange::hundred:
        std::cout << "Value is greater than 30 and less than or equal to 100.";
        break;
    case ValueRange::over:
        std::cout << "Value is over 100.";
        break;
    default:
        break;
    }

    std::cout << std::endl;

    return 0;
}