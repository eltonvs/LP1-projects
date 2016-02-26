#include <iostream>
#include <sstream>
#include <random>
#include <vector>
#include "constants.h"
#include "functions.h"
#include "predicates.h"

int main(int argc, char * argv[]) {
    auto arrSz(N_DEFAULT); // Initialize vector size.

    // Process any command line arguments.
    if (argc > 1) {
        // In case the user has provided a value for us.
        std::stringstream(argv[1]) >> arrSz;
    }

    // Do we have a valid array size so far?
    if (arrSz <= 0  || arrSz > N_MAX) {
        std::cout << "\n>> Invalid argument provided!\n"
                  << "    Correct sintax: " << argv[0] << " [N >= 0 and N <= " << N_MAX << "]\n"
                  << "    Assuming N = " << N_DEFAULT << " for this run.\n";
        arrSz = N_DEFAULT; // Back to the default value.
    }

    std::cout << "\n>>> Required array size is: " << arrSz << "\n\n";

    // Store the data.
    std::vector< int > V(arrSz);

    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    randomFill(V, -100, 100, r());

    // Printing out the array, just to make sure we've got random integers.
    std::cout << ">>> ORIGINAL Vet = [ ";
    for (const auto &e : V)
        std::cout << e << " ";
    std::cout << "], Size = " << arrSz << "\n\n";

    // Show menu to choose compact method
    std::cout << "    [0 - Negatives | 1 - Less than 50 | 2 - Even | 3 - Primes]" << std::endl;
    unsigned op;
    do {
        std::cout << ">>> Enter the compact condition: ";
        std::cin >> op;
    } while (op > 3);

    // Compact Vector
    std::cout << "\n>>> Compacting now...\n\n";
    switch (op) {
        case 0:
            compact(V, predicateNegatives);
            break;
        case 1:
            compact(V, predicateLessThan50);
            break;
        case 2:
            compact(V, predicateEven);
            break;
        case 3:
            compact(V, predicatePrime);
            break;
    }

    // Printing compacted array.
    std::cout << ">>> COMPACTED Vet = [ ";
    for (const auto &e : V)
        std::cout << e << " ";
    std::cout << "], Size = " << V.size() << "\n\n";

    return EXIT_SUCCESS;
}
