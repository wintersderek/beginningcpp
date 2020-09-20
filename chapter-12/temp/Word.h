#ifndef HDI_WORD
#define HDI_WORD

#include <string>
#include <string_view>

class Word
{
private:
    std::string data;
public:
    Word(std::string_view word_data);
    ~Word();

    inline std::string_view getWord() const { return data; }
};

Word::Word(std::string_view word_data)
{
    data = word_data;
}

Word::~Word()
{
}

#endif