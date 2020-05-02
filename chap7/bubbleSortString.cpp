//Bubble sort strings in a vector

#include <iostream>
#include <vector>
#include <string>

void add_names(std::vector<std::string>& names) {
    std::string name;

    do
    {
        std::cout << "Enter a name or # to quit:\n";
        std::getline(std::cin, name);

        if (name != "#")
            names.push_back(name);
    } while (name != "#");
    
    
}

void bubble_sort(std::vector<std::string>& names)
{
    bool sorted {false};

    while (!sorted)
    {
        sorted = true;

        for(size_t i {1}; i < names.size(); ++i)
        {
            if (names[i] < names[i -1])
            {
                names[i].swap(names[i -1]);
                sorted = false;
            }
        }
    }
}

int main () 
{
    std::vector<std::string> names {};
    add_names(names);
    bubble_sort(names);
    std::string name1 {"Derek"};
    std::string name2 {"Imelda"};

    for(auto& s : names)
    {
        std::cout << s << std::endl;
    }

    name1.swap(name2);
    std::cout << "Name1: " << name1 << "\tName2: " << name2 << std::endl;

    int val1 {10};
    int val2 {15};
    std::swap(val1, val2);
    std::cout << val1;
    return 0;
}