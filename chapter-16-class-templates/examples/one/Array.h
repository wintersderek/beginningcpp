#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <memory>
#include <string>
#include <utility>

template <typename T>
class Array
{
protected:
    std::unique_ptr<T[]> elements;
    //T* elements;
    size_t size;
    
public:
    explicit Array(size_t array_size);
    Array(const Array& from);
    virtual ~Array() = default;

    T& operator[](size_t item);
    const T& operator[](size_t item) const;

    Array& operator=(const Array& right_hand);

    size_t getSize() const { return size; }

    void swap(Array& other) noexcept;
};

template <typename T> 
Array<T>::Array(size_t array_size) : 
    elements{std::make_unique<T[]>(array_size)}, size {array_size}
{
#ifdef DEBUG
    std::cout << "Array<T>::Array(size_t array_size)\n";
#endif
}

template <typename T>
Array<T>::Array(const Array& from) : Array {from.size}
{
#ifdef DEBUG
    std::cout << "Array<T>::Array(const Array& from)\n";
#endif
    for(size_t i {}; i < from.size; ++i)
    {
        elements[i] = from[i];
    }
}

template <typename T> T& Array<T>::operator[](size_t item)
{
#ifdef DEBUG
    std::cout << "T& Array<T>::operator[]\n";
#endif

    return const_cast<T&>(std::as_const(*this)[item]);
}

template <typename T> const T& Array<T>::operator[](size_t item) const 
{
#ifdef DEBUG
    std::cout << "const T& Array<T>::operator[]\n";
#endif

    if (item >= size)
    {
        throw std::out_of_range{"Index is out of range: " + std::to_string(item)};
    }
    return elements[item];
}

template <typename T> Array<T>& Array<T>::operator=(const Array& right_hand) 
{
    if (this != &right_hand)
    {
        Array<T> copy {right_hand};
        swap(copy);
    }

    return *this;
}

template <typename T> void Array<T>::swap(Array& other) noexcept
{
    std::swap(elements, other.elements);
    std::swap(size, other.size);
}

template <typename T> void swap(Array<T>& one, Array<T>& two)
{
    one.swap(two);
}

#endif