/*!
 *  @mainpage Vector
 *  @authors Elton de Souza Vieira, Claudio Lima Bezerra
 *  @date May, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive_vector.cpp
 *  @brief Driver File
 *
 *  File with the Vector tests
 */

#include <iostream>
#include <cassert>
#include "vector.hpp"

int main(int argc, char const *argv[]) {
    int i;
    Vector<int> v1;
    Vector<int> v2(50);

    // Unity Test #1: capacity()
    assert(v1.capacity() == 1);
    assert(v2.capacity() == 50);

    // Unity Test #2: size()
    assert(v1.size() == 0);
    assert(v2.size() == 0);

    // Pop Back 10 times (testing the dynamic array allocation)
    for (i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i);
    }

    // Unity test #3: data()
    int *ptr1 = v1.data();
    int *ptr2 = v2.data();
    for (i = 0; i < 10; i++) {
        assert(*(ptr1+i) == i);
        assert(*(ptr2+i) == i);
    }

    // Unity test #4: const_iterator (postfix ++ and *), cbegin(), cend()
    i = 0;
    for (auto it = v1.cbegin(); it != v1.cend(); it++, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity test #5: const_iterator (infix ++ and *), cbegin(), cend()
    i = 0;
    for (auto it = v1.cbegin(); it != v1.cend(); ++it, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity test #6: iterator (postfix ++ and *), begin(), end()
    i = 0;
    for (auto it = v1.begin(); it != v1.end(); it++, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity test #7: iterator (infix ++ and *), begin(), end()
    i = 0;
    for (auto it = v1.begin(); it != v1.end(); ++it, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity test #8: back()
    assert(v1.back() == 9);
    assert(v2.back() == 9);

    // Unity test #9: front()
    assert(v1.front() == 0);
    assert(v2.front() == 0);

    // Unity test #10: size() after inserctions
    assert(v1.size() == 10);
    assert(v2.size() == 10);

    v1.pop_back();
    v2.pop_back();

    // Unity test #11: size() after remotion
    assert(v1.size() == 9);
    assert(v2.size() == 9);

    v1.assign(10);
    v2.assign(20);

    // Unity test #12: assign(), at() and the [] operator
    for (i = 0; i < 9; i++) {
        assert(v1.at(i) == 10);
        assert(v1[i] == 10);
        assert(v2.at(i) == 20);
        assert(v2[i] == 20);
    }

    // Clear Vector content
    v1.clear();
    v2.clear();

    // Unity test #13: size() after clear
    assert(v1.size() == 0);
    assert(v2.size() == 0);

    // Exit message
    std::cout << ">>> Exiting with sucess...\n";

    return EXIT_SUCCESS;
}
