// Determine quarters, dimes, nickles and pennies for an amount of money
// that is not greater than $10.00
#include <iostream>

const double kQuarter {0.25};
const double kDime {0.10};
const double kNickle {0.05};
const double kPenny {0.01};

int main () {
    std::cout << "Enter an amount of money not greater than $10.00: ";
    double amount {0};
    std::cin >> amount;

    if (amount > 10 || amount < 0){
        std::cout << "\n\nError: you must enter an amount between 0 and "
                     "10.00.";
    } else {
        int quarter {static_cast<int>(amount / kQuarter)};
        double temp {amount - (quarter * kQuarter)};
        
        int dime {static_cast<int>(temp / kDime)};
        temp = temp - (dime * kDime);
        
        int nickle {static_cast<int>(temp / kNickle)};
        temp = temp - (nickle * kNickle);
        
        double penny {(temp / kPenny)};
        temp = temp - (penny * kPenny);
        
        std::cout << "\nThe amount " << amount << " is " << quarter 
                  << "quarter" << ((quarter > 1)? "s, ": ", ") << dime 
                  << "dime" << ((dime > 1)? "s, ": ", ") << nickle << "nickle" 
                  << ((nickle > 1)? "s, ": ", ") << penny 
                  << ((penny > 1)? "pennies.": "penny");
    }

    std::cout << std::endl;

    return 0;
}