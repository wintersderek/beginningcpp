/*
Uses std::string and std::vector to parse words of a file
    - should read a file name from the command line
    - should open the file for reading
    - should read each line of the file and parse it into words
    - should close the file
    - should display the result of the parse
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ifstream open_parse_file();

int main () 
{

    // Get the file
    std::ifstream file {open_parse_file()};
    std::vector<std::pair<std::string, unsigned>> words {};

    // while not eof
    while (!file.eof())
    {
        std::string line {};

        //read line
        std::getline(file, line);

        std::cout << "Line: \n\t" << line << "\n";


        // parse line
    }

    // close file
    if (file.is_open())
    {
        file.close();
    }

    // display results

    std::cout << std::endl;

    return 0;
}

std::ifstream open_parse_file()
{
    //"../../data/moby_dick.txt"
}