// Copyright - 2016

#include "queue.hpp"

template <typename Data>
Queue<Data>::Queue(const int _SIZE) {
    m_SIZE = _SIZE;
    m_list = new Data[_SIZE];
}

template <typename Data>
bool Queue<Data>::enqueue(const Data &_a) {
    if (m_f == -1) {
        m_f = m_r = 0, m_list[0] = _a;
        return true;
    }

    auto final_b = (m_r + 1)%m_SIZE;

    if (final_b == m_f)  // Vector is full
        return false;

    m_list[final_b] = _a, m_r = final_b;

    return true;
}

template <typename Data>
bool Queue<Data>::dequeue(Data &_a) {
    auto queue_sz = size();
    if (queue_sz == 0)  // Lista Vazia
        return false;

    // Copy the front element
    front(_a);

    if (queue_sz == 1)
        m_r = m_f = -1;
    else
        m_f = (m_f + 1)%m_SIZE;

    return true;
}

template <typename Data>
bool Queue<Data>::front(Data &_a) const {
    auto queue_sz = size();
    if (queue_sz == 0) {
        // Lista Vazia
        return false;
    }

    // Copy the front element
    _a = m_list[m_f];
    return true;
}

template <typename Data>
unsigned Queue<Data>::size(void) const {
    if (m_f == -1)  // Lista Vazia
        return 0;
    if (m_f > m_r)
        return m_SIZE - m_f + m_r + 1;
    return m_r - m_f + 1;
}
