#ifndef __MY_LIST_HPP__
#define __MY_LIST_HPP__

//#include "Node.hpp"
#include "Iterator.hpp"
#include "Node.hpp"
<<<<<<< HEAD

#include <cstdlib>
#include <initializer_list>
=======
#include <cstdlib>
>>>>>>> c4c0df0e7c441ba477588490f512c47f1fc5d2cf
#include <iostream>
#include <stdexcept>


template<typename T>
class List {
    private:
        Node<T>* m_root;
        size_t m_size;

        //methods
<<<<<<< HEAD
        void displayNode(Node<T>* currentNode) const;
=======
        void displayNode(Node<T> *crrentNode) const;
>>>>>>> c4c0df0e7c441ba477588490f512c47f1fc5d2cf
        bool searchNode(Node<T>* someNode) const;
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
<<<<<<< HEAD
        void insert(const T value, const unsigned int position);
=======
        void insert(const T value,const unsigned int position);
>>>>>>> c4c0df0e7c441ba477588490f512c47f1fc5d2cf
        void delete_node(const T value);
        void delete_node_in_position(const unsigned int position);
        void concat(List<T>* MyList);
        void supprimer_doublon();
        void displayList() const;
<<<<<<< HEAD
        unsigned int size() const;
=======
        unsigned int getSize() const;
>>>>>>> c4c0df0e7c441ba477588490f512c47f1fc5d2cf
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
List<T>::List() : m_root(nullptr), m_size(0) {

    std::cout << "\t\tm_root = " << m_root << "\n";
    std::cout << "\t\t---------OBJET CREER--------\n";
}
//
template<typename T>
List<T>::List(const T value) : m_size(1) {

    m_root = create_Node(value);

    std::cout << "\t\tm_root = " << m_root << "\n";
    std::cout << "\t\t---------OBJET CREER--------\n";
<<<<<<< HEAD
}

template<typename T>
List<T>::List(const List<T>& rhs) {
    Node<T>* tmp = rhs.m_root;
    for (auto i = 0; i < rhs.m_size; i++) {
        this->insert(tmp->value);
        tmp = tmp->Next;
    }
}

template<typename T>
List<T>::List(std::initializer_list<T> list) : m_root(nullptr), m_size(0) {
    auto it = list.begin();
    for (auto i = 0; i < list.size(); i++, it++) {
        this->insert(*it);
    }
=======
>>>>>>> c4c0df0e7c441ba477588490f512c47f1fc5d2cf
}
//destructor.
template<typename T>
List<T>::~List<T>() {

//    Node<T>* currentNode = m_root;
    Node<T>* tmp = nullptr;
    std::cout << "\n\t\tm_root = " << m_root << "\n";
    while (m_root != nullptr) {
        tmp = m_root->Next;
        delete m_root;
        m_root = tmp;
    }
    m_size = 0;
    std::cout << "\t\t---------OBJET DETRUIT------\n";
}

//METHODS-----------------------------
//
template<typename T>
void List<T>::insert(const T value) {

    Node<T>* newNode = create_Node(value);

    if (is_empty()) {
        m_root = newNode;
    } else {
        Node<T> *tmp = m_root;
        while (tmp->Next != nullptr) {
            tmp = tmp->Next;
        }
        tmp->Next  = newNode;
    }
    m_size++;
}
//
template<typename T>
void List<T>::insert(const T value, const unsigned int position) {

    if (position <= 0 || position > m_size + 1) {
        std::cout << "Position valide [" << 1 << "..." << m_size + 1 << "]\n.";

        throw std::length_error("La position entrer n'est pas valide");
    }

    Node<T> *newNode = create_Node(value);

    if (position == 1) {

        newNode->Next = m_root;
        m_root = newNode;
        m_size++;

    }  else {

        Node<T> *previousNode = find_previous_and_next_node(position - 1);

        //Node<T>* previousNode = nullptr;

        if (static_cast<size_t>(position) < m_size) {
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
        Node<T>* tmp_root = m_root;
        Node<T>* previousNode = nullptr;

        while (tmp_root != nullptr) {
            if (tmp_root->value == value) {
                if (previousNode == nullptr)
                    m_root = tmp_root->Next;
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
void List<T>::delete_node_in_position(const unsigned int position) {

    if (position < 1 || position > m_size)
        throw std::out_of_range("Position invalide.\n");

    if (is_empty()) {
        throw std::runtime_error("la liste est vide.\n");
    } else if (position == 1){
        Node<T>* tmp = m_root;
        m_root = m_root->Next;
        delete tmp;
        m_size--;
    } else {
        int i = 1;
        Node<T>* tmp_root = m_root;
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
    Node<T>* tmp_root = MyList->m_root;

    while (tmp_root != nullptr) {
        insert(tmp_root->value);
        tmp_root = tmp_root->Next;
    }
}
//
template<typename T>
void List<T>::supprimer_doublon() {
    if (is_empty()) {
        std::cerr << "\nLa liste est vide.\n";
        return;
    } else if (m_size == 1) 
        return;

    //[2]->[6]->[5]->[1]->[2]->[1]->[7]->[6]->[3]->[10]->[5]->0X00
    Node<T>* fixNode = m_root;
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
void List<T>::displayList() const {
    Node<T>* tmp = m_root;
    std::cout << "\n";
    displayNode(tmp);
    std::cout << "\n-----size = " << m_size << "\n";
}
//

template<typename T>
bool List<T>::find_value(const T value) const {

    return searchNode(create_Node(value));
}

////////////////////////////////////////////////////
//                                                //
//              private methods.                  //
//                                                //
////////////////////////////////////////////////////

template<typename T>
bool List<T>::is_empty() const {
    return m_root == nullptr;
}
//
template<typename T>
void List<T>::displayNode(Node<T>* currentNode) const {
    if (currentNode == nullptr) {
        std::cout << "0x000\n";
    } else {
        std::cout << "[" << currentNode->value << "]->";
        displayNode(currentNode->Next);
    }

}
//

//b
template<typename T>
unsigned int List<T>::size() const {
    return m_size;
}
//
template<typename T>
bool List<T>::searchNode(Node<T>* someNode) const {

    if (is_empty()) {
        return false;
    } else {
        Node<T> *tmp = m_root;

        while (tmp != nullptr) {
            if (tmp->value == someNode->value) {
                return true;
            }
            tmp = tmp->Next;
        }
        return false;
    }
}
//

//
template<typename T>
Node<T>* List<T>::find_previous_and_next_node(const int position) const {

    Node<T>* tmp = m_root;
    int i = 1;
    while(i < position) {
        tmp = tmp->Next;
        i++;
    }
    return tmp;
}

//

<<<<<<< HEAD
template<typename T>
Iterator<T> List<T>::begin() const {
    return Iterator<T>(m_root);
}
=======
>>>>>>> c4c0df0e7c441ba477588490f512c47f1fc5d2cf

template<typename T>
Iterator<T> List<T>::end() const {
    return Iterator<T>(nullptr);
}
#endif
