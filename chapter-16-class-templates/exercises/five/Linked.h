#ifndef LINKED_H
#define LINKED_H

#include <memory>

template <typename T>
class Linked
{
private:
    class Node
    {
    public:
        T content;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> previous;
        explicit Node(T c) : content{c} {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

public:
    explicit Linked() {}
    void add(T item);
};

template <typename T>
void Linked<T>::add(T item)
{
    std::shared_ptr<Node> to_add{std::make_shared<Node>(item)};

    if (tail)
    {
        tail->next = to_add;
        to_add->previous = tail;
    }
    else
    {
        head = to_add;
    }
    tail = to_add;
}

#endif