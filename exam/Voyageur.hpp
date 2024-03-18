// Voyageur.hpp
#ifndef VOYAGEUR_HPP
#define VOYAGEUR_HPP

#include <vector>
#include "Ville.hpp"

// définition de la classe Voyageur
class Voyageur {
private:
    // stocker les villes, le chemin optimal et la distance du chemin optimal.
    std::vector<Ville> villes;
    std::vector<int> chemin;
    double meilleureDistance;

    double calculDistance(const Ville& ville1, const Ville& ville2);
    void permute(std::vector<int>& perm, int l, int r);

public:
    Voyageur(std::vector<Ville>&& _villes);
    void solve();
    void printSolution();
};

#endif
