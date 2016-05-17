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
    // Forward_list<int> fl2(fl1);
    // Forward_list<int> fl3(std::move(fl1));

    // Unity test #1: size()
    assert(fl1.size() == 0);
    // assert(fl2.size() == 0);
    // assert(fl3.size() == 0);

    // Unity test #2: empty()
    assert(fl1.empty() == true);
    // assert(fl2.empty() == true);
    // assert(fl3.empty() == true);

    fl1.push_front(3);
    // fl2.push_front(3);
    // fl3.push_front(3);

    // Unity test #1: size()
    assert(fl1.size() == 1);
    // assert(fl2.size() == 1);
    // assert(fl3.size() == 1);

    // Unity test #2: empty()
    assert(fl1.empty() == false);
    // assert(fl2.empty() == false);
    // assert(fl3.empty() == false);

    // Unity test #2: empty()
    assert(fl1.front() == 3);
    // assert(fl2.front() == 3);
    // assert(fl3.front() == 3);

    fl1.clear();
    // fl2.clear();
    // fl3.clear();

    // Unity test #3: size() and empty() after clear()
    assert(fl1.size() == 0 && fl1.empty() == true);
    // assert(fl2.size() == 0 && fl2.empty() == true);
    // assert(fl3.size() == 0 && fl3.empty() == true);

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;
}
