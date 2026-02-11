#include "functions.hpp"

#include <iomanip>
#include <iostream>

bool continuer() {
    char c = '\0';
    std::cout << "\t\t'c' pour continuer.\n";
    std::cout << "\t\t'q' pour sortir.\n";
    std::cout << "\t\tVoulez vous continuer ?.\n";

    do {
        std::cout << ">_ ";
        std::cin >> c;
    }while (c != 'c' && c != 'q');

    return c == 'c';
}
//
void menu_principal() {
    std::cout << std::left << std::setw(30) <<  "1. pour creer un nouveau maillon dans la liste." << std::endl;

    std::cout << std::left << std::setw(30) << "2. pour supprimer un maillon dans la liste." << std::endl;

    std::cout << std::left << std::setw(30) << "3. pour afficher la liste." << std::endl;
}
