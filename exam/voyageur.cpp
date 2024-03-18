// voyageur.cpp
#include "Voyageur.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>

double Voyageur::calculDistance(const Ville& ville1, const Ville& ville2) {
    return sqrt(pow(ville1.x - ville2.x, 2) + pow(ville1.y - ville2.y, 2));
}

void Voyageur::permute(std::vector<int>& perm, int l, int r) {
    if (l == r) {
            double distance = 0.0;
            for (int i = 1; i < perm.size(); ++i) {
                distance += calculDistance(villes[perm[i - 1]], villes[perm[i]]);
            }
            distance += calculDistance(villes[perm.back()], villes[perm[0]]);
            if (distance < meilleureDistance) {
                meilleureDistance = distance;
                chemin = perm;
            }
        } else {
            for (int i = l; i <= r; ++i) {
                std::swap(perm[l], perm[i]);
                permute(perm, l + 1, r);
                std::swap(perm[l], perm[i]);
        }
    }
}

Voyageur::Voyageur(std::vector<Ville>&& _villes) : villes(std::move(_villes)), meilleureDistance(std::numeric_limits<double>::max()) {}


void Voyageur::solve() {
    std::vector<int> perm(villes.size());
    for (int i = 0; i < perm.size(); ++i) {
        perm[i] = i;
    }
    permute(perm, 1, perm.size() - 1);
}

void Voyageur::printSolution() {
    std::cout << "Best Path: ";
    for (int ville : chemin) {
        std::cout << villes[ville].id << " ";
    }
    std::cout << villes[chemin.front()].id << std::endl;
    std::cout << "Total Distance: " << meilleureDistance << std::endl;
}
