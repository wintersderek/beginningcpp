#ifndef CONTENTS_H
#define CONTENTS_H
#include <iostream>
#include <string>
#include <string_view>

class Contents
{
private:
    std::string content;

public:
    Contents(std::string_view c) : content {c} {}

    virtual ~Contents() = default;

    virtual std::string_view getContent() const { return content; }

    void printContent() const
    {
        std::cout << "Contents are: " << content << '\n';
    }
};

#endif