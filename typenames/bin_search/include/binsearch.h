/*
 * Copyright 2016 - Elton Viana
 */

#ifndef _BINSEARCH_H_
#define _BINSEARCH_H_

// Function prototypes.
template <typename T>
int buscaBin(T[], T &, int, int, int (*)(const T &, const T &));

template <typename T>
void printArray(const T[], int);

template <typename T>
int compara(const T &, const T &);

#include "binsearch.inl"

#endif
