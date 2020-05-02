//Demonstrate concatenation
#include <iostream>
#include <string>

int main () {
    std::string first;
    std::string second;

    std::cout << "Enter your first name: ";
    std::cin >> first;

    std::cout << "Enter your last name: ";
    std::cin >> second;

    std::string full_name {first + " " + second};

    std::cout << "Your name is: " << full_name << "\n"
              << "Length: " << full_name.length() << std::endl;
    
    full_name.append(" was here");
    std::cout << full_name << std::endl;

    full_name.append(10, '!');
    std::cout << full_name << std::endl;

    int age {};
    std::cout << "Enter you age: ";
    std::cin >> age;

    std::string sentance {"You are "};
    sentance += std::to_string(age);
    sentance += " old";

    std::cout << sentance << std::endl; 

    return 0;
}