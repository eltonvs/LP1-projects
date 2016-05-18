/*!
 *  @mainpage List
 *  @authors Elton de Souza Vieira, Claudio Lima Bezerra
 *  @date May, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive_list.cpp
 *  @brief Driver File
 *
 *  File with the List tests
 */

#include <iostream>
#include <cassert>
#include "list.hpp"

int main(int argc, char const *argv[]) {
    int i;
    List<int> l1;
    List<int> l2(l1);
    List<int> l3(std::move(l1));
    List<int>::iterator it;
    List<int>::const_iterator cit;

    // Unity test #1: size()
    assert(l1.size() == 0);
    assert(l2.size() == 0);
    assert(l3.size() == 0);

    // Unity test #2: empty()
    assert(l1.empty() == true);
    assert(l2.empty() == true);
    assert(l3.empty() == true);

    // Unity test #3: push_front() consequences
    l1.push_front(3);
    l2.push_front(3);
    l3.push_front(3);
    assert(l1.size() == 1);       // size() to l1
    assert(l2.size() == 1);       // size() to l2
    assert(l3.size() == 1);       // size() to l3
    assert(l1.empty() == false);  // empty() to l1
    assert(l2.empty() == false);  // empty() to l2
    assert(l3.empty() == false);  // empty() to l3
    assert(l1.front() == 3);      // front() to l1
    assert(l2.front() == 3);      // front() to l2
    assert(l3.front() == 3);      // front() to l3
    assert(l1.back() == 3);       // back() to l1
    assert(l2.back() == 3);       // back() to l2
    assert(l3.back() == 3);       // back() to l3

    // Unity test #4: push_back() consequences
    l1.push_back(10);
    l2.push_back(10);
    l3.push_back(10);
    assert(l1.size() == 2);       // size() to l1
    assert(l2.size() == 2);       // size() to l2
    assert(l3.size() == 2);       // size() to l3
    assert(l1.empty() == false);  // empty() to l1
    assert(l2.empty() == false);  // empty() to l2
    assert(l3.empty() == false);  // empty() to l3
    assert(l1.front() == 3);      // front() to l1
    assert(l2.front() == 3);      // front() to l2
    assert(l3.front() == 3);      // front() to l3
    assert(l1.back() == 10);      // back() to l1
    assert(l2.back() == 10);      // back() to l2
    assert(l3.back() == 10);      // back() to l3

    // Unity test #5: pop_front() consequences
    l1.pop_front();
    l2.pop_front();
    l3.pop_front();
    assert(l1.size() == 1);       // size() to l1
    assert(l2.size() == 1);       // size() to l2
    assert(l3.size() == 1);       // size() to l3
    assert(l1.empty() == false);  // empty() to l1
    assert(l2.empty() == false);  // empty() to l2
    assert(l3.empty() == false);  // empty() to l3
    assert(l1.front() == 10);     // front() to l1
    assert(l2.front() == 10);     // front() to l2
    assert(l3.front() == 10);     // front() to l3
    assert(l1.back() == 10);      // back() to l1
    assert(l2.back() == 10);      // back() to l2
    assert(l3.back() == 10);      // back() to l3

    l1.push_front(3);
    l2.push_front(3);
    l3.push_front(3);

    // Unity test #6: pop_back() consequences
    l1.pop_back();
    l2.pop_back();
    l3.pop_back();
    assert(l1.size() == 1);       // size() to l1
    assert(l2.size() == 1);       // size() to l2
    assert(l3.size() == 1);       // size() to l3
    assert(l1.empty() == false);  // empty() to l1
    assert(l2.empty() == false);  // empty() to l2
    assert(l3.empty() == false);  // empty() to l3
    assert(l1.front() == 3);      // front() to l1
    assert(l2.front() == 3);      // front() to l2
    assert(l3.front() == 3);      // front() to l3
    assert(l1.back() == 3);       // back() to l1
    assert(l2.back() == 3);       // back() to l2
    assert(l3.back() == 3);       // back() to l3

    // Unity test #7: clear() consequences
    l1.clear();
    l2.clear();
    l3.clear();
    assert(l1.size() == 0);      // size() to l1
    assert(l2.size() == 0);      // size() to l2
    assert(l3.size() == 0);      // size() to l3
    assert(l1.empty() == true);  // empty() to l1
    assert(l2.empty() == true);  // empty() to l2
    assert(l3.empty() == true);  // empty() to l3

    // Unity test #8: push_back() and back()
    for (i = 0; i < 10; i++) {
        l1.push_back(i);
        l2.push_back(i);
        l3.push_back(i);
        assert(l1.back() == i);
        assert(l2.back() == i);
        assert(l3.back() == i);
    }

    // Unity test #9: assign(), front() and pop_front();
    l1.assign(100);
    l2.assign(100);
    l3.assign(100);
    for (i = 0; i < 10; i++) {
        assert(l1.front() == 100);
        assert(l2.front() == 100);
        assert(l3.front() == 100);
        l1.pop_front();
        l2.pop_front();
        l3.pop_front();
    }

    // Unity test #10: size() and empty() (after pop_front)
    assert(l1.size() == 0);
    assert(l2.size() == 0);
    assert(l3.size() == 0);
    assert(l1.empty() == true);
    assert(l2.empty() == true);
    assert(l3.empty() == true);

    // Unity test #11: assign() with initializer list
    l1.assign({1, 2, 3, 4});
    l2.assign({1, 2, 3, 4});
    l3.assign({1, 2, 3, 4});
    for (i = 1; i < 5; i++) {
        assert(l1.front() == i);
        assert(l2.front() == i);
        assert(l3.front() == i);
        l1.pop_front();
        l2.pop_front();
        l3.pop_front();
    }

    // Unity test #12: size() and empty() (after pop_front) [2]
    assert(l1.size() == 0);
    assert(l2.size() == 0);
    assert(l3.size() == 0);
    assert(l1.empty() == true);
    assert(l2.empty() == true);
    assert(l3.empty() == true);

    // Unity test #13: assign() w/ initializer_list, insert_after(),
    // --------------- before_begin(), begin(), operators (prefix ++ and !=),
    // --------------- end(), front() and pop_front()
    l1.assign({1, 2, 3, 4, 5, 6});
    l2.assign({1, 2, 3, 4, 5, 6});
    l3.assign({1, 2, 3, 4, 5, 6});
    // To l1
    it = l1.insert_after(l1.before_begin(), 0);
    for (it = l1.begin(), i = 0; it != l1.end(); ++it, i++) {
        assert(l1.front() == i);
        l1.pop_front();
    }
    assert(i == 7);
    // To l2
    it = l2.insert_after(l2.before_begin(), 0);
    for (it = l2.begin(), i = 0; it != l2.end(); ++it, i++) {
        assert(l2.front() == i);
        l2.pop_front();
    }
    assert(i == 7);
    // To l3
    it = l3.insert_after(l3.before_begin(), 0);
    for (it = l3.begin(), i = 0; it != l3.end(); ++it, i++) {
        assert(l3.front() == i);
        l3.pop_front();
    }
    assert(i == 7);

    // Unity test #14: assign() w/ initializer_list, insert_after(),
    // --------------- before_begin(), cbegin(), operators (postfix ++ and !=),
    // --------------- cend(), front() and pop_front()
    l1.assign({1, 2, 3, 4, 5, 6});
    l2.assign({1, 2, 3, 4, 5, 6});
    l3.assign({1, 2, 3, 4, 5, 6});
    // To l1
    it = l1.insert_after(l1.before_begin(), 0);
    for (cit = l1.cbegin(), i = 0; cit != l1.cend(); cit++, i++) {
        assert(l1.front() == i);
        l1.pop_front();
    }
    assert(i == 7);
    // To l2
    it = l2.insert_after(l2.before_begin(), 0);
    for (cit = l2.cbegin(), i = 0; cit != l2.cend(); cit++, i++) {
        assert(l2.front() == i);
        l2.pop_front();
    }
    assert(i == 7);
    // To l3
    it = l3.insert_after(l3.before_begin(), 0);
    for (cit = l3.cbegin(), i = 0; cit != l3.cend(); cit++, i++) {
        assert(l3.front() == i);
        l3.pop_front();
    }
    assert(i == 7);

    // Unit test #15: erase_after() with only one iterator and cbefore_begin()
    // Fill List
    for (i = 0; i < 10; i++) {
        l1.push_back(i);
        l2.push_back(i);
        l3.push_back(i);
    }
    it = l1.erase_after(l1.cbefore_begin());
    it = l2.erase_after(l2.cbefore_begin());
    it = l3.erase_after(l3.cbefore_begin());
    assert(l1.size() == 9);       // Test for l1
    assert(l2.size() == 9);       // Test for l2
    assert(l3.size() == 9);       // Test for l3
    assert(l1.empty() == false);  // Test for l1
    assert(l2.empty() == false);  // Test for l2
    assert(l3.empty() == false);  // Test for l3
    assert(l1.front() == 1);      // Test for l1
    assert(l2.front() == 1);      // Test for l2
    assert(l3.front() == 1);      // Test for l3
    assert(l1.back() == 9);       // Test for l1
    assert(l2.back() == 9);       // Test for l2
    assert(l3.back() == 9);       // Test for l3

    // Clear List content
    l1.clear();
    l2.clear();
    l3.clear();

    // Unit test #16: erase_after() with the begin and end iterators
    // Fill List
    for (i = 0; i < 10; i++) {
        l1.push_back(i);
        l2.push_back(i);
        l3.push_back(i);
    }
    it = l1.erase_after(l1.cbegin(), l1.cend());
    it = l2.erase_after(l2.cbegin(), l2.cend());
    it = l3.erase_after(l3.cbegin(), l3.cend());
    assert(l1.size() == 1);       // Test for l1
    assert(l2.size() == 1);       // Test for l2
    assert(l3.size() == 1);       // Test for l3
    assert(l1.empty() == false);  // Test for l1
    assert(l2.empty() == false);  // Test for l2
    assert(l3.empty() == false);  // Test for l3
    assert(l1.front() == 0);      // Test for l1
    assert(l2.front() == 0);      // Test for l2
    assert(l3.front() == 0);      // Test for l3
    assert(l1.back() == 0);       // Test for l1
    assert(l2.back() == 0);       // Test for l2
    assert(l3.back() == 0);       // Test for l3

    // Clear List content
    l1.clear();
    l2.clear();

    // Unit test #17: find()
    // Fill List
    for (i = 0; i < 10; i++) {
        l1.push_back(i);
        l2.push_back(i);
        l3.push_back(i);
    }
    for (i = 0; i < 10; i++) {
        assert(*l1.find(i) == i);
        assert(*l2.find(i) == i);
        assert(*l3.find(i) == i);
    }

    // Clear List content
    l1.clear();
    l2.clear();

    // Put elements on list to test memory leak
    for (i = 0; i < 10; i++) {
        l1.push_back(i);
        l2.push_back(i);
        l3.push_back(i);
    }

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;
}
