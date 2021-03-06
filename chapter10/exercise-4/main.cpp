/*
Exercise 1: create print_this, print_that, and print in 3 separate .cpp files
            with headers in 3 separate files.  The functions print_this and
            print_that should call the print function.
*/
#include <string>
#include "print_this.h"
#include "print_that.h"

int main ()
{
    constexpr const char* val_x {"This is the C string for this."};
    constexpr const char* val_y {"This is the C string for that."};
    std::string val_this {"This is the value for this."};
    std::string val_that {"This is the value for that."};

#ifdef DO_THIS
    print_this(val_x);
    print_this(val_this);
#else
    print_that(val_y);
    print_that(val_that);
#endif
    return 0;
}