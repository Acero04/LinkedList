#include Actions.hpp "
#include "List.hpp"
#include "functions.hpp"

#include <cstdlib>
#include <ncurses.h>

int main() {
  std::system("clear");
  List<int> *MyList = new List<int>();

  while (continuer()) {
    menu_principal();
    char choice = '\0';
    std::cout << "FAITE VOTRE CHOIX.";
    std::cout << ">_ ";

    std::cin >> choice;

    switch (choice) {
    case '1':
      std::system("clear");
      ajouter_une_valeur(MyList);
      break;
    case '2':
      std::system("clear");
      supprimer(MyList);
    case '3':
      std::system("clear");
      afficher_la_liste(MyList);
    default:
      std::cerr << "Choix non disponible.\n";
    }
  }
  std::cout << "Espace allouer pour la liste : "
            << MyList->getSize() * sizeof(*MyList) << std::endl;
  delete MyList;

  return 0;
}
