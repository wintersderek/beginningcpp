// Excercise 3-1
#include <iostream>
#include <iomanip>

int main () 
{
  int value {};
  std::cout << "Enter any integer: ";
  std::cin >> value;
  int inverted_value {~value};

  unsigned int hex_digits {2 * sizeof(int)};          // Hex digits in value
  unsigned int hex_value_width {hex_digits + 2};      // Add 2 for 0x prefix
  unsigned int column_width {hex_value_width + 4};    // Output column width (add 4 for padding)

  // Output column headings
  std::cout << std::right << std::setw(column_width) << "value"
    << std::setw(column_width) << "~value"
    << std::setw(column_width) << "~value+1" << std::endl;

  // Output hexadecimal values
  std::cout << std::hex << std::showbase << std::internal << std::setfill('0')
    << "    " << std::setw(hex_value_width) << value
    << "    " << std::setw(hex_value_width) << inverted_value
    << "    " << std::setw(hex_value_width) << inverted_value + 1 << std::endl;

  // Output decimal values
  std::cout << std::dec << std::right << std::setfill(' ')
    << std::setw(column_width) << value
    << std::setw(column_width) << inverted_value
    << std::setw(column_width) << inverted_value + 1 << std::endl;
    return 0;
}