#include <iostream>
#include <string>
#include <string_view>
#include "DoubleLinkedList.h"

/*
Print out a DoubleLinkedList<T>::Iterator
*/
template <typename T>
void printIterator(typename DoubleLinkedList<T>::Iterator& it, bool forward=true);

/*
Fill a DoubleLinkedList<T> with a string
*/
template <typename T> 
DoubleLinkedList<T>& fillList(DoubleLinkedList<T>& list, std::string_view content);

int main(int argc, char const *argv[])
{
    
    DoubleLinkedList<std::string> values {};
    values = fillList(values, "This is the text that I am going to use");

    std::cout << "Size: " << values.size() << '\n';
    std::cout << "Is Empty: " << values.empty() << '\n';
    
    auto it {values.get_forward_iterator()};
    printIterator<std::string>(it);

    it = values.get_backward_iterator();
    printIterator<std::string>(it, false);

    values.clear();
    std::cout << "Size: " << values.size() << '\n';
    std::cout << "Is Empty: " << values.empty() << '\n';

    std::cout << std::endl;
    return 0;
}

template <typename T>
void printIterator(typename DoubleLinkedList<T>::Iterator &it, bool forward)
{
    for (size_t i {}; it;)
    {
        std::cout << it.value() << ' ';
        if (++i % 5 == 0)
        {
            std::cout << '\n';
        }
        (forward) ? it.move_next() : it.move_previous();
    }
}

template <typename T>
DoubleLinkedList<T> &fillList(DoubleLinkedList<T> &list, std::string_view content)
{
    if (!content.empty())
    {
        size_t start = 0;
        size_t end = content.find_first_of(' ', start + 1);

        while (end != std::string::npos)
        {
            //std::cout << start << ' ' <<  content.substr(start, end) << ' ' << end << '\n';
            //std::string back_value {content.substr(start, end - 1)};
            list.push_back(static_cast<std::string>(content.substr(start, end - start)));
            start = end + 1;
            end = content.find_first_of(' ', start);
        }
        if (content.length() - 1 != ' ')
        {
            list.push_back(static_cast<std::string>(
                content.substr(start, content.length() - start)));
        }        
    }
    return list;
}