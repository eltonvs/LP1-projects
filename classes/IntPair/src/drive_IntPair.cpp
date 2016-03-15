// Copyright - 2016

#include <iostream>
#include <cassert>

#include "IntPair.h"

int main(int argc, char const *argv[]) {
    IntPair p1(2, 3);

    // Unit test #1: constructor
    assert(p1.get_first() == 2);
    assert(p1.get_second() == 3);

    std::cout << "The pair p1 is: " << p1.print() << std::endl;

    p1.set_first(-3);  // Sets the first element of the pair
    p1.set_second(0);  // Sets the second element of the pair

    // Unit test #2: get functions
    auto x = p1.get_first();
    assert(x == -3);
    auto y = p1.get_second();
    assert(y == 0);

    p1.set(-3, 0);  // Sets both element of the pair
    // Unit test #3: set()
    assert(p1.get_first() == -3);
    assert(p1.get_second() == 0);

    int z1, z2;
    p1.get(z1, z2);  // Recover both values of the pair

    // std::cout << "The pair p1 is: " << p1 << std::endl;

    IntPair p2(p1);
    // Unit test #4: constructor (with a object)
    assert(p2.get_first() == p1.get_first());
    assert(p2.get_second() == p1.get_second());

    IntPair p3 = p2;
    // Unit test #5: operator
    assert(p3.get_first() == p2.get_first());
    assert(p3.get_second() == p2.get_second());

    IntPair p4(0, 0);
    // Unit test #6: constructor
    assert(p4.get_first() == 0);
    assert(p4.get_second() == 0);

    p4 = p2 + p3;
    // Unit test #7: operator
    assert(p4.get_first() == p2.get_first() + p3.get_first());
    assert(p4.get_second() == p2.get_second() + p3.get_second());

    if (p1 == p3) {
        std::cout << ">>> p1 and p3 are equals\n";
        assert(p1.get_first() == p3.get_first());
        assert(p1.get_second() == p3.get_second());
    } else {
        std::cout << ">>> p1 and p3 are differents\n";
        assert(p1.get_first() != p3.get_first());
        assert(p1.get_second() != p3.get_second());
    }

    // Switch elements of the pair
    p3.flip();

    std::cout << "The pair p1 is: " << p1.print() << std::endl;
    std::cout << "The pair p2 is: " << p2.print() << std::endl;
    std::cout << "The pair p3 is: " << p3.print() << std::endl;
    std::cout << "The pair p4 is: " << p4.print() << std::endl;

    return EXIT_SUCCESS;
}
