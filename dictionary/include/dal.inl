/**
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
template < typename Key, typename Data >
DAL<Key,Data>::DAL(int _iMaxSz):
    mi_Length(0),         // Tamanho logico.
    mi_Capacity(_iMaxSz), // Guardar capacidade atual.
    mpt_Data(nullptr)
{
    if (_iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[_iMaxSz]; // Tamanho maximo.
}

template < typename Key, typename Data >
bool DAL<Key,Data>::insert(const Key &_novaId, const Data &_novaInfo) {
    if (mi_Length < mi_Capacity) {
        mpt_Data[mi_Length].id   = _novaId;
        mpt_Data[mi_Length].info = _novaInfo;
        mi_Length++;
        return true;
    }
    return false;
}
