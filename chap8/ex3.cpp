/*
Write a function plus that will will add to values and return the sum.
    - create overload for int.
    - create overload for double.
    - create overload for string
*/

#include <iostream>
#include <string>
#include <string_view>
#include <optional>

using OSV = std::optional<std::string_view>;
int plus(int a, int b);
double plus(double a, double b);
std::string plus(std::string_view a, OSV b = std::nullopt);

int main ()
{
    const int n {plus(3, 4)};
    const double d {plus(3.2, 4.2)};
    const std::string s {plus("he", "llo")};
    const std::string s1 {plus("aaa")};
    const std::string s2 {plus("bbb")};
    const std::string s3 {plus(s1, s2)};
    //const auto d2 { plus(3, 4.2) };

    std::cout << "int: " << n << "\ndouble: " << d << "\ns: "
              << s << "\ns1: " << s1 << "\ns2: " << s2 << "\ns3: "
              << s3 << std::endl;
}

int plus (int a, int b)
{
    return a + b;
}

double plus (double a, double b)
{
    return a + b;
}

std::string plus (std::string_view a, OSV b)
{
    //std::string {a + b};
    return (b.has_value()) ? std::string {a} + std::string{b.value()} : 
                                std::string {a};
}