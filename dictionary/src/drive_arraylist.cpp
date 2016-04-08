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
    /*
     * DAL - Dictionary Array List
     */
    std::cout << "\n>>> DAL <<<\n";

    // Lista de no máximo 50 elementos.
    DAL <int, std::string>  myList(50);

    std::cout << ">>> myList: " << myList << std::endl;

    myList.insert(15, "dado 1");
    myList.insert(2, "dado 2");
    myList.insert(8, "dado 3");

    if (myList.search(8, "dado 3"))
        std::cout << "Found! 8 on dictionary\n";
    else
        std::cout << "Not Found!\n";

    std::cout << ">>> myList [after insertions]: " << myList << std::endl;

    myList.remove(15, "dado 1");
    myList.remove(21, "dado 21");

    std::cout << ">>> myList [after remotions]: " << myList << std::endl;


    /*
     * DSAL - Dictionary Sorted Array List
     */
    std::cout << "\n>>> DSAL <<<\n";

    // Lista de no máximo 50 elementos.
    DSAL <int, std::string>  mySortedList(50);

    std::cout << ">>> mySortedList: " << mySortedList << std::endl;

    mySortedList.insert(15, "dado 1");
    mySortedList.insert(2, "dado 2");
    mySortedList.insert(8, "dado 3");

    if (mySortedList.search(8, "dado 3"))
        std::cout << "Found! 8 on dictionary\n";
    else
        std::cout << "Not Found!\n";

    std::cout << ">>> mySortedList [after insertions]: " << mySortedList << std::endl;

    std::string removed_data;
    mySortedList.remove(15, removed_data);
    mySortedList.remove(21, removed_data);

    std::cout << ">>> mySortedList [after remotions]: " << mySortedList << std::endl;

    std::cout << "\n\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}
