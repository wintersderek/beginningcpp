/*
Demonstrate the use of file output.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using name_list = std::vector<std::pair<std::string, unsigned int>>;

void add_record(const std::string& name, const int& age, std::ofstream& out);

std::pair<std::string, unsigned int> get_name(const std::string& line);

name_list read_records(std::ifstream& in_file);

int main ()
{
    int result {};
    char filename[] {"temp.data"};
    std::ofstream out_file {filename};

    if (!out_file)
    {
        //File is not open
        std::cerr << "Unable to open " << filename << std::endl;
        result = 1;
    }
    else
    {
        //File is open
        add_record("Imelda", 46, out_file);
        add_record("Derek", 48, out_file);
        add_record("Dani", 10, out_file);
        add_record("Emma", 2, out_file);
        add_record("Yessica", 42, out_file);

        out_file.close(); 
    }
    
    std::ifstream in_file {filename};
    if (!in_file)
    {
        //File could not be opened for input
        std::cerr << "Unable to open " << filename << " for input" 
                  << std::endl;
    }
    else
    {
        name_list records = read_records(in_file);
        std::cout << "==================\t\tFILE OUT\t\t===================\n";
        for (auto& name : records)
        {
            std::cout << std::left << std::setw(10) << name.first
                      << std::right << std::setw(5) << name.second << "\n";
        }
    }
    
    std::cout << std::endl;

    return result;
}

void add_record(const std::string& name, const int& age, std::ofstream& out)
{
    const char separator {','};
    const char escape_character {'"'};
    const char replacement[] {R"*(\")*"};

    out << escape_character << name << escape_character << separator
        << age << std::endl;
}

name_list read_records(std::ifstream& in_file)
{
    name_list result {}; 
    while (in_file)
    {
        std::string line {};
        std::getline(in_file, line);

        result.push_back(get_name(line));
    }

    return result;
}

std::pair<std::string, unsigned int> get_name(const std::string& line)
{
    std::pair<std::string, unsigned int> result;

    size_t start {line.find(',')};
    if (start != std::string::npos)
    {
        result.second = std::stoi(line.substr((start + 1), 
                                  (line.length() - (start + 1))));

        result.first = line.substr(0, start);
    }

    return result;
}