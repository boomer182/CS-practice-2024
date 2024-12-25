#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "linked_list.h"

template <typename T>
class Stack : public LinkedList<T> {
public:
    Stack() = default;

    Stack(const Stack& other) {
        if (!other.IsEmpty()) {
            this->head = std::make_unique<typename LinkedList<T>::Node>(other.head->data);
            auto current = other.head->next.get();
            auto newCurrent = this->head.get();

            while (current) {
                newCurrent->next = std::make_unique<typename LinkedList<T>::Node>(current->data);
                newCurrent = newCurrent->next.get();
                current = current->next.get();
            }
        }
        this->size = other.size;
    }

    Stack(Stack&& other) noexcept = default;

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            Stack temp(other);
            std::swap(this->head, temp.head);
            this->size = other.size;
        }
        return *this;
    }

    Stack& operator=(Stack&& other) noexcept = default;

    void Push(T value) override {
        auto newNode = std::make_unique<typename LinkedList<T>::Node>(value);
        newNode->next = std::move(this->head);
        this->head = std::move(newNode);
        this->size++;
    }

    T Pop() override {
        if (this->IsEmpty()) throw std::runtime_error("Stack is empty.");
        T value = this->head->data;
        this->head = std::move(this->head->next);
        this->size--;
        return value;
    }

    T GetFront() const override {
        if (this->IsEmpty()) throw std::runtime_error("Stack is empty.");
        return this->head->data;
    }

protected:
    void Print(std::ostream& os) const override {
        auto current = this->head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
    }
};

#endif // STACK_H_INCLUDED
