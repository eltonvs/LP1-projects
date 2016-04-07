// Copyright - 2016

#include <iostream>

#include "queue.hpp"

int main(int argc, char const *argv[]) {
    auto sz(10);
    Queue<int> my_queue(sz);

    my_queue.enqueue(1);
    my_queue.enqueue(20);
    my_queue.enqueue(3);

    int a, b;
    my_queue.dequeue(a);
    my_queue.front(b);

    return EXIT_SUCCESS;
}
