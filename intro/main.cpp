#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {

    int nombre_de_lignes = std::atoi(argv[1]);

    for (int i = 1; i <= nombre_de_lignes; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }

    return 0;
}