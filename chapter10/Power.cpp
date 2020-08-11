/*
Power definition
*/
template <typename T>
const T pi {3.1415926535897932385L};

double compute(double number, unsigned exponent)
{
    return exponent == 0? 1.0 : number * compute(number, exponent - 1);
}

double power(double number, int exponent)
{
    return exponent >= 0 ? 
        compute(static_cast<double>(number), static_cast<unsigned>(exponent)) : 
        1.0 / compute(static_cast<double>(number), static_cast<unsigned>(-exponent));
}
/*
template <typename T>
double power(T number, int exponent)
{
    return exponent >=0 ? 
        compute(static_cast<double>(number), static_cast<unsigned>(exponent)) :
        1.0 / compute(static_cast<double>(number), static_cast<unsigned>(-exponent));
}
*/