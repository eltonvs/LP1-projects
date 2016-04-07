// Copyright - 2016

#include "queue.hpp"

template <typename Data>
Queue<Data>::Queue(const int _SIZE) {
    m_SIZE = _SIZE;
    m_list = new Data[_SIZE];
}

template <typename Data>
bool Queue<Data>::enqueue(const Data _a) {
    if (m_f == -1) {
        m_f = m_b = 0, m_list[0] = _a;
        return true;
    }

    auto final_b = (m_b + 1)%m_SIZE;

    if (final_b == m_f)  // Vector is full
        return false;

    m_list[final_b] = _a, m_b = final_b;
}
