#include <vector>

#include "compact.h"

template <typename T>
void compact(std::vector<T> &_V, bool (*predicate)(T)) {
    auto iSlow(0ul);
    auto iFast(0ul);
    for (/* empty */; iFast < _V.size(); ++iFast) {
        if (predicate(_V[iFast]))
            _V[iSlow++] = _V[iFast];
    }
    _V.resize(iSlow); // New vector size.
}
