#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__
#include "Node.hpp"


template<typename T>
class Iterator {
    private:
        Node<T>* ptr_;

    public:
        Iterator(Node<T>* ptr);
        Iterator(const Iterator& other);

        Node<T>& operator*() const;
        bool operator!=(const Iterator<T>& rhs) const;
        bool operator==(const Iterator<T>& rhs) const;
        Iterator& operator++();
        Iterator operator++(int) const;
};

template<typename T>
Iterator<T>::Iterator(Node<T>* ptr) : ptr_(ptr) {}

template<typename T>
Iterator<T>::Iterator(const Iterator& other) : ptr_(other.ptr_){}

template<typename T>
Node<T>& Iterator<T>::operator*() const {
    return (*ptr_);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) const{
    return (ptr_ != rhs.ptr_);
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) const{
    return (ptr_ == rhs.ptr_);
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    ++ptr_;
    return *(this);
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) const {
    Iterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

#endif
