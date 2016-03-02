#ifndef _BINSEARCH_H_
#define _BINSEARCH_H_

#include <iostream>

// Function prototypes.
template <typename Obj>
int buscaBin(Obj, Obj &, int, int, int (*)(const Obj&, const Obj&));

#include "binsearch.inl"

#endif
