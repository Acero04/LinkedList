#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__
#include "Node.hpp"


template<typename T>
class Iterator {
    private:
        Node<T>* current_;

    public:
        Iterator(Node<T>* ptr);
        Node<T>& operator*() const;
        bool operator!=(const Iterator<T>& rhs) const;
        bool operator==(const Iterator<T>& rhs) const;
        Iterator& operator++();
        Iterator operator++(int) const;
};

template<typename T>
Iterator<T>::Iterator(Node<T>* ptr) : current_(ptr) {}

template<typename T>
Node<T>& Iterator<T>::operator*() const {
    return *current_;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) const {
    return (current_ != rhs.current_);
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) const {
    return (current_ == rhs.current_);
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    current_ = current_->Next;
    return (*this);
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) const {
    Iterator<T> tmp = *this;
    *this = operator++();
    return tmp;
}

#endif
