// Use the header <cctype> to demonsrate functionality
#include <iostream>

#include <iomanip>
#include <locale>

int main ()
{
    unsigned char inChar {0};
    unsigned char continueKey {0};

    while (inChar < 254)
    {
        //std::cout << "Enter a character: " << std::endl;
        //std::cin >> inChar;

        //if (inChar == 'q'){break;}
        std::cout << std::hex << std::showbase << std::setfill('0')
                  << std::internal << std::setw(8) 
                  << static_cast<unsigned int>(inChar)
                  << " - "
                  << static_cast<unsigned char>(inChar) << "\n";

        std::cout << std::boolalpha <<
            "isalnum(): " << static_cast<bool>(std::isalnum(inChar)) << "\n"
            "isalpha(): " << static_cast<bool>(std::isalpha(inChar)) << "\n"
            "islower(): " << static_cast<bool>(std::islower(inChar)) << "\n"
            "isupper(): " << static_cast<bool>(std::isupper(inChar)) << "\n"
            "isdigit(): " << static_cast<bool>(std::isdigit(inChar)) << "\n"
            "isxdigit(): " << static_cast<bool>(std::isxdigit(inChar)) << "\n"
            "iscntrl(): " << static_cast<bool>(std::iscntrl(inChar)) << "\n"
            "isgraph(): " << static_cast<bool>(std::isgraph(inChar)) << "\n"
            "isspace(): " << static_cast<bool>(std::isspace(inChar)) << "\n"
            "isblank(): " << static_cast<bool>(std::isblank(inChar)) << "\n"
            "isprint(): " << static_cast<bool>(std::isprint(inChar)) << "\n"
            "ispunct(): " << static_cast<bool>(std::ispunct(inChar)) << "\n"
            "tolower(): " << std::tolower(inChar) << " - " << static_cast<char>(std::tolower(inChar)) << "\n"
            "toupper(): " << std::toupper(inChar) << " - " << static_cast<char>(std::toupper(inChar)) << "\n";

        ++inChar;

        for (int i {0}; i < 100000000; i++){
            continue;
        }
    }

    std::cout << std::endl;
    

    return 0;
}