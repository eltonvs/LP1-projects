#ifndef _COMPACT_H_
#define _COMPACT_H_

#include <vector>

// Function prototypes.
template <typename T>
void compact(std::vector<T> &, bool (*)(T));

#include "compact.inl"

#endif
