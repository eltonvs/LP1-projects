// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1

#include "les_v1.h"
#include <iostream>
#include <cassert>

int main(void) {
    SNPtr pHead = NULL;  // nullptr;

    // Print to Debug
    print(pHead);

    // Unity Test #1: length()
    assert(length(pHead) == 0);
    // Unity Test #2: empty()
    assert(empty(pHead) == true);

    clear(pHead);
    // Unity Test #3: length()
    assert(length(pHead) == 0);
    // Unity Test #4: empty()
    assert(empty(pHead) == true);

    int aux;
    if (front(pHead, aux))
        std::cout << aux << std::endl;
    if (back(pHead, aux))
        std::cout << aux << std::endl;

    pushFront(pHead, 1);
    pushFront(pHead, 2);

    // Print to Debug
    print(pHead);

    // Unity Test #5: length()
    assert(length(pHead) == 2);
    // Unity Test #6: empty()
    assert(empty(pHead) == false);

    clear(pHead);
    // Unity Test #3: length()
    assert(length(pHead) == 0);
    // Unity Test #4: empty()
    assert(empty(pHead) == true);

    pushBack(pHead, 1);
    pushBack(pHead, 2);
    pushBack(pHead, 3);
    pushBack(pHead, 4);

    // Print to Debug
    print(pHead);

    // Unity Test #5: length()
    assert(length(pHead) == 4);
    // Unity Test #6: empty()
    assert(empty(pHead) == false);

    std::cout << "\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
