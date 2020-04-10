// Demonstrate using the std::unique_ptr<T>

#include <iostream>
#include <memory>
#include <iomanip>

int main () {
    std::cout << std::left;
    std::unique_ptr<int> p_int {std::make_unique<int>(25)};
    auto pvalue {std::make_unique<double>(99.56)};
    std::cout << std::setw(18) << "Value: " << *p_int << "\n"
              << std::setw(18) << "Address: " 
              << std::hex << std::showbase << p_int.get() << "\n"
              << std::setw(18) << "Value Two: " 
              << std::dec  << *pvalue << "\n"
              << std::setw(18) << "Address Two: " 
              << std::hex << std::showbase << pvalue.get() << std::endl;

    auto pv = pvalue.get();
    std::cout << std::setw(18) << ".get() Address: " << pv << "\n"
              << std::setw(18) << ".get() Value: " 
              << std::dec << *pv << std::endl;

    
    auto* ptemp = pvalue.release();
    std::cout << std::setw(18) << "Released Value: " << *ptemp << "\n"
              << std::setw(18) << "Released Address: " 
              << std::hex << std::showbase  << ptemp << std::endl;
    delete ptemp;

    return 0;
}