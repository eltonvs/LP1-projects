// Copyright - 2016

#include <iostream>

#include "queue.hpp"

int main(int argc, char const *argv[]) {
    Queue<int> my_queue(10);

    my_queue.enqueue(1);
    my_queue.enqueue(2);
    my_queue.enqueue(3);

    return EXIT_SUCCESS;
}
