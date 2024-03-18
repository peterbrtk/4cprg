#include <iostream>
#include "Voyageur.hpp"

// fonction principale 
// crée un vecteur de villes, crée une instance de "Voyageur", résout le problème et affiche la solution.
int main() {
    std::vector<Ville> villes = {
        // définition des coordonnées des villes
        {0, 0.0, 0.0},
        {1, 4.0, 4.0},
        {2, 1.0, 1.0},
        {3, 3.0, 3.0},
        {4, 2.0, 4.0},
        
    };
    // appel de la classe Voyageur
    Voyageur tsp(std::move(villes));
    tsp.solve();
    tsp.printSolution();

    return 0;
}
