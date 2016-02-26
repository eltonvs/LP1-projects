#include <cmath>

bool predicateNegatives(int _a) {
    return _a < 0;
}

bool predicateLessThan50(int _a) {
    return _a < 50;
}

bool predicateEven(int _a) {
    return !(_a&1);
}

bool predicatePrime(int _a) {
    for (int i = 2; i <= sqrt(_a); i++)
        if (!(_a%i)) return false;
    return _a > 1;
}