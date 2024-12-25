#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "linked_list.h"

template <typename T>
class Queue : public LinkedList<T> {
public:
    Queue() = default;

    Queue(const Queue& other) {
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

    Queue(Queue&& other) noexcept = default;

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            Queue temp(other);
            std::swap(this->head, temp.head);
            this->size = other.size;
        }
        return *this;
    }

    Queue& operator=(Queue&& other) noexcept = default;

    void Push(T value) override {
        auto newNode = std::make_unique<typename LinkedList<T>::Node>(value);
        if (this->IsEmpty()) {
            this->head = std::move(newNode);
        } else {
            auto current = this->head.get();
            while (current->next) {
                current = current->next.get();
            }
            current->next = std::move(newNode);
        }
        this->size++;
    }

    T Pop() override {
        if (this->IsEmpty()) throw std::runtime_error("Queue is empty.");
        T value = this->head->data;
        this->head = std::move(this->head->next);
        this->size--;
        return value;
    }

    T GetFront() const override {
        if (this->IsEmpty()) throw std::runtime_error("Queue is empty.");
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

#endif // QUEUE_H_INCLUDED
