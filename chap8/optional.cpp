/*
Show the use of the C++17 feature std::optional<T>
*/

#include <optional>
#include <iostream>
#include <string_view>

std::optional<size_t> find_last(std::string_view text, char to_find, 
                                std::optional<size_t> back_index = 
                                    std::nullopt);

int main() 
{
    std::optional<size_t> i {};
    const char text[] {"Growing old is mandatory; growing up is optional."};

    auto result {find_last(text, 'a')};
    if (result)
        std::cout << "Found last 'a' at " << *result << "\n";

    result = find_last(text, 'b');
    if (result.has_value())
        std::cout << "Found last 'b' at " << result.value() << "\n";

    result = find_last(text, 'c', 10);
    if (result != std::nullopt)
        std::cout << "Found last 'c' at " << *result << "\n";
    return 0;
}

std::optional<size_t> find_last(std::string_view text, char to_find, 
                                std::optional<size_t> back_index)
{
    if (!text.empty())
    {
        // value_or() returns the value of optional or value if nullopt
        size_t index {back_index.value_or(text.length() - 1)};

        while (true)
        {
            if (text[index] == to_find)
            {
                return index;
            }

            if (index == 0)
            {
                return std::nullopt;
            }
            --index;
        }
    }
    else
    {
        return std::nullopt;
    }
    
}