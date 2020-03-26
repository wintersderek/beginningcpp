// Count the whitespace characters in a line up to the first #
#include <iostream>

int main () {
    size_t max_size {1'000};
    char values[max_size] {};
    unsigned int count {};
    
    std::cout << "Enter a line of text: ";
    std::cin.getline(values, max_size);

    while(values[count] != '\0'){
        ++count;
    } 

    std::cout << "Characters Entered: " << count << std::endl;

    for(size_t i {0}, j {count -1}; i < count/2; ++i, --j) {
        char temp {values[i]};
        values[i] = values[j];
        values[j] = temp;
    }

    std::cout << "Backward: " << values <<  std::endl;

    return 0;
}