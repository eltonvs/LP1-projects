/*
 * Copyright 2016 - Elton Viana
 */

#include <iostream>

using std::cout;
using std::endl;

namespace myMaxMin {
    template <typename T>
    T max(T x, T y) {
        return x > y ? x : y;
    }

    template <typename T>
    T min(T x, T y) {
        return x < y ? x : y;
    }
}

int main() {
    int x = 5, y = 7;
    double a = 2.3, b = 4.5;
    char r = 'a', s = 'z';

    cout << "Before swap:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    cout << "(x, y) = (" << x << ", " << y << ")" << endl;
    cout << "(a, b) = (" << a << ", " << b << ")" << endl;
    cout << "(r, s) = (" << r << ", " << s << ")" << endl;

    cout << ">>> Max(x, y) = " << myMaxMin::max(x, y) << endl;
    cout << ">>> Max(a, b) = " << myMaxMin::max(a, b) << endl;
    cout << ">>> Max(r, s) = " << myMaxMin::max(r, s) << endl;
    cout << ">>> Min(x, y) = " << myMaxMin::min(x, y) << endl;
    cout << ">>> Min(a, b) = " << myMaxMin::min(a, b) << endl;
    cout << ">>> Min(r, s) = " << myMaxMin::min(r, s) << endl;

    return EXIT_SUCCESS;
}
