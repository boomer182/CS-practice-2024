#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>
#include <memory>

template <typename T>
class LinkedList {
protected:
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(T value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    size_t size;

    virtual void Print(std::ostream& os) const = 0;

public:
    LinkedList() : head(nullptr), size(0) {}
    virtual ~LinkedList() = default;

    virtual void Push(T value) = 0;
    virtual T Pop() = 0;
    virtual T GetFront() const = 0;
    virtual bool IsEmpty() const { return size == 0; }
    virtual size_t Size() const { return size; }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        list.Print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, LinkedList<T>& list) {
        T value;
        is >> value;
        list.Push(value);
        return is;
    }
};

#endif // LINKED_LIST_H_INCLUDED
