// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1

#include "les_v1.h"
#include <iostream>
#include <cassert>

int main(void) {
    SNPtr pHead = NULL;  // nullptr;
    int aux;  // Aux variable

    // Print to Debug
    print(pHead);

    // Unity Test #1: length()
    assert(length(pHead) == 0);
    // Unity Test #2: empty()
    assert(empty(pHead) == true);
    // Unity Test #3: popFront()
    assert(popFront(pHead, aux) == false);

    clear(pHead);
    // Unity Test #4: length()
    assert(length(pHead) == 0);
    // Unity Test #5: empty()
    assert(empty(pHead) == true);

    if (front(pHead, aux))
        std::cout << aux << std::endl;
    if (back(pHead, aux))
        std::cout << aux << std::endl;

    pushFront(pHead, 1);
    pushFront(pHead, 2);

    // Print to Debug
    print(pHead);

    // Unity Test #6: length()
    assert(length(pHead) == 2);
    // Unity Test #7: empty()
    assert(empty(pHead) == false);

    clear(pHead);
    // Unity Test #8: length()
    assert(length(pHead) == 0);
    // Unity Test #9: empty()
    assert(empty(pHead) == true);

    pushBack(pHead, 1);
    pushBack(pHead, 2);
    pushBack(pHead, 3);
    pushBack(pHead, 4);

    // Print to Debug
    print(pHead);

    // Unity Test #10: length()
    assert(length(pHead) == 4);
    // Unity Test #11: empty()
    assert(empty(pHead) == false);

    // Unity Test #12: popFront()
    assert(popFront(pHead, aux) == true);
    // Unity Test #13: popFront() return
    assert(aux == 1);

    // Unity Test #12: popFront()
    assert(popBack(pHead, aux) == true);
    // Unity Test #13: popFront() return
    assert(aux == 4);

    // Unity Test #14: find()
    assert(find(pHead, 3)->miData == 2);

    // Unity Test #15: insert() return
    assert(insert(pHead, pHead, 12) == true);
    // Unity Test #16: insert() return
    assert(insert(pHead, pHead->mpNext, 123) == true);
    // Unity Test #17: insert()
    assert(find(pHead, 12) == NULL);
    // Unity Test #18: insert()
    assert(find(pHead, 123) == pHead);

    // Print to Debug
    print(pHead);

    // Unity Test #19: remove()
    assert(remove(pHead, pHead->mpNext, aux) == true);
    // Unity Test #20: remove() return
    assert(aux == 2);

    // Print to Debug
    print(pHead);

    std::cout << "\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
