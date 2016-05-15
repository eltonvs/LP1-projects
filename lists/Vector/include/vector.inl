/*!
 *  @file vector.inl
 *  @brief Vector Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with Vector ADT implementations
 */

#include <memory>
#include "vector.hpp"

// Constructor
template <typename T>
Vector<T>::Vector(size_type _sz) : m_capacity(_sz), m_list(new T[_sz]) {}

// Get the Vector size
template <typename T>
size_type Vector<T>::size() const {
    return m_size;
}

// Clear Vector
template <typename T>
void Vector<T>::clear() {
    while (m_size > 0)
        (&m_list[--m_size])->~T();
}

// Push Back
template <typename T>
void Vector<T>::push_back(const T &_x) {
    if (m_size >= m_capacity)
        _dbl_capacity();
    m_list[m_size++] = _x;
}

// Pop Back
template <typename T>
void Vector<T>::pop_back() {
    (&m_list[--m_size])->~T();
}

// Double Capacity
template <typename T>
void Vector<T>::_dbl_capacity() {
    // Creates a new unique_ptr with a bigger size
    std::unique_ptr<T[]> cpy_list(new T[m_capacity * 2]);
    // Copy vector content to cpy_list and calls your destructor
    for (auto i(0u); i < m_size; i++) {
        cpy_list[i] = m_list[i];
        (&m_list[i])->~T();
    }
    // Moves the cpy_list to m_list
    m_list = std::move(cpy_list);
    // Sets the new capacity value
    m_capacity *= 2;
}
