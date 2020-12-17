/*
Class template for a Stack using a nested class
*/
#ifndef STACK_H
#define STACK_H
#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
class Stack
{
private:
    class Node
    {
        public:
            T item;
            std::unique_ptr<Node> next;
            Node(const T& i) : item {i} {}
            // Copy Constructor
            Node(const Node& x) : item {x.item}
            {
                if (x.next)
                {
                    next = std::make_unique<Node>(x.next->item);
                }
            }
    };

    std::unique_ptr<Node> head {};

public:
    Stack() = default;
    Stack(const Stack& copy);
    Stack& operator=(const Stack& rhs);
    operator bool() const { return head !=nullptr; };

    void push(const T& item);   // Add item
    T pop();                    // Remove Item
    void swap(Stack& other);    // support copy-and-swap idiom
};

// Copy Constructor
template <typename T> 
Stack<T>::Stack(const Stack& copy)
{
    if (copy.head)
    {
        T copyItem = copy.head->item;
        // Replicate copy in to this by copying all nodes
        head = std::make_unique<Node>(copyItem);


        Node* originalNode {copy.head.get()};
        Node* copyNode {head.get()};

        while (originalNode = originalNode->next.get())
        {
            
            // Original had a next in the linked list.  Add it to copy using
            // Node's copy constructor
            copyNode->next = std::make_unique<Node>(*originalNode);
            // move down the linked list to the next node for copying
            copyNode = copyNode->next.get();
    
        }
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
    // Implement copy-and-swap idiom
    auto copy {rhs};
    swap(copy);
    return *this;
}

template <typename T>
void Stack<T>::swap(Stack<T>& other)
{
    std::swap(head, other.head);
}

template <typename T>
void Stack<T>::push(const T& item)
{
    std::unique_ptr<Node> node {std::make_unique<Node>(item)};
    node->next = std::move(head);
    head = std::move(node);
    //std::move(head, node->next);
    //std::move(node, head);
    //node->next = head;
    //head = node;
}

template <typename T>
T Stack<T>::pop()
{
    if (this->head != nullptr)
    {
        T retValue{head->item};
        head = std::move(head->next);
        //std::move(head->next, head);
        //head = head->next;
        return retValue;
    }
    else
    {
        throw std::logic_error("The stack is currently empty!");
    }
}

#endif