/*
 * Copyright 2016 - Elton Viana
 */

#include <iostream>

using std::cout;
using std::endl;

namespace mySwap {
    template <typename T>
    void swap(T &x, T &y) {
        x += y, y = x - y, x -= y;
    }
}

int main() {
    int x = 5 , y = 7;
    double a = 2.3 , b = 4.5;

    cout << "Before swap:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    mySwap::swap(x, y);
    mySwap::swap(a, b);

    cout << "After swap:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    return EXIT_SUCCESS;
}
