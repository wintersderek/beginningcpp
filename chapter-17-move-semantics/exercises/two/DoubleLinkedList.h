#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <memory>
#include <stdexcept>

template <typename T>
class DoubleLinkedList
{
private:
    class Node
    {
    public:
        T content;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> previous;
        explicit Node(T c) : content {c} {}
    };

    std::shared_ptr<Node> head {};         // * to first Node
    std::shared_ptr<Node> tail {};         // * to last Node
    size_t items {};

public:
    class Iterator;

    DoubleLinkedList() = default;
    DoubleLinkedList(const DoubleLinkedList& src);      // Copy Constructor
    DoubleLinkedList(DoubleLinkedList&& src) noexcept;  // Move Constructor

    DoubleLinkedList& operator=(const DoubleLinkedList& src);
    DoubleLinkedList& operator=(DoubleLinkedList&& src) noexcept;

    void swap(DoubleLinkedList& src) noexcept;

    void push_back(T item);
    void push_front(T item);
    void clear() { head = nullptr; tail = nullptr; items = 0; }
    bool empty() const { return items == 0; }
    size_t size() const { return items; }

    Iterator get_forward_iterator() const { return Iterator(head); }
    Iterator get_backward_iterator() const { return Iterator(tail); }
};

// Copy Constructor
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& src)
{
    for (auto it {src.get_forward_iterator()}; it; it.move_next())
    {
        push_back(it.value());
    }
}

// Move Constructor
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList&& src) noexcept
{
    head = std::move(src.head);
    tail = std::move(src.tail);
    items = std::move(src.items);
}

// Copy Assignment Operator
template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& src) 
{
    if (&src != this)
    {
        DoubleLinkedList<T> copy{src}; // Copy
        swap(copy);                    // Swap
    }
    return *this;
}

// Move Assignment Operator
template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(DoubleLinkedList&& src) noexcept
{
    if (&src != this)
    {
        DoubleLinkedList<T> move {std::move(src)};
        swap(move);
    }
    return this;
}

// Swap
template <typename T>
void DoubleLinkedList<T>::swap(DoubleLinkedList &src) noexcept
{
    if (&src != this)
    {
        std::swap(head, src.head);
        std::swap(tail, src.tail);
        std::swap(items, src.items);
    }
}

template <typename T>
void DoubleLinkedList<T>::push_back(T item)
{
    std::shared_ptr<Node> to_add{std::make_shared<Node>(item)};

    if (tail)
    {
        // Point the current tail->next to to_add and to_add->previous to tail
        tail->next = to_add;
        to_add->previous = tail;
    }
    else
    {
        // List is empty.  to_add should be head
        head = to_add;
    }
    tail = to_add;
    ++items;
}

template <typename T>
void DoubleLinkedList<T>::push_front(T item)
{
    std::shared_ptr<Node> new_head {std::make_shared<Node>(item)};

    if (head)
    {
        new_head->next = head;
        head->previous = new_head;
    }
    head = new_head;
    ++items;
}

template <typename T>
class DoubleLinkedList<T>::Iterator
{
private:
    std::shared_ptr<Node> current;
    friend class DoubleLinkedList<T>;
    Iterator (std::shared_ptr<Node> start) : current {start} {}

public:
    operator bool() const { return current != nullptr; }
    const T& value() const;
    void move_next() { current = current->next; }
    void move_previous() { current = current->previous; }
};

template <typename T>
const T& DoubleLinkedList<T>::Iterator::value() const
{
    if (current == nullptr)
    {
        throw std::logic_error("Current is null");
    }
    return current->content;
}

template <typename T>
void swap(DoubleLinkedList<T>& one, DoubleLinkedList<T> two)
{
    one.swap(two);
}

#endif