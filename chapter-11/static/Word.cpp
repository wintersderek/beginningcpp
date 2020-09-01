/*
Create member definitions for Word
*/
#include <iostream>
#include "Word.h"

const Word Word::referenceWord {"Word", "Definition", false};

Word::Word(std::string_view word, std::string_view definition, bool verb)
{
#ifdef HDI_DEBUG
    std::cout << "\tConstructor One Called" << std::endl;
#endif
    ++Word::objectCount;
    _word = std::string{word};
    _definition = std::string{definition};
    _verb = verb;
}

Word::Word(std::string_view word, std::string_view definition) : 
    Word(word, definition, false)
{
#ifdef HDI_DEBUG
    std::cout << "\tConstructor Two Called" << std::endl;
#endif
    // no extra code
}

Word::Word(const Word& x) : Word(x._word, x._definition, x._verb)
{
#ifdef HDI_DEBUG
    std::cout << "\t\tCopy constructor called" << std::endl;
#endif
}

Word::~Word()
{
#ifdef HDI_DEBUG
    std::cout << "Destructor called" << std::endl;
#endif
    --Word::objectCount;
}
