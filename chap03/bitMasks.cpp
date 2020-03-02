// Explore how to use bits as flags

#include <iostream>
#include <bitset>

int main() {
    unsigned short fontData {0x64c}; //0b0000 0110 0100 1100
    unsigned short testDoubleByte {0b0000'0000'0000'0011};
    unsigned short boldMask {0x20};
    unsigned short italicsMask {0x40};
    unsigned short sizeMask {0x1f};


    std::cout << "Double Bype: " << testDoubleByte << "\n\n";

    std::cout << "Size of fontData: " << sizeof(fontData) << "\n"
              << "Decimal Value of fontData: " << fontData << "\n";

    auto result {static_cast<unsigned short>(fontData << 2)};

    std::cout << "Size of result: " << sizeof(result) << "\n"
              << "Decimal Value of result: " << result << "\n"
              << "Binary value of result: " << std::bitset<16>(result) << "\n";

    // Font is set up as first 8 significat bits for style, 1 separator bit, 1 italic bit, 1 bold bit, and 5 bits for style.
    // Get the value of bold
    auto bold {static_cast<unsigned short>((fontData >> 5) & 1)};
    std::cout << "Bold: " << bold << "\n"
              << "Bold Binary: " << std::bitset<16>(bold) << "\n";

    // Get the value of italics
    auto italics {static_cast<unsigned short>(fontData >> 6 & 1)};
    std::cout << "Italics: " << italics << "\n"
              << "Italics Binary: " << std::bitset<16>(italics) << "\n";

    // Show the value of NOT bold and italics
    std::cout << "~ bold: " << (~bold & 1) << "\n"
              << "~ italics: " << (~italics & 1) << "\n";

    // Using masks to get Bold and Italics
    if ((boldMask & fontData) == boldMask){
        std::cout << "The font is bold!!!" << "\n";
    }else
    {
        std::cout << "The fond is not bold!!!" << "\n";
    }

    if ((italicsMask & fontData) == italicsMask)
    {
        std::cout << "The font is italics!!!" << "\n";
    }
    else
    {
        std::cout << "The font is not italics!!!" << "\n";
    }
    
    // Get the font size
    std::cout << "The font size is: " << (fontData & sizeMask) << "\n";

    // Turn bold & italics on
    std::cout << "TURN BOLD/ITALICS ON" << "\n";
    fontData |= boldMask | italicsMask;
    if (((italicsMask & fontData) == italicsMask) && ((boldMask & fontData) == boldMask))
    {
        std::cout << "The font is bold/italics!!!" << "\n";
    }
    else
    {
        //std::cout << std::bitset<16>(fontData) << "\n";
        //std::cout << std::bitset<16>(fontData & boldMask) << "\n";
        std::cout << std::bitset<16>(fontData) << "\n";
        std::cout << std::bitset<16>(italicsMask) << "\n";
        std::cout << std::bitset<16>(fontData & italicsMask) << "\n";
        std::cout << "The font is not bold/italics!!!" << "\n";
    }
    // Turn bold and italics off
    std::cout << "TURN BOLD/ITALICS OFF" << "\n";
    fontData &= ~boldMask & ~italicsMask;
    if (((italicsMask & fontData) != italicsMask && (boldMask & fontData) != boldMask))
    {
        std::cout << "The font is not bold/italics!!!" << "\n";
    }
    else
    {
        std::cout << "The font is bold/italics!!!" << "\n";
    }
    

    std::cout << std::endl;
    return 0;
}