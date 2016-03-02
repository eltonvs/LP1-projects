/*
 * Copyright 2016 - Elton Viana
 */

#include <iostream>
#include <functional>

using std::cout;
using std::endl;

namespace myFuncs {
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
};


int main() {
    auto a(5), b(10);

    cout << ">>> a = " << a << ", b = " << b << endl << endl;

    int (*func)(int, int) = nullptr;
    func = myFuncs::max;

    std::function<int(int, int)> func2  = myFuncs::min;
    func2(a, b);

    cout << ">>> Max (a, b): " << myFuncs::max(a, b) << endl;
    cout << ">>> Min (a, b): " << myFuncs::min(a, b) << endl;
    cout << ">>> Func (a, b): " << func(a, b) << endl;
    cout << ">>> Func2 (a, b): " << func2(a, b) << endl;


    return EXIT_SUCCESS;
}
