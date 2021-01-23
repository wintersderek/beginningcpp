#ifndef ARRAY_H
#define ARRAY_H

#ifdef DEBUG
#include <iostream>
#endif

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

template <typename T>
class Array
{
private:
    std::unique_ptr<T[]> elements;
    size_t size; // Number of array elements

    void copyElements(const Array& to_copy);

public:
    explicit Array(size_t arraySize=0);              // Constructor
    Array(const Array &array);                       // Copy constructor
    Array(Array&& moved);                            // Move constructor
    ~Array();                                        // Destructor
    Array &operator=(const Array &rhs);              // Copy assignment operator
    Array& operator=(Array&& rhs);                   // MOve assignment operator
    T &operator[](size_t index);                     // Subscript operator
    const T &operator[](size_t index) const;         // Subscript operator-const arrays
    size_t getSize() const noexcept { return size; } // Accessor for size
    void swap(Array &other) noexcept;                // noexcept swap function
    //void push_back(const T& item);                   // push_back function
    //void push_back(T&& item);                        // push_back move function
    void push_back(T item);
};

template <typename T>
Array<T>::Array(size_t arraySize) : 
    elements {std::make_unique<T[]>(arraySize)}, 
    size {arraySize} 
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T> Constructor\n";
#endif
}

template <typename T>
Array<T>::Array(const Array& array) : 
    elements {std::make_unique<T[]>(array.getSize())},
    size {array.getSize()}
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T> Copy Constructor\n";
#endif
    // Need to copy each one of the values from array into this->elements[x]
    copyElements(array);
}

template <typename T>
Array<T>::Array(Array&& moved) : 
    size {moved.size}
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T> Move Constructor\n";
#endif
    elements = std::move(moved.elements);
}

template <typename T>
Array<T>::~Array()
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T> Destructor\n";
#endif
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T> Assignment Operator\n";
#endif
    if (this != &rhs)
    {
        Array<T> copy {rhs};
        swap(copy);
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs)
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T> Move Assignment Operator\n";
#endif
    if (this != &rhs)       // Always check for self assignment
    {
        elements.reset();
        size = rhs.size;
        elements = std::move(rhs.elements);
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    return const_cast<T&>(std::as_const(*this)[index]);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("The array does not have an index " + 
            std::to_string(index));
    }
    return elements[index];
}


template <typename T>
void Array<T>::copyElements(const Array<T>& to_copy)
{
    for (size_t i {}; i < to_copy.getSize(); ++i)
    {
        elements[i] = std::move(to_copy[i]);
    }
}

template <typename T>
void Array<T>::swap(Array<T>& other) noexcept
{
    std::swap(elements, other.elements);
    std::swap(size, other.size);
}

template <typename T>
void swap(Array<T>& first, Array<T>& second) noexcept
{
    if (&first != &second)
    {
        first.swap(second);
    }
}

/*
template <typename T>
void Array<T>::push_back(const T& item)
{
#ifdef DEBUG 
    std::cout << "{DEBUG}\t\tArray<T>::push_back copy\n";
#endif
    Array<T> newArray {size + 1};
    for (size_t i {}; i < size; ++i)
    {
        newArray[i] = std::move(elements[i]);
    }
    newArray[size] = item;
    swap(newArray);
}

template <typename T>
void Array<T>::push_back(T&& item)
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T>::push_back Move\n";
#endif
    Array<T> newArray {size + 1};
    for (size_t i {}; i < size; ++i)
    {
        newArray[i] = std::move(elements[i]);
    }
    newArray[size] = std::move(item);
    swap(newArray);
}
*/

template <typename T>
void Array<T>::push_back(T item)
{
#ifdef DEBUG
    std::cout << "{DEBUG}\t\tArray<T>::push_back by-value\n";
#endif
    Array<T> newArray{size + 1};
    for (size_t i{}; i < size; ++i)
    {
        newArray[i] = std::move(elements[i]);
    }
    newArray[size] = std::move(item);
    swap(newArray);
}
#endif