#include <iostream>

#include "binsearch.h"

using std::cout;
using std::endl;

template <typename Obj>
int buscaBin(Obj V[], Obj &x, int low, int high, int (*comp)(const Obj&, const Obj&)) {
    if (high < low)  // Caso base da recursao
        return -1;   // indice invalido, indicando que nao achou.

    // Determinar o elemento no centro do vetor.
    int mid = (low + high) / 2;

    cout << " >>> Procurando em [" << low << ", " << high << "]\n";
    int compR = comp(x, V[ mid ]);
    cout << " >>> Resultado comp: " << compR << endl;
    // Sera que o do meio eh o procurado?
    if (compR == 0) {
        // sucesso
        return mid;
    } else if (compR > 0) {
        // Procurar na metade direita.
        cout << " >>> Going right... [" << mid+1 << ", " << high << "]\n";
        return buscaBin(V, x, mid+1, high, comp);
    } else {
        // Procurar na metade esquerda.
        cout << " >>> Going left... [" << low << ", " << mid-1 << "]\n";
        return buscaBin(V, x, low, mid-1, comp);
    }
}
