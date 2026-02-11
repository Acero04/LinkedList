#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include "List.hpp"
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <ncurses.h>
#include <new>


template<typename T>
List<T>* creer_la_liste() {
    try {
        List<T>* MyList = new List<T>();
        return MyList;
    } catch (std::bad_alloc const &e) {
        std::cout << "Echec d'allocation memoire : " << e.what() << "\n";
        return nullptr;
    }
}
//
template<typename T>
static void menu_ajouter(const List<T>* MyList) {

    std::system("clear");
    int npos = MyList->getSize() + 1;
    int i = 1;
    std::cout << "\n----[-BIENVENUE AU MENU AJOUTER-]----\n";
    std::cout << "1. pour ajouter en fin de liste.\n";

    std::cout << "2. pour ajouter a une position comprise entre [1..." << npos << "].\n";


}
//
//
template<typename T>
void ajouter_une_valeur(List<T> *MyList) {

    unsigned int choice = 0;
    T valeur = 0;

    menu_ajouter(MyList);
    std::cout << "entre ton choix : ";

    do {
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Erreur de saisie. Veuillez réessayer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while (choice < 1 || choice > 2);

    switch (choice) {

        case 1:
            do {
                std::cout << "Entrer la valeur du Noeud : ";
                std::cin >> valeur;
            } while(std::cin.fail());
            MyList->insert(valeur);
        break;

        case 2:
            size_t position = 0;
            std::cout << "Entre la position du noeud : ";
            do {
                std::cin >> position;
                if (std::cin.fail()) {
                    std::cout << "Erreur de saisie. Veuillez réessayer: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } 
            }while (position < 1 || position > MyList->getSize() + 1);
            do {
                std::cout << "Entrer la valeur du Noeud : ";
                std::cin >> valeur;
            } while(std::cin.fail());
            MyList->insert(valeur, position);
        break;
    }
}
//
template<typename T>
static void menu_supprimer(const List<T>* MyList) 
{
    std::cout << "\n\t----[-BIENVENUE AU MENU SUPPRIMER-]----\n";
    std::cout << "\t1. suppression par la valeur.\n";
    std::cout << "\t2. suppression par position [1..." << MyList->getSize() << "].\n";
}
//
template<typename T>
void supprimer(List<T>* MyList) 
{
    menu_supprimer(MyList);

    unsigned int choice = 0;
    std::cout << "entre ton choix : ";

    while (!(std::cin >> choice) || choice < 1 || choice > 2){
        if (std::cin.fail()) {
            std::cerr << "Erreur de saisie. Veuillez réessayer: \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << ">_ ";
        } else {
            std::cerr << "Entrer soit 1 soit 2.\n";
            std::cout << ">_ ";
        }
    }

    switch (choice) {
        case 1:
            T valeur;
            std::cout << "\nEntre la valeur du Noeud à supprimer.\n";
            do {
                std::cout << ">_.";
                std::cin >> valeur;
            } while(std::cin.fail());
            MyList->delete_value(valeur);
        break;

        case 2:
            unsigned int position = 0;
            std::cout << "\nEntre la position du noeud à supprimer.\n";
            do {
                std::cout << ">_ ";
                std::cin >> position;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }while (position < 1 || position > MyList->getSize());

            MyList->delete_value(position);
    }
}
template<typename T>
void afficher_la_liste(const List<T>* MyList) {
    std::system("clear");
    MyList->displayList();
}
#endif
