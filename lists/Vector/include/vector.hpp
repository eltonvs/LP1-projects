/*!
 *  @file vector.hpp
 *  @brief Vector ADT Header
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Vector ADT header
 */

#ifndef _vector_hpp_
#define _vector_hpp_

#include <memory>

typedef size_t size_type;

template <typename T>
class Vector {
 public:
    /**
     * @brief Vector Constructor
     * @param _sz The Vector size (default = 1)
     */
    explicit Vector(size_type _sz = 1);

    /**
     * @brief Vector Destructor
     */
    ~Vector() {}

    /**
     * @brief Get the Vector size
     * @return The Vector size
     */
    size_type size() const;

    /**
     * @brief Remove all elements from vector
     */
    void clear();

    /**
     * @brief Verify if the Vector is empty
     * @return True if is empty, False otherwise
     */
    bool empty();

    /**
     * @brief Add an element to the end of Vector
     * @param _x The element to be pushed back
     */
    void push_back(const T &_x);

    /**
     * @brief Removes the last element of Vector
     */
    void pop_back();

    /**
     * @brief Returns the object of the end of Vector
     * @return The last Vector element
     */
    const T &back() const;

    /**
     * @brief Gets the element on the beginning of Vector
     * @return The first Vector element
     */
    const T &front() const;

    /**
     * @brief Replaces the content of the Vector
     * @param _x The value to be used on replacement
     */
    void assign(const T &_x);

 private:
    size_type m_size = 0;
    size_type m_capacity = 1;
    std::unique_ptr<T[]> m_list;
};

#include "vector.inl"

#endif
