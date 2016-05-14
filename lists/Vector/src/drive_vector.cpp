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

    // Exit message
    std::cout << ">>> Exiting with sucess...\n";

    return EXIT_SUCCESS;
}
