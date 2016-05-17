/*!
 *  @mainpage Forward List
 *  @author Elton de Souza Vieira
 *  @date May, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive_forward_list.cpp
 *  @brief Driver File
 *
 *  File with the Forward List tests
 */

#include <iostream>
#include <cassert>
#include "forward_list.hpp"

int main(int argc, char const *argv[]) {
    Forward_list<int> fl1;

    // Unity test #1: size()
    assert(fl1.size() == 0);

    // Unity test #2: empty()
    assert(fl1.empty() == true);

    // Unity test #3: push_front() consequences
    fl1.push_front(3);
    assert(fl1.size() == 1);       // size()
    assert(fl1.empty() == false);  // empty()
    assert(fl1.front() == 3);      // front()
    assert(fl1.back() == 3);      // back()

    // Unity test #4: push_back() consequences
    fl1.push_back(10);
    assert(fl1.size() == 2);       // size()
    assert(fl1.empty() == false);  // empty()
    assert(fl1.front() == 3);      // front()
    assert(fl1.back() == 10);      // back()

    // Unity test #5: clear() consequences
    fl1.clear();
    assert(fl1.size() == 0);      // size()
    assert(fl1.empty() == true);  // empty()

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;
}
