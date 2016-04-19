// This is a stub code (or skeleton code) just to allow the first compilation.

#include <iostream>
#include "les_v1.h"

//! Prints the list.
/*! This a debugging function that prints the list content.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 */
void print(SNPtr _pAIL) {
    std::cout << "List Content = [ ";
    while (_pAIL != NULL) {
        std::cout << _pAIL->miData << " ";
        _pAIL = _pAIL->mpNext;
    }
    std::cout << "]\n";
}

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
int length(SNPtr _pAIL) {
    auto i(0u);
    while (_pAIL != NULL) _pAIL = _pAIL->mpNext, i++;
    return i;
}

bool empty(SNPtr _pAIL) {
    return length(_pAIL) == 0;
}

void clear(SNPtr &_pAIL) {
    if (_pAIL != NULL) {
        while (_pAIL->mpNext != NULL)
            clear(_pAIL->mpNext);
        delete _pAIL;
        _pAIL = NULL;
    }
}

bool front(SNPtr _pAIL, int &_retrievedVal) {
    if (_pAIL != NULL) {
        _retrievedVal = _pAIL->miData;

        return true;
    }

    return false;
}

bool back(SNPtr _pAIL, int &_retrievedVal) {
    if (_pAIL != NULL) {
        while(_pAIL->mpNext != NULL)
            _pAIL = _pAIL->mpNext,
            _retrievedVal = _pAIL->miData;
        return true;
    }

    return false;
}

bool pushFront(SNPtr &_pAIL, int _newVal) {
    SNPtr aux = new SLLNode;
    aux->miData = _newVal;
    aux->mpNext = _pAIL;
    _pAIL = aux;

    return true;
}

bool pushBack(SNPtr &_pAIL, int _newVal) {
    if (_pAIL == NULL) {
        pushFront(_pAIL, _newVal);
    } else {
        SNPtr aux = _pAIL;
        while (_pAIL->mpNext != NULL)
            _pAIL = _pAIL->mpNext;
        pushFront(_pAIL->mpNext, _newVal);
        _pAIL = aux;
    }
    return true;
}

bool popFront(SNPtr &_pAIL, int &_retrievedVal) {
    return true;
}

bool popBack(SNPtr &_pAIL, int&_retrievedVal) {
    return true;
}

SNPtr find(SNPtr _pAIL, int _targetVal) {
    return NULL;
}

bool insert(SNPtr &_pAIL, SNPtr _pAnte, int _newVal) {
    return true;
}

bool remove(SNPtr &_pAIL, SNPtr _pAnte, int &_retrievedVal) {
    return true;
}

//**** ===================[ End of les_v1.cpp ]=================== ****//
