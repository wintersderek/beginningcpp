#ifndef DOUBLEARRAYRAII_H
#define DOUBLEARRAYRAII_H
#include <iostream>

class DoubleArrayRAII
{
protected:
    size_t size;
    size_t max_index;
    double* doubles;

public:
    DoubleArrayRAII(size_t i) : 
        size {i}, max_index {i - 1}, doubles {new double[i]} {}

    DoubleArrayRAII(const DoubleArrayRAII&) = delete;
    DoubleArrayRAII& operator=(const DoubleArrayRAII&) = delete;

    ~DoubleArrayRAII();

    double &operator[](size_t i);
    const double &operator[](size_t i) const;

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