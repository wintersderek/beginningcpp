// Ask user for products, and then output products
#include <iomanip>
#include <iostream>
#include <vector>
#include <cctype>

int main () {
    const size_t max_length {100};
    char answer {};
    std::vector<unsigned> ids;
    std::vector<unsigned> quantities;
    std::vector<float> prices;

    // Get all the products from the user
    do {
        unsigned id {};
        unsigned quantity {};
        float price {};

        std::cout << "Enter the ID: ";
        std::cin >> id;
        ids.push_back(id);

        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        quantities.push_back(quantity);

        std::cout << "Enter price: ";
        std::cin >> price;
        prices.push_back(price);

        std::cout << "Do you want to enter another product (Y/n)?";
        std::cin >> answer;
    } while (std::tolower(answer) == 'y');

    // Print the header line
    std::cout << std::setw(14) << std::left << "ID"
              << std::setw(11) << "Quantity"
              << std::setw(14) << "Unit Price"
              << std::setw(10) << "Cost"
              << "\n"
              << std::setw(14) << "----------"
              << std::setw(11) << "-------"
              << std::setw(14) << "----------"
              << std::setw(10) << "----------" << std::endl;
              
    // Print user output with sum
    float sum {};
    for (size_t i {0}; i < ids.size(); ++i) {
        std::cout << std::setw(14) << ids[i]
                  << std::setw(11) << quantities[i]
                  << "$" << std::setw(13) << prices[i]
                  << "$" << std::setw(9) << (quantities[i] * prices[i])
                  << "\n";
        sum += (quantities[i] * prices[i]);
    }

    std::cout << std::setw(14) << " "
              << std::setw(11) << " "
              << std::setw(14) << " "
              << "$" << std::setw(9) << sum
              << std::endl;

    return 0;
}