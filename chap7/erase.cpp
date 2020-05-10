//Demonstrate the use of std::string.erase()

#include <iostream>
#include <string>

int main ()
{
    std::string entered_text;
    std::cout << "Enter the text to manipulate:\n";
    std::getline(std::cin, entered_text);

    size_t start {};
    std::cout << "Enter the starting index to erase: ";
    std::cin >> start;
    if (start > entered_text.length())
    {
        start = entered_text.length() - 1;
    }

    size_t count {};
    std::cout << "Enter number of characters to remove: ";
    std::cin >> count;

    if ((start + count) > entered_text.length()) 
    {
        count = entered_text.length() - start;
    }


    entered_text.erase(15);
    std::cout << "Removed Text: " << entered_text << std::endl;

    entered_text.erase(start, count);
    std::cout << "Removed Text: " << entered_text << std::endl;

    return 0;
}