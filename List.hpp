#ifndef __MY_LIST_HPP__
#define __MY_LIST_HPP__

//#include "Node.hpp"
#include "Iterator.hpp"
#include "Node.hpp"
#include <cstddef>
#include <cstdlib>
#include <initializer_list>
#include <cstdlib>
#include <iostream>
#include <stdexcept>


template<typename T>
class List {
    private:
        Node<T>* root_;
        size_t m_size;

        //methods
        void display_node(Node<T>* currentNode) const;
        bool search_node(Node<T>* someNode) const;
        bool is_empty() const;
        Node<T>* find_previous_and_next_node(const int position) const;

    public:
        //constructor && destructor.
        List();
        List(const T value);
        List(const List& rhs);
        List(std::initializer_list<T> list);
        ~List();

        //methods
        void insert(const T value);
        void insert(const T value, size_t position);
        void delete_node(const T value);
        void delete_node_in_position(size_t position);
        void concat(List<T>* MyList);
        void remove_duplicate();
        void display() const;
        size_t size() const;
        bool find_value(const T value) const;

        Iterator<T> begin() const;
        Iterator<T> end() const;
};

//////////////////////////////////////////////////////
//                                                  //
//              public methods.                     //
//                                                  //
//////////////////////////////////////////////////////

// constructors
template<typename T>
List<T>::List() : root_(nullptr), m_size(0) {}
//
template<typename T>
List<T>::List(const T value) : m_size(1), root_(create_Node(value)) {}

template<typename T>
List<T>::List(const List<T>& rhs) {

}

template<typename T>
List<T>::List(std::initializer_list<T> list) : root_(nullptr), m_size(0) {
    for (auto it =list.begin(); it < list.end(); it++) {
        insert(*it);
    }
}
//destructor.
template<typename T>
List<T>::~List<T>() {

    Node<T>* tmp = nullptr;
    while (root_ != nullptr) {
        tmp = root_->Next;
        delete root_;
        root_ = tmp;
    }
    m_size = 0;
}

//METHODS-----------------------------
//
template<typename T>
void List<T>::insert(const T value) {

    Node<T>* newNode = create_Node(value);

    if (is_empty()) {
        root_ = newNode;
    } else {
        Node<T> *tmp = root_;
        while (tmp->Next != nullptr) {
            tmp = tmp->Next;
        }
        tmp->Next  = newNode;
    }
    m_size++;
}
//
template<typename T>
void List<T>::insert(const T value, size_t position) {

    if (position <= 0 || position > m_size + 1) {
        std::cout << "Position valide [" << 1 << "..." << m_size + 1 << "]\n.";

        throw std::length_error("La position entrer n'est pas valide");
    }

    Node<T> *newNode = create_Node(value);

    if (position == 1) {

        newNode->Next = root_;
        root_ = newNode;
        m_size++;

    }  else {

        Node<T> *previousNode = find_previous_and_next_node(position - 1);

        //Node<T>* previousNode = nullptr;

        if (position < m_size) {
            newNode->Next = previousNode->Next;
            previousNode->Next = newNode;
        }
        int i = 0;
    }
    m_size += 1;
}
//

template<typename T>
void List<T>::delete_node(const T value) {

    if (is_empty()) {
        std::runtime_error("la liste est vide.\n");
    } else if (!find_value(value)) {
        throw std::runtime_error("La valeur saisie n'existe pas dans la liste.\n");
    } else {
        Node<T>* tmp_root = root_;
        Node<T>* previousNode = nullptr;

        while (tmp_root != nullptr) {
            if (tmp_root->value == value) {
                if (previousNode == nullptr)
                    root_ = tmp_root->Next;
                else
                    previousNode->Next = tmp_root->Next;
                delete tmp_root;
            }
            previousNode = tmp_root;
            tmp_root = tmp_root->Next;
        }
        m_size -= 1;
    }
}

//
template<typename T>
void List<T>::delete_node_in_position(size_t position) {

    if (position < 1 || position > m_size)
        throw std::out_of_range("Position invalide.\n");

    if (is_empty()) {
        throw std::runtime_error("la liste est vide.\n");
    } else if (position == 1){
        Node<T>* tmp = root_;
        root_ = root_->Next;
        delete tmp;
        m_size--;
    } else {
        int i = 1;
        Node<T>* tmp_root = root_;
        Node<T>* previousNode = nullptr;

        while (i < position) {
            previousNode = tmp_root;
            tmp_root = tmp_root->Next;
            i++;
        }
        previousNode->Next = tmp_root->Next;
        delete tmp_root;
        m_size--;
    }
}
//
template<typename T>
void List<T>::concat(List<T>* MyList) {
    Node<T>* tmp_root = MyList->root_;

    while (tmp_root != nullptr) {
        insert(tmp_root->value);
        tmp_root = tmp_root->Next;
    }
}
//
template<typename T>
void List<T>::remove_duplicate() {
    if (is_empty()) {
        std::cerr << "\nLa liste est vide.\n";
        return;
    } else if (m_size == 1) 
        return;

    //[2]->[6]->[5]->[1]->[2]->[1]->[7]->[6]->[3]->[10]->[5]->0X00
    Node<T>* fixNode = root_;
    Node<T>* mobileNode = nullptr;
    unsigned int positionFix = 1;
    unsigned int positionMobile = 0;

    while (fixNode != nullptr) {
        mobileNode = fixNode->Next;
        positionMobile = positionFix + 1;

        while (mobileNode != nullptr) {

            if (mobileNode->value == fixNode->value) {
                delete_node_in_position(positionMobile);
            }
            mobileNode = mobileNode->Next;
            positionMobile++;
        }
        fixNode = fixNode->Next;
        positionFix++;
    }
}

template<typename T>
void List<T>::display() const {
    Node<T>* tmp = root_;
    std::cout << "\n";
    display_node(tmp);
    std::cout << "\n-----size = " << m_size << "\n";
}
//

template<typename T>
bool List<T>::find_value(const T value) const {

    return search_node(create_Node(value));
}

////////////////////////////////////////////////////
//                                                //
//              private methods.                  //
//                                                //
////////////////////////////////////////////////////

template<typename T>
bool List<T>::is_empty() const {
    return root_ == nullptr;
}
//
template<typename T>
void List<T>::display_node(Node<T>* currentNode) const {
    if (currentNode == nullptr) {
        std::cout << "0x000\n";
    } else {
        std::cout << "[" << currentNode->value << "]->";
        display_node(currentNode->Next);
    }

}
//

//b
template<typename T>
size_t List<T>::size() const {
    return m_size;
}
//
template<typename T>
bool List<T>::search_node(Node<T>* someNode) const {

    if (is_empty()) {
        return false;
    } else {
        Node<T>* tmp = root_;

        while (tmp != nullptr) {
            if (tmp->value == someNode->value)
                return true;

            tmp = tmp->Next;
        }
        return false;
    }
}
//

//
template<typename T>
Node<T>* List<T>::find_previous_and_next_node(const int position) const {

    Node<T>* tmp = root_;
    int i = 1;
    while(i < position) {
        tmp = tmp->Next;
        i++;
    }
    return tmp;
}

//

template<typename T>
Iterator<T> List<T>::begin() const {
    return Iterator<T>(root_);
}

template<typename T>
Iterator<T> List<T>::end() const {
    return Iterator<T>(nullptr);
}
#endif
