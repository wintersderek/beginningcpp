#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template <typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;

    // Constructors
    explicit Pair() = default;
    explicit Pair(const T1& f, const T2& s) : first {f}, second {s} {}
    ~Pair() = default;

    // Operators
    bool operator<(const Pair& rhs) const;
    bool operator==(const Pair& rhs) const;
    std::ostream& write(std::ostream& out) const;
};

template <typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair& rhs) const
{
    if (first == rhs.first)
    {
#ifdef DEBUG
        std::cout << second << " is less than " << rhs.second << " : "
                  << (second < rhs.second ? "true" : "false") << '\n';
#endif
        return second < rhs.second;
    }
    else
    {
#ifdef DEBUG
        std::cout << first << " is less than " << rhs.first << " : "
                  << (first < rhs.first ? "true" : "false") << '\n';
#endif
        return first < rhs.first;
    }
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator==(const Pair& rhs) const
{
    return (first == rhs.first) && (second == rhs.second);
}

template <typename T1, typename T2>
std::ostream& Pair<T1, T2>::write(std::ostream& out) const
{
    out << "Pair(" << first << ", " << second << ')';
    return out;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const Pair<T1, T2>& pair)
{
    pair.write(out);
    return out;
}
#endif