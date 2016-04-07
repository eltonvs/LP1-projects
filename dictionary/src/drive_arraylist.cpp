/*
 * Copyright - 2016
 *
 * Test aplication for the Dictionary with Array Lits or DAL.
 *
 * Try to test as many DAL's methods in varying situations
 * as possible.
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <functional>

#include "dal.hpp"

int main() {
    // Lista de no máximo 50 elementos.
    DAL <int, std::string>  myList(50);

    std::cout << "\n>>> myList: " << myList << std::endl;

    myList.insert(15, "dado 1");
    myList.insert(2, "dado 2");
    myList.insert(8, "dado 3");

    if (myList.search(8, "dado 3"))
        std::cout << "Found!\n";
    else std::cout << "Not Found!\n";

    std::cout << "\n>>> myList [after insertions]: " << myList << std::endl;

    myList.remove(15, "dado 1");
    myList.remove(21, "dado 21");

    std::cout << "\n>>> myList [after remotions]: " << myList << std::endl;

    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}
