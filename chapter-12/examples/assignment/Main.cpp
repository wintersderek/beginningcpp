#include <iostream>
#include "Message.h"

int main()
{
    Message message;
    Message beware {"Careful"};
    message = beware;
    Message warning {beware};
    
    return EXIT_SUCCESS;
}