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
    int i;
    Forward_list<int> fl1;
    Forward_list<int>::iterator it;
    Forward_list<int>::const_iterator cit;

    // Unity test #1: size()
    assert(fl1.size() == 0);

    // Unity test #2: empty()
    assert(fl1.empty() == true);

    // Unity test #3: push_front() consequences
    fl1.push_front(3);
    assert(fl1.size() == 1);       // size()
    assert(fl1.empty() == false);  // empty()
    assert(fl1.front() == 3);      // front()
    assert(fl1.back() == 3);       // back()

    // Unity test #4: push_back() consequences
    fl1.push_back(10);
    assert(fl1.size() == 2);       // size()
    assert(fl1.empty() == false);  // empty()
    assert(fl1.front() == 3);      // front()
    assert(fl1.back() == 10);      // back()

    // Unity test #5: pop_front() consequences
    fl1.pop_front();
    assert(fl1.size() == 1);       // size()
    assert(fl1.empty() == false);  // empty()
    assert(fl1.front() == 10);     // front()
    assert(fl1.back() == 10);      // back()

    fl1.push_front(3);

    // Unity test #6: pop_back() consequences
    fl1.pop_back();
    assert(fl1.size() == 1);       // size()
    assert(fl1.empty() == false);  // empty()
    assert(fl1.front() == 3);      // front()
    assert(fl1.back() == 3);       // back()

    // Unity test #7: clear() consequences
    fl1.clear();
    assert(fl1.size() == 0);      // size()
    assert(fl1.empty() == true);  // empty()

    // Unity test #8: push_back() and back()
    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        assert(fl1.back() == i);
    }

    // Unity test #9: assign(), front() and pop_front();
    fl1.assign(100);
    for (i = 0; i < 10; i++) {
        assert(fl1.front() == 100);
        fl1.pop_front();
    }

    // Unity test #10: size() and empty() (after pop_front)
    assert(fl1.size() == 0);
    assert(fl1.empty() == true);

    // Unity test #11: assign() with initializer list
    fl1.assign({1, 2, 3, 4});
    for (i = 1; i < 5; i++) {
        assert(fl1.front() == i);
        fl1.pop_front();
    }

    // Unity test #12: size() and empty() (after pop_front) [2]
    assert(fl1.size() == 0);
    assert(fl1.empty() == true);

    // Unity test #13: assign() w/ initializer_list, insert_after(),
    // --------------- before_begin(), begin(), operators (prefix ++ and !=),
    // --------------- end(), front() and pop_front()
    fl1.assign({1, 2, 3, 4, 5, 6});
    it = fl1.insert_after(fl1.before_begin(), 0);
    for (it = fl1.begin(), i = 0; it != fl1.end(); ++it, i++) {
        assert(fl1.front() == i);
        fl1.pop_front();
    }
    assert(i == 7);

    // Unity test #14: assign() w/ initializer_list, insert_after(),
    // --------------- before_begin(), cbegin(), operators (postfix ++ and !=),
    // --------------- cend(), front() and pop_front()
    fl1.assign({1, 2, 3, 4, 5, 6});
    it = fl1.insert_after(fl1.before_begin(), 0);
    for (cit = fl1.cbegin(), i = 0; cit != fl1.cend(); cit++, i++) {
        assert(fl1.front() == i);
        fl1.pop_front();
    }
    assert(i == 7);

    // Put elements on list to test memory leak
    for (i = 0; i < 10; i++)
        fl1.push_back(i);

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;
}
