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
template <typename Key, typename Data, typename KeyComparator>
DAL<Key, Data, KeyComparator>::DAL(int _iMaxSz):
    mi_Length(0),         // Tamanho logico.
    mi_Capacity(_iMaxSz), // Guardar capacidade atual.
    mpt_Data(nullptr)
{
    if (_iMaxSz < 0)  // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[_iMaxSz]; // Tamanho maximo.
}

template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::compare(Key _x, Key _y) const {
    KeyComparator comp;
    auto r = comp(_x, _y);
    return r < 0 ? -1 : r > 0 ? 1 : 0;
}

template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::_search(Key _x) const {
    int i;
    for (i = 0; compare(mpt_Data[i].id, _x) != 0 and i < mi_Length; i++);

    return i;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::search(const Key &_x, const Data &_y) const {
    int pos = _search(_x);

    return pos != mi_Length;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::insert(const Key &_novaId, const Data &_novaInfo) {
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

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::remove(const Key &_x, Data &_y) {
    int pos = _search(_x);
    if (pos != mi_Length) {
        mpt_Data[pos] = mpt_Data[--mi_Length];

        return true;
    }

    return false;
}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::min(void) const {
    auto min(0);
    for (auto i(1u); i < mi_Length; i++)
        if (compare(mpt_Data[i].id, mpt_Data[min].id) == -1) min = i;
    return mi_Length ? mpt_Data[min].id : 0;
}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::max(void) const {
    auto max(0);
    for (auto i(1u); i < mi_Length; i++)
        if (compare(mpt_Data[i].id, mpt_Data[max].id) == 1) max = i;
    return mi_Length ? mpt_Data[max].id : 0;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::sucessor(const Key &_x, Key &_y) const {
    if (mi_Length > 1) {
        _y = max();
        if (_x == _y) return false;

        for (auto i(0u); i < mi_Length; i++)
            if (compare(mpt_Data[i].id, _x) == 1 && compare(mpt_Data[i].id, _y) == -1)
                _y = mpt_Data[i].id;

        return true;
    }

    return false;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::predecessor(const Key &_x, Key &_y) const {
    if (mi_Length > 1) {
        _y = min();

        if (_y == _x) return false;

        for (auto i(0u); i < mi_Length; i++)
            if (compare(mpt_Data[i].id, _x) == -1 && compare(mpt_Data[i].id, _y) == 1)
                _y = mpt_Data[i].id;

        return true;
    }

    return false;
}


/**
 * ---------------------------------------------------------------------------
 * Methods from DSAL.
 * ---------------------------------------------------------------------------
 */

template <typename Key, typename Data, typename KeyComparator>
int DSAL<Key, Data, KeyComparator>::_search(const Key &_x) const {
    auto sz = DAL<Key, Data, KeyComparator>::mi_Length, l  = 0, r = sz - 1;

    while (l <= r) {
        int m    = (l+r)/2;
        auto at  = DAL<Key, Data, KeyComparator>::mpt_Data[m].id,
             rst = DAL<Key, Data, KeyComparator>::compare(at, _x);
        if (rst == 0)
            return m;
        else if (rst < 0)
            l = m+1;
        else
            r = m-1;
    }

    return sz;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::insert(const Key &_novaId, const Data &_novaInfo) {
    auto &length  = DAL<Key, Data, KeyComparator>::mi_Length,
         capacity = DAL<Key, Data, KeyComparator>::mi_Capacity,
         &data    = DAL<Key, Data, KeyComparator>::mpt_Data;

    if (length < capacity) {
        auto pos = _search(_novaId);

        // Verify if the the key is already in dict
        if (pos != length) return false;

        auto i = length;
        while (i > 0 and DAL<Key, Data, KeyComparator>::compare(data[i-1].id, _novaId) == 1)
            data[i] = data[i-1], i--;
        data[i].id = _novaId, data[i].info = _novaInfo, length++;

        return true;
    }

    return false;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::remove(const Key &_x, Data &_y) {
    auto &length = DAL<Key, Data, KeyComparator>::mi_Length,
         &data   = DAL<Key, Data, KeyComparator>::mpt_Data;

    int pos = _search(_x);
    if (pos != length) {
        _y = data[pos].info, length--;
        for (int i = pos; i < length; i++)
            data[i] = data[i+1];

        return true;
    }

    return false;
}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::min(void) const {
    return DAL<Key, Data, KeyComparator>::mi_Length ? DAL<Key, Data, KeyComparator>::mpt_Data->id : 0;
}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::max(void) const {
    return DAL<Key, Data, KeyComparator>::mi_Length ? DAL<Key, Data, KeyComparator>::mpt_Data[DAL<Key, Data, KeyComparator>::mi_Length - 1].id : 0;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::sucessor(const Key &_x, Key &_y) const {
    int pos = _search(_x);
    if (pos >= DAL<Key, Data, KeyComparator>::mi_Length - 1)
        return false;

    _y = DAL<Key, Data, KeyComparator>::mpt_Data[pos+1].id;

    return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::predecessor(const Key &_x, Key &_y) const {
    int pos = _search(_x);
    if (pos == 0 || pos == DAL<Key, Data, KeyComparator>::mi_Length)
        return false;

    _y = DAL<Key, Data, KeyComparator>::mpt_Data[pos-1].id;

    return true;
}
