#ifndef DOUBLEARRAYRAII_H
#define DOUBLEARRAYRAII_H
#include <iostream>

class DoubleArrayRAII
{
protected:
    size_t size;
    double* doubles;

public:
    DoubleArrayRAII(size_t i) : size {i}, doubles {new double[i]} {}

    DoubleArrayRAII(const DoubleArrayRAII&) = delete;
    DoubleArrayRAII& operator=(const DoubleArrayRAII&) = delete;

    double& operator[](size_t i) noexcept { return doubles[i]; }
    const double& operator[](size_t i) const noexcept { return doubles[i]; }

    ~DoubleArrayRAII() 
    {
        std::cout << "Freeing memory...\n";
        delete[] doubles;
    }

    double *get() const noexcept { return doubles; }
    void fill() noexcept
    {
        for (size_t i{0}; i < size; ++i)
        {
            doubles[i] = i;
        }
    }

    // Give ownership of the resource to someone else.
    double* release() noexcept
    {
        double* returnValue = doubles;
        doubles = nullptr;
        return returnValue;
    }
};
#endif