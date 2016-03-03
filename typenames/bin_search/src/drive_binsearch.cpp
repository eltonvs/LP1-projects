/*
 * Copyright 2016 - Elton Viana
 */

#include <iostream>
#include <string>

#include "binsearch.h"

int main() {
    // Vetor de inteiros
    int V[]          = {2, 4, 6, 8, 10, 12, 14};
    int x            = 14;  // Elemento a ser procurado.
    char V2[]        = {'a', 'c', 'e', 'g', 'h', 'j', 'k'};
    char x2          = 'c';  // Elemento a ser procurado.
    std::string V3[] = {
        "aquaman",
        "batman",
        "capitão",
        "demolidor",
        "falcão",
        "hulk",
        "thor"
    };
    std::string x3   = "hulk";  // Elemento a ser procurado.
    int sz           = 7;  // Tamanho dos vetores

    std::cout << ">>> Vetor original: \n";
    printArray(V, sz);
    std::cout << ">>> Procurar pelo elemento: " << x << std::endl;
    std::cout << ">>> Resultado da busca: \n"
              << buscaBin(V, x, 0, sz-1, compara) << std::endl;

    std::cout << ">>> Vetor original: \n";
    printArray(V2, sz);
    std::cout << ">>> Procurar pelo elemento: " << x2 << std::endl;
    std::cout << ">>> Resultado da busca: \n"
              << buscaBin(V2, x2, 0, sz-1, compara) << std::endl;

    std::cout << ">>> Vetor original: \n";
    printArray(V3, sz);
    std::cout << ">>> Procurar pelo elemento: " << x3 << std::endl;
    std::cout << ">>> Resultado da busca: \n"
              << buscaBin(V3, x3, 0, sz-1, compara) << std::endl;

    return EXIT_SUCCESS;
}
