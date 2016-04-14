// Copyright - 2016

#include <stdexcept>

#include "queuear.hpp"

template <typename Object>
QueueAr<Object>::QueueAr(const int _sz) : m_SIZE(_sz) {
    if (_sz < 0)
        throw std::invalid_argument("[QueueAr()]: Invalid Queue size!");
    m_list = new Object[_sz];
}

template <typename Object>
QueueAr<Object>::~QueueAr() {
    delete m_list;
}

template <typename Object>
void QueueAr<Object>::enqueue(const Object &_x) {
    if (m_f == -1) {
        m_f = m_r = 0, m_list[0] = _x;
    } else {
        auto final_b = (m_r + 1)%m_SIZE;

        if (final_b == m_f)  // Vector is full
            throw std::out_of_range("[enqueue()]: The Queue is already fully!");

        m_list[final_b] = _x, m_r = final_b;
    }
}

template <typename Object>
Object QueueAr<Object>::dequeue() {
    if (isEmpty())
        throw std::out_of_range("[dequeue()]: The Queue is empty!");

    // Copy the front element
    Object _a = getFront();

    if (size() == 1)
        m_r = m_f = -1;
    else
        m_f = (m_f + 1)%m_SIZE;

    return _a;
}

template <typename Object>
Object QueueAr<Object>::getFront() const {
    if (isEmpty())
        throw std::out_of_range("[dequeue()]: The Queue is empty!");

    // Return the front element
    return m_list[m_f];
}

template <typename Object>
bool QueueAr<Object>::isEmpty() const {
    return m_f == -1;
}

template <typename Object>
void QueueAr<Object>::makeEmpty() {
    m_f = m_r = -1;
}

template <typename Object>
unsigned QueueAr<Object>::size() const {
    if (isEmpty())
        return 0;
    if (m_f > m_r)
        return m_SIZE - m_f + m_r + 1;
    return m_r - m_f + 1;
}
