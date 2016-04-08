/**
 * Copyright 2016
 *
 * DAL class implementation.
 *
 */

#include "dal.hpp"

/**
 * ---------------------------------------------------------------------------
 * Common methods from DAL.
 * ---------------------------------------------------------------------------
 */

// Construtor inicializa TAD.
template <typename Key, typename Data>
DAL<Key, Data>::DAL(int _iMaxSz):
    mi_Length(0),         // Tamanho logico.
    mi_Capacity(_iMaxSz), // Guardar capacidade atual.
    mpt_Data(nullptr)
{
    if (_iMaxSz < 0)  // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[_iMaxSz]; // Tamanho maximo.
}

template <typename Key, typename Data>
int DAL<Key, Data>::_search(Key _x) const {
    int i;
    for (i = 0; mpt_Data[i].id != _x and i < mi_Length; i++);

    return i;
}

template <typename Key, typename Data>
bool DAL<Key, Data>::search(const Key &_x, const Data &_y) const {
    int pos = _search(_x);

    return pos != mi_Length;
}

template <typename Key, typename Data>
bool DAL<Key, Data>::insert(const Key &_novaId, const Data &_novaInfo) {
    if (mi_Length < mi_Capacity) {
        int pos = _search(_novaId);
        mpt_Data[pos].id   = _novaId;
        mpt_Data[pos].info = _novaInfo;
        if (pos == mi_Length)
            mi_Length++;

        return true;
    }

    return false;
}

template <typename Key, typename Data>
bool DAL<Key, Data>::remove(const Key &_x, Data &_y) {
    int pos = _search(_x);
    if (pos != mi_Length) {
        mpt_Data[pos] = mpt_Data[--mi_Length];

        return true;
    }

    return false;
}

/**
 * ---------------------------------------------------------------------------
 * Methods from DSAL.
 * ---------------------------------------------------------------------------
 */

template <typename Key, typename Data>
int DSAL<Key, Data>::_search(const Key &_x) const {
    auto sz = DAL<Key, Data>::mi_Length;
    auto l = 0, r = sz - 1;

    while (l <= r) {
        int m = (l+r)/2;
        auto at = DAL<Key, Data>::mpt_Data[m].id;
        if (at == _x)
            return m;
        else if (at < _x)
            l = m+1;
        else
            r = m-1;
    }

    return sz;
}

template <typename Key, typename Data>
bool DSAL<Key, Data>::insert(const Key &_novaId, const Data &_novaInfo) {
    auto &length  = DAL<Key, Data>::mi_Length,
         capacity = DAL<Key, Data>::mi_Capacity,
         &data    = DAL<Key, Data>::mpt_Data;

    if (length < capacity) {
        auto pos = _search(_novaId);

        // Verify if the the key is already in dict
        if (pos != length) return false;

        auto i = length;
        while (i > 0 and data[i-1].id > _novaId)
            data[i] = data[i-1], i--;
        data[i].id = _novaId, data[i].info = _novaInfo, length++;

        return true;
    }

    return false;
}

template <typename Key, typename Data>
bool DSAL<Key, Data>::remove(const Key &_x, Data &_y) {
    auto &length = DAL<Key, Data>::mi_Length,
         &data   = DAL<Key, Data>::mpt_Data;

    int pos = _search(_x);
    if (pos != length) {
        _y = data[pos].info, length--;
        for (int i = pos; i < length; i++)
            data[i] = data[i+1];

        return true;
    }

    return false;
}

template <typename Key, typename Data>
Key DSAL<Key, Data>::min(void) const {
    return DAL<Key, Data>::mi_Length ? DAL<Key, Data>::mpt_Data[0].id : 0;
}

template <typename Key, typename Data>
Key DSAL<Key, Data>::max(void) const {
    return DAL<Key, Data>::mi_Length ? DAL<Key, Data>::mpt_Data[DAL<Key, Data>::mi_Length].id : 0;
}

template <typename Key, typename Data>
bool DSAL<Key, Data>::sucessor(const Key &_x, Key &_y) const {
    int pos = _search(_x);
    if (pos >= DAL<Key, Data>::mi_Length - 1)
        return false;

    _y = DAL<Key, Data>::mpt_Data[pos+1].id;

    return true;
}

template <typename Key, typename Data>
bool DSAL<Key, Data>::predecessor(const Key &_x, Key &_y) const {
    int pos = _search(_x);
    if (pos == 0 || pos == DAL<Key, Data>::mi_Length)
        return false;

    _y = DAL<Key, Data>::mpt_Data[pos-1].id;

    return true;
}
