/*
 * Copyright 2016 - Elton Viana
 */

#include <new>
#include <stdexcept>
#include <iostream>

#include "doublearray.h"

using std::bad_alloc;

template <typename T>
void DoubleArray(T *&A, int &s, T *n_A = nullptr) {
    // 1) Alocar a nova memoria
    n_A = new T[s*2];

    // 2) Copiar valores de A para o novo vetor
    for (int i = 0; i < s; i++)
        *(n_A+i) = *(A+i);

    // 3) Liberar a memoria associada ao ponteiro A
    delete[] A;

    // 4) Fazer o A apontar p/ a nova memoria
    A = n_A;

    // 5) Atualizar o novo tamanho do arranjo A.
    s *= 2;
}
