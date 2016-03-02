/*
 * Copyright 2016 - Elton Viana
 */

#include <iostream>
#include <string>

#include "binsearch.h"

using std::cout;
using std::endl;
using std::string;

template <typename Obj>
void printArray(Obj V[], int sz) {
    cout << ">>> [ ";
    for (int i(0); i < sz; ++i)
        cout << V[i] << " ";
    cout << "]\n";
}

template <typename T>
int compara(const T & a, const T & b) {
    return a == b ? 0 : a > b ? 1 : -1;
}

int main() {
    // Vetor de inteiros
    int V1[] = { 2, 4, 6, 8, 10, 12, 14 };
    int x = 14;  // Elemento a ser procurado.
    char V2[] = { 'a', 'c', 'e', 'g', 'h', 'j', 'k'};
    char x2 = 'c';  // Elemento a ser procurado.
    string V3[] = {"aquaman", "batman", "capitão", "demolidor", "falcão", "hulk", "thor"};
    string x3 = "hulk";  // Elemento a ser procurado.
    // Tamanho dos vetores
    int sz = 7;

    cout << ">>> Vetor original: \n";
    printArray(V1, sz);

    cout << ">>> Procurar pelo elemento: " << x << endl;
    cout << ">>> Resultado da busca: \n" << buscaBin(V1, x, 0, sz-1, compara) << endl;

    cout << ">>> Vetor original: \n";
    printArray(V2, sz);
    cout << ">>> Procurar pelo elemento: " << x2 << endl;
    cout << ">>> Resultado da busca: \n" << buscaBin(V2, x2, 0, sz-1, compara) << endl;

    cout << ">>> Vetor original: \n";
    printArray(V3, sz);
    cout << ">>> Procurar pelo elemento: " << x3 << endl;
    cout << ">>> Resultado da busca: \n" << buscaBin(V3, x3, 0, sz-1, compara) << endl;

    return EXIT_SUCCESS;
}
