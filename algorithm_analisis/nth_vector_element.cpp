/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva uma função para obter o k-ésimo menor elemento de uma
 * lista sequencial L com n elementos (precondição: 1 <= k <= n). Podem
 * haver elementos repetidos em L.
 * Elabore sua função de modo a minimizar a complexidade de pior caso
 * e determine esta complexidade.
 * Por fim, descreva a situação correspondente ao pior caso considerado
 * e forneça um exemplo ilustrativo com, pelo menos, n = 5 elementos.
 */

#include <iostream>   // Input/Output functions
#include <algorithm>  // std::sort()

using namespace std;

int nth_element(int *V, int n, int k);
void sort_vector(int *V, int n);

int main(int argc, const char *argv[]) {
    int vector[] = {5, 4, 3, 2, 1},
        vector_size = sizeof(vector)/sizeof(int);

    // Show array
    cout << "Array = [ ";
    for (auto i : vector)
        cout << i << " ";
    cout << "]\n";

    // Call nth_element and show it
    cout << "The 3rd minor element from vector is: "
         << nth_element(vector, vector_size, 3) << endl;

    // Exiting message
    cout << "\n\nExiting..." << endl;

    return EXIT_SUCCESS;
}

int nth_element(int *V, int n, int k) {
    /*
     *  - Sort the array.
     *  - So I just need to return the V[k-1] (or, in pointers notation, *(V+k-1))
     */

    sort(V, V + n);

    return *(V+k-1);
}