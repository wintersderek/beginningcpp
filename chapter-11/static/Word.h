/*
Define a word
*/
#ifndef HDI_WORD_CLASS
#define HDI_WORD_CLASS

#include <string>
#include <string_view>

class Word
{
private:
    const static Word referenceWord;
    static inline size_t objectCount {};
    //static size_t count;
    std::string _word;
    std::string _definition;
    bool _verb;

public:
    // Constructors
    Word(std::string_view word, std::string_view definition, bool verb);
    Word(std::string_view word, std::string_view definition);
    Word(const Word& x);

    // Destructors
    ~Word();

    // Getters/Setters
    inline std::string_view getWord() { return _word; }
    inline std::string_view getDefinition() { return _definition; }
    inline bool isVerb() { return _verb; }

    // Statics
    static size_t getWordCount() { return Word::objectCount; }
};

#endif