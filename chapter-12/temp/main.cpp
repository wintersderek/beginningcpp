
#include <iostream>
#include "Word.h"

std::ostream& operator<<(std::ostream& stream, const Word& word);

int main()
{
    Word my_word {"Hello Derek"};

    std::cout << my_word << std::endl;
        
    return 0;
}

std::ostream& operator<<(std::ostream& stream, const Word& word)
{
    stream << word.getWord();
    return stream;
}