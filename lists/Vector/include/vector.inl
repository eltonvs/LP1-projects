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
