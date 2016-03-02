/*
 * Copyright 2016 - Elton Viana
 */

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void Swap(T &x, T &y) {
    x += y, y = x - y, x -= y;
}

void SwapInt(int &x, int &y) {
    x += y, y = x - y, x -= y;
}

void SwapDbl(double &x, double &y) {
    x += y, y = x - y, x -= y;
}

int main() {
    int x = 5, y = 7;
    double a = 2.3, b = 4.5;

    cout << "Antes da troca:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    SwapInt(x, y);  // troca inteiros
    SwapDbl(a, b);  // troca números em ponto flutuante

    cout << "Depois da troca:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    return EXIT_SUCCESS;
}
