#ifndef INT_FUNCTOR_H
#define INT_FUNCTOR_H

template <typename T>
class IntFunctor
{
private:
    unsigned count {};

public:
    explicit IntFunctor() = default;
    IntFunctor(const IntFunctor&) = delete;

    bool operator()(const T& x, const T& y);
    unsigned getCount() const { return count; }
    void reset() { count = 0; }
};

template <typename T>
bool IntFunctor<T>::operator()(const T& lhs, const T& rhs)
{
    ++count;
    return lhs < rhs;
}

#endif