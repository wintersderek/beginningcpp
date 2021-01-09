#ifndef SPARSE_ARRAY_H
#define SPARSE_ARRAY_H

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

/* This sparse array should probably be implemented as a map. */
template <typename T>
class SparseArray
{
private:
    std::vector<std::pair<size_t, T>> sparse;

public:
    explicit SparseArray() = default;
    SparseArray(const SparseArray& from);
    ~SparseArray() = default;

    // Operators
    T& operator[](size_t index);

    // Behavior
    const T& at(size_t index) const;
    T& at(size_t index);

    const T* find(size_t index) const;
    T* find(size_t index);
    bool element_exists_at(size_t index) const;
};

template <typename T>
SparseArray<T>::SparseArray(const SparseArray<T>& from)
{
    for (size_t i {}; i < from.sparse.size(); ++i)
    {
        sparse.push_back(from.sparse[i]);
    }
}

template <typename T>
T& SparseArray<T>::operator[](size_t index)
{
    T* item {find(index)};
    if (item != nullptr)
    {
        return *item;
    }
    sparse.push_back(std::pair<size_t, T>{index, T{}});
    return sparse.back().second;
}

template <typename T>
const T& SparseArray<T>::at(size_t index) const
{
    T* item {find(index)};
    if (item)
    {
        return *item;
    }
    throw std::out_of_range("No item at " + std::to_string(index));
}

template <typename T>
T& SparseArray<T>::at(size_t index)
{
    return const_cast<T&>(std::as_const(*this).at(index));
}

template <typename T>
const T* SparseArray<T>::find(size_t index) const
{
    for (size_t i {}; i < sparse.size(); ++i)
    {
        if (sparse[i].first == index)
        {
            return &sparse[i].second;
        }
    }
    return nullptr;
}

template <typename T>
T* SparseArray<T>::find(size_t index)
{
    return const_cast<T*>(std::as_const(*this).find(index));
}

template <typename T>
bool SparseArray<T>::element_exists_at(size_t index) const
{
    return find(index) != nullptr;
}

#endif