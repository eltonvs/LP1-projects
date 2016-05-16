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

    /**
     * @brief Returns the Vector capacity
     * @return The Vector capacity
     */
    size_type capacity() const;

    /**
     * @brief Sets the new Vector capacity
     * @param _new_capacity The new capacity size
     */
    void reserve(size_type _new_capacity);

    /**
     * @brief Returns the element at some position
     * @param _idx The position to be returned
     * @return The element on position
     */
    T &at(size_type _idx);

    /**
     * @brief Overload the [] operator
     * @param idx The position to be accessed
     * @return The element on informed position
     */
    T &operator[](size_type idx);

    /**
     * @brief Returns a pointer with the Vector data
     * @return A pointer to the beggining of the array
     */
    T* data();

    /**
     * @brief The nested const_iterator class
     */
    class const_iterator;

    /**
     * @brief The nested iterator class
     */
    class iterator;

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

 private:
    size_type m_size = 0;         //!< The Vector size
    size_type m_capacity = 1;     //!< The Vector capacity
    std::unique_ptr<T[]> m_list;  //!< The Vector list
};

template <typename T>
class Vector<T>::const_iterator {
friend class Vector<T>;  //!< Declares const_iterator as a friend of Vector
 public:
    /**
     * @brief const_iterator Constructor
     * @param _ptr The initial pointer value
     */
    explicit const_iterator(T *_ptr = nullptr) : m_ptr(_ptr) {}

    /**
     * @brief Overload the prefix ++ operator
     * @param _it The const_iterator to be modified
     * @return The modified const_iterator
     */
    inline friend
    const_iterator &operator++(Vector<T>::const_iterator &_it) {
        _it.m_ptr++;
        return _it;
    }

    /**
     * @brief Overload the postfix ++ operator
     * @param _it The const_iterator to be modified
     * @return The modified const_iterator
     */
    inline friend
    Vector<T>::const_iterator operator++(Vector<T>::const_iterator &_it, int) {
        Vector<T>::const_iterator cpy(_it.m_ptr++);
        return cpy;
    }

    /**
     * @brief Overload the * operator
     * @param _it The const_iterator to be accessed
     * @return The element value
     */
    inline friend
    T operator*(const Vector<T>::const_iterator &_it) {
        return *(_it.m_ptr);
    }

    /**
     * @brief Overload the == operator
     * @param _lhs The const_iterator from right side
     * @param _rhs The const_iterator from left side
     * @return True if both are equals, False otherwise
     */
    inline friend
    bool operator==(const const_iterator &_lhs, const const_iterator &_rhs) {
        return _lhs.m_ptr == _rhs.m_ptr;
    }

    /**
     * @brief Overload the == operator
     * @param _lhs The const_iterator from right side
     * @param _rhs The const_iterator from left side
     * @return True if both aren't equals, False otherwise
     */
    inline friend
    bool operator!=(const const_iterator &_lhs, const const_iterator &_rhs) {
        return !(_lhs == _rhs);
    }

 protected:
    T *m_ptr; //!< The internal pointer to a Vector element
};

#include "vector.inl"

#endif
