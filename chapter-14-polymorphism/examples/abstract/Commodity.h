#pragma once
#ifndef COMMODITY_H
#define COMMODITY_H
#include <string>
#include <string_view>

class Commodity
{
protected:
    std::string name;
    
    Commodity(std::string_view commodity_name) : name{commodity_name} {}

public:
    virtual ~Commodity() = default;

    virtual std::string getTradingMonths() const = 0;

    virtual std::string getName() const { return name; } 
};
#endif