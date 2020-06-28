#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main ()
{
    using namespace boost::lambda;
    using in = std::istream_iterator<int>;

    std::for_each(
        in(std::cin),
        in(),
        std::cout << (_1 * 3) << " "
    );
}