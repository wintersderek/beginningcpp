#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

template <typename T>
class Array 
{
private:
    std::unique_ptr<T[]> items;
    size_t size {};

public:
    /*****                          Constructors                         *****/
    explicit Array() : size {0} {}
    explicit Array(size_t item_number) : 
        items {std::make_unique<T[]>(item_number)},
        size {item_number} {}
    Array(const Array& from);

    /*****                          Destructors                          *****/
    ~Array() = default;

    /*****                          Operator Overloads                   *****/
    const T &operator[](size_t index) const;
    T& operator [](size_t index);
    Array& operator=(const Array& rhs);
    
    /*****                          Behavior                             *****/
    size_t getSize() const { return size; }
    void swap(Array& other) noexcept;
    void push_back(const T& item);
};

template <typename T>
Array<T>::Array(const Array& from) : Array {from.size}
{
    for (size_t i {}; i < size; ++i)
    {
        items[i] = from.items[i];
    }
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index > size - 1)
    {
        throw std::out_of_range("Index is too large: " + std::to_string(index));
    }
    return items[index];
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    return const_cast<T&>(std::as_const(*this)[index]);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if (&rhs != this)
    {
        // perform copy and swap idiom
        Array<T> copy {rhs};
        swap(copy);
    }
    return *this;
}

template <typename T>
void Array<T>::swap(Array& other) noexcept
{
    std::swap(items, other.items);
    std::swap(size, other.size);
}

template <typename T>
void Array<T>:: push_back(const T& item)
{
    // This uses the copy and swap idiom on the internal items array.
    // Create a new array that is one bigger than this->items
    std::unique_ptr<T[]> copy {std::make_unique<T[]>(size+1)};
    // Fill the array
    for(size_t i {}; i < size; ++i)
    {
        copy[i] = items[i];
    }
    // Add the new item to the copy
    copy[size] = item;
    // Increase the size of the this->size by one
    ++ size;
    // replace current this->items with copy
    std::swap(copy, this->items);
}

#ifdef DBG_EXPLICIT
template class Array<int>;
#endif

#endif