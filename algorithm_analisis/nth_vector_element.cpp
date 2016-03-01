/*
 * Escreva uma função para obter o k-ésimo menor elemento de uma
 * lista sequencial L com n elementos (precondição: 1 <= k <= n). Podem
 * haver elementos repetidos em L.
 * Elabore sua função de modo a minimizar a complexidade de pior caso
 * e determine esta complexidade.
 * Por fim, descreva a situação correspondente ao pior caso considerado
 * e forneça um exemplo ilustrativo com, pelo menos, n = 5 elementos.


 English translation (by google)

 Write a function for the kth smallest element of L sequential
 list with n elements (pre-condition: 1 <= k <= n). There may
 be repeated elements in L. Work its function to minimize complexity
 and determine this worst case complexity. Finally, describing the
 situation corresponding to the worst case considered and provides
 an illustrative example of at least n = 5 elements.

 */

#include <iostream>
#include <algorithm>

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
     *  - So I just need to return the V[k-1] (or, in pointers notation, *(v+k-1))
     */

    sort(V, V + n);

    return *(V+k-1);
}

// Now, let's analize the algorithm complexity
// First, let's see the C++ std::sort() complexity
// The std::sort() complexity is O'(n) = n*log(n) for the better and worst case
// And our nth_element function?
// We just have a return (after calling the sort function)
// So, the nth_element complexity is a constant, the time to return an element
// O''(n) = k
// After analyze that (was very simple, right?) We got the algorithm complexity
// O(n) = O'(n) + O''(n)
// O(n) = n*log(n) + k
// By the definition, we can ignore constants
// So, our complexity is the sort complexity
// O(n) = n*log(n) <- That's all folks!