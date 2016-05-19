/*!
 *  @file vector.inl
 *  @brief Vector Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with Vector ADT implementations
 */

#include <memory>
#include "vector.hpp"

// Default Constructor
template <typename T>
Vector<T>::Vector(size_type _sz) : m_capacity(_sz), m_list(new T[_sz]) {}

// Copy Constructor
template <typename T>
Vector<T>::Vector(const Vector &_v) : m_capacity(_v.m_capacity), m_list(new T[_v.m_capacity]) {
    for (auto i(0u); i < _v.m_size; i++)
        push_back(_v[i]);
}

// Move Constructor
template <typename T>
Vector<T>::Vector(Vector &&_v) : m_capacity(_v.m_capacity), m_list(std::move(_v.m_list)) {
    m_size = _v.m_size;
    _v.m_size = 0;
    _v.m_capacity = 0;
}

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

// Verify if the Vector is empty
template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

// Push Back
template <typename T>
void Vector<T>::push_back(const T &_x) {
    if (m_size >= m_capacity)
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    m_list[m_size++] = _x;
}

// Pop Back
template <typename T>
void Vector<T>::pop_back() {
    (&m_list[--m_size])->~T();
}

// Get the Back element
template <typename T>
const T &Vector<T>::back() const {
    return m_list[m_size - 1];
}

// Get the Front element
template <typename T>
const T &Vector<T>::front() const {
    return m_list[0];
}

// Assign a value to Vector
template <typename T>
void Vector<T>::assign(const T &_x) {
    for (auto i(0u); i < m_size; i++)
        m_list[i] = _x;
}

// Gets the capacity size
template <typename T>
size_type Vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
void Vector<T>::reserve(size_type _new_capacity) {
    if (_new_capacity > m_capacity) {
        // Creates a new unique_ptr with a bigger size
        std::unique_ptr<T[]> cpy_list(new T[_new_capacity]);
        // Copy vector content to cpy_list and calls your destructor
        for (auto i(0u); i < m_size; i++) {
            cpy_list[i] = m_list[i];
            (&m_list[i])->~T();
        }
        // Moves the cpy_list to m_list
        m_list = std::move(cpy_list);
        // Sets the new capacity value
        m_capacity = _new_capacity;
    }
}

// Gets the element at some position
template <typename T>
T &Vector<T>::at(size_type _idx) {
    if (_idx >= m_size || _idx < 0)
        throw std::out_of_range("Index out of range!");
    return m_list[_idx];
}

template <typename T>
T* Vector<T>::data() {
    return m_list.get();
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return typename Vector<T>::iterator(m_list.get());
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return typename Vector<T>::iterator(m_list.get() + m_size);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return typename Vector<T>::const_iterator(m_list.get());
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const {
    return typename Vector<T>::const_iterator(m_list.get() + m_size);
}
