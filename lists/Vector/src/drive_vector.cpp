/*!
 *  @mainpage Vector
 *  @author Elton de Souza Vieira
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
    // Code Here
    Vector<int> v1;
    Vector<int> v2(50);

    // Unity Test #1: size()
    assert(v1.size() == 0);
    assert(v2.size() == 0);

    // Pop Back 10 times (testing the dynamic array allocation)
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i);
    }

    // Unity test #2: size() after inserctions
    assert(v1.size() == 10);
    assert(v2.size() == 10);

    v1.pop_back();
    v2.pop_back();

    // Unity test #3: size() after remotion
    assert(v1.size() == 9);
    assert(v2.size() == 9);

    // Clear Vector content
    v1.clear();
    v2.clear();

    // Unity test #4: size() after clear
    assert(v1.size() == 0);
    assert(v2.size() == 0);

    // Exit message
    std::cout << ">>> Exiting with sucess...\n";

    return EXIT_SUCCESS;
}
