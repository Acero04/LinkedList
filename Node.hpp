#ifndef __MY_NODE_H__
#define __MY_NODE_H__

#include <iostream>
#include <ostream>
template<typename T>

struct Node {
    T value;
    Node* Next;
    friend std::ostream& operator<<(std::ostream& fOut, const Node& other) {
        if (!other.value)
            fOut << "empty";
        else
            fOut << other.value;
        return fOut;
    }
};
/*
template<typename T>
std::ostream& operator<<(std::ostream& fOut, const Node<T>& )
*/

template<typename T>
Node<T>* create_Node(const T value) {
    Node<T>* newNode = new Node<T>();

    if (newNode == nullptr) {
        std::cerr << "l'allocation d'un nouveau noeud a exhouer.\n";
        return nullptr;
    } else {
        newNode->value = value;
        newNode->Next = nullptr;
        return newNode;
    }
}


#endif
