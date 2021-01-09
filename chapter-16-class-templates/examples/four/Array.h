#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>

template <typename T, int startIndex>
class Array
{
    //static_assert(std::is_default_constructible_v<T>, "T must be default constructable.");

protected:
    std::unique_ptr<T[]> elements;
    //T* elements;
    size_t size;
    
public:
    explicit Array(size_t array_size);
    Array(const Array& from);
    virtual ~Array() = default;

    T& operator[](int item);
    const T& operator[](int item) const;

    Array& operator=(const Array& right_hand);

    size_t getSize() const { return size; }

    void swap(Array& other) noexcept;
};

template <typename T, int startIndex> 
Array<T, startIndex>::Array(size_t array_size) : 
    elements{std::make_unique<T[]>(array_size)}, size {array_size}
{
#ifdef DEBUG
    std::cout << "Array<T>::Array(size_t array_size)\n";
#endif
}

template <typename T, int startIndex>
Array<T, startIndex>::Array(const Array& from) : Array {from.size}
{
#ifdef DEBUG
    std::cout << "Array<T>::Array(const Array& from)\n";
#endif
    for(size_t i {}; i < from.size; ++i)
    {
        elements[i] = from[i];
    }
}

template <typename T, int startIndex> 
T& Array<T, startIndex>::operator[](int item)
{
#ifdef DEBUG
    std::cout << "T& Array<T>::operator[]\n";
#endif

    return const_cast<T&>(std::as_const(*this)[item]);
}

template <typename T, int startIndex> 
const T& Array<T, startIndex>::operator[](int item) const 
{
#ifdef DEBUG
    std::cout << "const T& Array<T>::operator[]\n";
#endif
    if (item < startIndex)
    {
        throw std::out_of_range{"Index is too small: " + std::to_string(item)};
    }

    if (item > (startIndex + static_cast<int>(size) - 1))
    {
        throw std::out_of_range{"Index is too big: " + std::to_string(item)};
    }

    return elements[item - startIndex];
}

template <typename T, int startIndex> 
Array<T, startIndex>& Array<T, startIndex>::operator=(const Array& right_hand) 
{
    if (this != &right_hand)
    {
        Array<T, startIndex> copy {right_hand};
        swap(copy);
    }

    return *this;
}

template <typename T, int startIndex> 
void Array<T, startIndex>::swap(Array& other) noexcept
{
    std::swap(elements, other.elements);
    std::swap(size, other.size);
}

template <typename T, int startIndex> 
void swap(Array<T, startIndex>& one, Array<T, startIndex>& two)
{
    one.swap(two);
}

#endif