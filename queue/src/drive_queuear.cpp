// Copyright - 2016

#include <iostream>
#include <cassert>

#include "queuear.hpp"

int main(int argc, char const *argv[]) {
    auto sz(10);
    QueueAr<int> my_queue(sz);

    // Unity Test #1: isEmpty method
    assert(my_queue.isEmpty() == true);

    my_queue.enqueue(1);
    my_queue.enqueue(20);
    my_queue.enqueue(3);

    // Unity Test #2: isEmpty method
    assert(my_queue.isEmpty() == false);
    // Unity Test #3: getFront method
    assert(my_queue.getFront() == 1);
    // Unity Test #4: dequeue method
    assert(my_queue.dequeue() == 1);
    // Unity Test #5: getFront method
    assert(my_queue.getFront() == 20);

    my_queue.makeEmpty();

    // Unity Test #6: makeEmpty() method
    assert(my_queue.isEmpty() == true);

    return EXIT_SUCCESS;
}
