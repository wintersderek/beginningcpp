// Demonstrate the use of creating a file
#include <iostream>
#include <fstream>

int main ()
{
    std::ofstream myFile;
    myFile.open("test.txt");
    myFile << "Yessica" << std::endl;
    myFile << "Tom" << std::endl;
}
