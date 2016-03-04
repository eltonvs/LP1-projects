#include <iostream>
#include "binsearch.h"

template <typename T>
int buscaBin(T V[], T &x, int low, int high, int (*comp)(const T &, const T &)) {
    if (high < low)  // Caso base da recursao
        return -1;   // indice invalido, indicando que nao achou.

    // Determinar o elemento no centro do vetor.
    int mid = (low + high)/2;

    std::cout << " >>> Procurando em [" << low << ", " << high << "]\n";
    int compR = comp(x, V[mid]);
    std::cout << " >>> Resultado comp: " << compR << std::endl;
    // Sera que o do meio eh o procurado?
    if (compR == 0) {
        // sucesso
        return mid;
    } else if (compR > 0) {
        // Procurar na metade direita.
        std::cout << " >>> Going right... [" << mid+1 << ", " << high << "]\n";
        return buscaBin(V, x, mid+1, high, comp);
    } else {
        // Procurar na metade esquerda.
        std::cout << " >>> Going left... [" << low << ", " << mid-1 << "]\n";
        return buscaBin(V, x, low, mid-1, comp);
    }
}

template <typename T>
void printArray(const T V[], int sz) {
    std::cout << ">>> [ ";
    for (int i(0); i < sz; ++i)
        std::cout << V[i] << " ";
    std::cout << "]\n";
}

template <typename T>
int compara(const T &a, const T &b) {
    return a == b ? 0 : a > b ? 1 : -1;
}
