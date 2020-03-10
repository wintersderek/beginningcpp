// Demonstrate creating a file

#include <iostream>
#include <string>
#include <fstream>

int main () 
{
    std::string myfile {""};

    std::cout << "Enter file name: " << std::endl;
    std::cin >> myfile;

    std::cout << "File entered: " << myfile;

    std::ofstream MyFile(myfile);
    MyFile << "It's tricky working with C++ files.";
    MyFile.close();
    return 0;
}