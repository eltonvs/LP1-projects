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
#include <cassert>
#include <cmath>
#include <functional>

#include "dal.hpp"

class MyKeyComparator {
 public:
    int operator()(int lhs, int rhs) const {
        if (lhs < rhs) return -1;
        else if (lhs == rhs) return 0;
        else return 1; // lhs > rhs
    }
};

int main() {
    std::string removed_data;
    int aux;

    /*
     * DAL - Dictionary Array List
     */
    std::cout << "\n>>> DAL <<<\n";

    // Lista de no máximo 50 elementos.
    DAL <int, std::string, MyKeyComparator>  myList(50);

    std::cout << ">>> myList: " << myList << std::endl;

    myList.insert(15, "dado 1");
    myList.insert(2, "dado 2");
    myList.insert(8, "dado 3");

    // Unity Tests #1: max() and min()
    assert(2 == myList.min());
    assert(15 == myList.max());

    // Unity Tests #2: sucessor()
    assert(true == myList.sucessor(2, aux));
    assert(8 == aux);
    assert(true == myList.sucessor(8, aux));
    assert(15 == aux);
    assert(false == myList.sucessor(15, aux));

    // Unity Tests #3: predecessor()
    assert(false == myList.predecessor(2, aux));
    assert(true == myList.predecessor(8, aux));
    assert(2 == aux);
    assert(true == myList.predecessor(15, aux));
    assert(8 == aux);

    // Unity Tests #4: search()
    assert(true == myList.search(2, "dado 2"));
    assert(true == myList.search(8, "dado 3"));
    assert(true == myList.search(15, "dado 1"));
    assert(false == myList.search(20, "dado 4"));

    std::cout << ">>> myList [after insertions]: " << myList << std::endl;

    myList.remove(15, removed_data);
    myList.remove(21, removed_data);

    // Unity Tests #5: remove()
    assert(false == myList.search(15, "dado 1"));
    assert(false == myList.search(20, "dado 4"));

    std::cout << ">>> myList [after remotions]: " << myList << std::endl;


    /*
     * DSAL - Dictionary Sorted Array List
     */
    std::cout << "\n>>> DSAL <<<\n";

    // Lista de no máximo 50 elementos.
    DSAL <int, std::string, MyKeyComparator>  mySortedList(50);

    std::cout << ">>> mySortedList: " << mySortedList << std::endl;

    mySortedList.insert(15, "dado 1");
    mySortedList.insert(2, "dado 2");
    mySortedList.insert(8, "dado 3");

    // Unity Tests #1: max() and min()
    assert(2 == mySortedList.min());
    assert(15 == mySortedList.max());

    // Unity Tests #2: sucessor()
    assert(true == mySortedList.sucessor(2, aux));
    assert(8 == aux);
    assert(true == mySortedList.sucessor(8, aux));
    assert(15 == aux);
    assert(false == mySortedList.sucessor(15, aux));

    // Unity Tests #3: predecessor()
    assert(false == mySortedList.predecessor(2, aux));
    assert(true == mySortedList.predecessor(8, aux));
    assert(2 == aux);
    assert(true == mySortedList.predecessor(15, aux));
    assert(8 == aux);

    // Unity Tests #4: search()
    assert(true == mySortedList.search(2, "dado 2"));
    assert(true == mySortedList.search(8, "dado 3"));
    assert(true == mySortedList.search(15, "dado 1"));
    assert(false == mySortedList.search(20, "dado 4"));

    std::cout << ">>> mySortedList [after insertions]: " << mySortedList << std::endl;

    mySortedList.remove(15, removed_data);
    mySortedList.remove(21, removed_data);

    // Unity Tests #5: remove()
    assert(false == mySortedList.search(15, "dado 1"));
    assert(false == mySortedList.search(20, "dado 4"));

    std::cout << ">>> mySortedList [after remotions]: " << mySortedList << std::endl;

    std::cout << "\n\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}
