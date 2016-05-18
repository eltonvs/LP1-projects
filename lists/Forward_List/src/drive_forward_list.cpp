/*!
 *  @mainpage Forward List
 *  @authors Elton de Souza Vieira, Claudio Lima Bezerra
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
    Forward_list<int> fl2(fl1);
    Forward_list<int> fl3(std::move(fl1));
    Forward_list<int>::iterator it;
    Forward_list<int>::const_iterator cit;

    // Unity test #1: size()
    assert(fl1.size() == 0);
    assert(fl2.size() == 0);
    assert(fl3.size() == 0);

    // Unity test #2: empty()
    assert(fl1.empty() == true);
    assert(fl2.empty() == true);
    assert(fl3.empty() == true);

    // Unity test #3: push_front() consequences
    fl1.push_front(3);
    fl2.push_front(3);
    fl3.push_front(3);
    assert(fl1.size() == 1);       // size() to fl1
    assert(fl2.size() == 1);       // size() to fl2
    assert(fl3.size() == 1);       // size() to fl3
    assert(fl1.empty() == false);  // empty() to fl1
    assert(fl2.empty() == false);  // empty() to fl2
    assert(fl3.empty() == false);  // empty() to fl3
    assert(fl1.front() == 3);      // front() to fl1
    assert(fl2.front() == 3);      // front() to fl2
    assert(fl3.front() == 3);      // front() to fl3
    assert(fl1.back() == 3);       // back() to fl1
    assert(fl2.back() == 3);       // back() to fl2
    assert(fl3.back() == 3);       // back() to fl3

    // Unity test #4: push_back() consequences
    fl1.push_back(10);
    fl2.push_back(10);
    fl3.push_back(10);
    assert(fl1.size() == 2);       // size() to fl1
    assert(fl2.size() == 2);       // size() to fl2
    assert(fl3.size() == 2);       // size() to fl3
    assert(fl1.empty() == false);  // empty() to fl1
    assert(fl2.empty() == false);  // empty() to fl2
    assert(fl3.empty() == false);  // empty() to fl3
    assert(fl1.front() == 3);      // front() to fl1
    assert(fl2.front() == 3);      // front() to fl2
    assert(fl3.front() == 3);      // front() to fl3
    assert(fl1.back() == 10);      // back() to fl1
    assert(fl2.back() == 10);      // back() to fl2
    assert(fl3.back() == 10);      // back() to fl3

    // Unity test #5: pop_front() consequences
    fl1.pop_front();
    fl2.pop_front();
    fl3.pop_front();
    assert(fl1.size() == 1);       // size() to fl1
    assert(fl2.size() == 1);       // size() to fl2
    assert(fl3.size() == 1);       // size() to fl3
    assert(fl1.empty() == false);  // empty() to fl1
    assert(fl2.empty() == false);  // empty() to fl2
    assert(fl3.empty() == false);  // empty() to fl3
    assert(fl1.front() == 10);     // front() to fl1
    assert(fl2.front() == 10);     // front() to fl2
    assert(fl3.front() == 10);     // front() to fl3
    assert(fl1.back() == 10);      // back() to fl1
    assert(fl2.back() == 10);      // back() to fl2
    assert(fl3.back() == 10);      // back() to fl3

    fl1.push_front(3);
    fl2.push_front(3);
    fl3.push_front(3);

    // Unity test #6: pop_back() consequences
    fl1.pop_back();
    fl2.pop_back();
    fl3.pop_back();
    assert(fl1.size() == 1);       // size() to fl1
    assert(fl2.size() == 1);       // size() to fl2
    assert(fl3.size() == 1);       // size() to fl3
    assert(fl1.empty() == false);  // empty() to fl1
    assert(fl2.empty() == false);  // empty() to fl2
    assert(fl3.empty() == false);  // empty() to fl3
    assert(fl1.front() == 3);      // front() to fl1
    assert(fl2.front() == 3);      // front() to fl2
    assert(fl3.front() == 3);      // front() to fl3
    assert(fl1.back() == 3);       // back() to fl1
    assert(fl2.back() == 3);       // back() to fl2
    assert(fl3.back() == 3);       // back() to fl3

    // Unity test #7: clear() consequences
    fl1.clear();
    fl2.clear();
    fl3.clear();
    assert(fl1.size() == 0);      // size() to fl1
    assert(fl2.size() == 0);      // size() to fl2
    assert(fl3.size() == 0);      // size() to fl3
    assert(fl1.empty() == true);  // empty() to fl1
    assert(fl2.empty() == true);  // empty() to fl2
    assert(fl3.empty() == true);  // empty() to fl3

    // Unity test #8: push_back() and back()
    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
        assert(fl1.back() == i);
        assert(fl2.back() == i);
        assert(fl3.back() == i);
    }

    // Unity test #9: assign(), front() and pop_front();
    fl1.assign(100);
    fl2.assign(100);
    fl3.assign(100);
    for (i = 0; i < 10; i++) {
        assert(fl1.front() == 100);
        assert(fl2.front() == 100);
        assert(fl3.front() == 100);
        fl1.pop_front();
        fl2.pop_front();
        fl3.pop_front();
    }

    // Unity test #10: size() and empty() (after pop_front)
    assert(fl1.size() == 0);
    assert(fl2.size() == 0);
    assert(fl3.size() == 0);
    assert(fl1.empty() == true);
    assert(fl2.empty() == true);
    assert(fl3.empty() == true);

    // Unity test #11: assign() with initializer list
    fl1.assign({1, 2, 3, 4});
    fl2.assign({1, 2, 3, 4});
    fl3.assign({1, 2, 3, 4});
    for (i = 1; i < 5; i++) {
        assert(fl1.front() == i);
        assert(fl2.front() == i);
        assert(fl3.front() == i);
        fl1.pop_front();
        fl2.pop_front();
        fl3.pop_front();
    }

    // Unity test #12: size() and empty() (after pop_front) [2]
    assert(fl1.size() == 0);
    assert(fl2.size() == 0);
    assert(fl3.size() == 0);
    assert(fl1.empty() == true);
    assert(fl2.empty() == true);
    assert(fl3.empty() == true);

    // Unity test #13: assign() w/ initializer_list, insert_after(),
    // --------------- before_begin(), begin(), operators (prefix ++ and !=),
    // --------------- end(), front() and pop_front()
    fl1.assign({1, 2, 3, 4, 5, 6});
    fl2.assign({1, 2, 3, 4, 5, 6});
    fl3.assign({1, 2, 3, 4, 5, 6});
    // To fl1
    it = fl1.insert_after(fl1.before_begin(), 0);
    for (it = fl1.begin(), i = 0; it != fl1.end(); ++it, i++) {
        assert(fl1.front() == i);
        fl1.pop_front();
    }
    assert(i == 7);
    // To fl2
    it = fl2.insert_after(fl2.before_begin(), 0);
    for (it = fl2.begin(), i = 0; it != fl2.end(); ++it, i++) {
        assert(fl2.front() == i);
        fl2.pop_front();
    }
    assert(i == 7);
    // To fl3
    it = fl3.insert_after(fl3.before_begin(), 0);
    for (it = fl3.begin(), i = 0; it != fl3.end(); ++it, i++) {
        assert(fl3.front() == i);
        fl3.pop_front();
    }
    assert(i == 7);

    // Unity test #14: assign() w/ initializer_list, insert_after(),
    // --------------- before_begin(), cbegin(), operators (postfix ++ and !=),
    // --------------- cend(), front() and pop_front()
    fl1.assign({1, 2, 3, 4, 5, 6});
    fl2.assign({1, 2, 3, 4, 5, 6});
    fl3.assign({1, 2, 3, 4, 5, 6});
    // To fl1
    it = fl1.insert_after(fl1.before_begin(), 0);
    for (cit = fl1.cbegin(), i = 0; cit != fl1.cend(); cit++, i++) {
        assert(fl1.front() == i);
        fl1.pop_front();
    }
    assert(i == 7);
    // To fl2
    it = fl2.insert_after(fl2.before_begin(), 0);
    for (cit = fl2.cbegin(), i = 0; cit != fl2.cend(); cit++, i++) {
        assert(fl2.front() == i);
        fl2.pop_front();
    }
    assert(i == 7);
    // To fl3
    it = fl3.insert_after(fl3.before_begin(), 0);
    for (cit = fl3.cbegin(), i = 0; cit != fl3.cend(); cit++, i++) {
        assert(fl3.front() == i);
        fl3.pop_front();
    }
    assert(i == 7);

    // Unit test #15: erase_after() with only one iterator and cbefore_begin()
    // Fill List
    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
    }
    it = fl1.erase_after(fl1.cbefore_begin());
    it = fl2.erase_after(fl2.cbefore_begin());
    it = fl3.erase_after(fl3.cbefore_begin());
    assert(fl1.size() == 9);       // Test for fl1
    assert(fl2.size() == 9);       // Test for fl2
    assert(fl3.size() == 9);       // Test for fl3
    assert(fl1.empty() == false);  // Test for fl1
    assert(fl2.empty() == false);  // Test for fl2
    assert(fl3.empty() == false);  // Test for fl3
    assert(fl1.front() == 1);      // Test for fl1
    assert(fl2.front() == 1);      // Test for fl2
    assert(fl3.front() == 1);      // Test for fl3
    assert(fl1.back() == 9);       // Test for fl1
    assert(fl2.back() == 9);       // Test for fl2
    assert(fl3.back() == 9);       // Test for fl3

    // Clear List content
    fl1.clear();
    fl2.clear();
    fl3.clear();

    // Unit test #16: erase_after() with the begin and end iterators
    // Fill List
    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
    }
    it = fl1.erase_after(fl1.cbegin(), fl1.cend());
    it = fl2.erase_after(fl2.cbegin(), fl2.cend());
    it = fl3.erase_after(fl3.cbegin(), fl3.cend());
    assert(fl1.size() == 1);       // Test for fl1
    assert(fl2.size() == 1);       // Test for fl2
    assert(fl3.size() == 1);       // Test for fl3
    assert(fl1.empty() == false);  // Test for fl1
    assert(fl2.empty() == false);  // Test for fl2
    assert(fl3.empty() == false);  // Test for fl3
    assert(fl1.front() == 0);      // Test for fl1
    assert(fl2.front() == 0);      // Test for fl2
    assert(fl3.front() == 0);      // Test for fl3
    assert(fl1.back() == 0);       // Test for fl1
    assert(fl2.back() == 0);       // Test for fl2
    assert(fl3.back() == 0);       // Test for fl3

    // Clear List content
    fl1.clear();
    fl2.clear();

    // Unit test #17: find()
    // Fill List
    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
    }
    for (i = 0; i < 10; i++) {
        assert(*fl1.find(i) == i);
        assert(*fl2.find(i) == i);
        assert(*fl3.find(i) == i);
    }

    // Clear List content
    fl1.clear();
    fl2.clear();

    // Put elements on list to test memory leak
    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
    }

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;
}
