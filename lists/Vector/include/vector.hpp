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
     * @brief Vector Default Constructor
     * @param _sz The Vector size (default = 1)
     */
    explicit Vector(size_type _sz = 1);

    /**
     * @brief Vector Copy Constructor
     * @param _sz The another Vector to be copied
     */
    Vector(const Vector &_v);

    /**
     * @brief Vector Move Constructor
     * @param _v The anotehr Vector to be moved
     */
    Vector(Vector &&_v);

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
    bool empty() const;

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
    T &operator[](size_type idx) const {
        return m_list[idx];
    }

    /**
     * @brief Overload copy assignment
     * @param _v The element to be copied
     * @return The new (pasted) element
     */
    Vector &operator=(const Vector &_v) {
        clear();

        for (auto i(0u); i < _v.m_size; i++)
            push_back(_v[i]);

        return (*this);
    }

    /**
     * @brief Overload move assignment
     * @param _v The element to be moved
     * @return The new element
     */
    Vector &operator=(Vector &&_v) {
        clear();

        m_list = std::move(_v.m_list);
        m_capacity = _v.m_capacity;
        m_size = _v.m_size;
        _v.m_size = 0;
        _v.m_capacity = 0;

        return (*this);
    }

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

    /**
     * @brief Returns a iterator to the first Vector element
     * @return An iterator pointing to the first Vector element
     */
    iterator begin();

    /**
     * @brief Returns a iterator to the end mark in the list
     * @return An iterator pointing to the end mark in the list
     */
    iterator end();

    /**
     * @brief Returns a const_iterator to the first Vector element
     * @return A const_iterator pointing to the first Vector element
     */
    const_iterator cbegin() const;

    /**
     * @brief Returns a const_iterator to the end mark in the list
     * @return A const_iterator pointing to the end mark in the list
     */
    const_iterator cend() const;

 private:
    size_type m_size = 0;         //!< The Vector size
    size_type m_capacity = 1;     //!< The Vector capacity
    std::unique_ptr<T[]> m_list;  //!< The Vector list
};

template <typename T>
class Vector<T>::const_iterator {
 public:
    /**
     * @brief Public constructor
     */
    const_iterator() {}

    /**
     * @brief Overloads the * operator (w/ const modifier)
     * @return The element value (const)
     */
    const T &operator*() const {
        return *m_ptr;
    }

    /**
     * @brief Overloads the infix ++ operator
     * @return The increased const_iterator
     */
    const_iterator &operator++() {
        m_ptr++;
        return (*this);
    }

    /**
     * @brief Overloads the postfix ++ operator
     * @return A const_iterator
     */
    const_iterator operator++(int) {
        const_iterator cpy(m_ptr);
        m_ptr++;
        return cpy;
    }

    /**
     * @brief Overloads the infix -- operator
     * @return The decreased const_iterator
     */
    const_iterator &operator--() {
        m_ptr--;
        return (*this);
    }

    /**
     * @brief Overloads the postfix -- operator
     * @return A const_iterator
     */
    const_iterator operator--(int) {
        const_iterator cpy(m_ptr);
        m_ptr--;
        return cpy;
    }

    /**
     * @brief Overloads the == operator
     * @param _rhs The element from right side
     * @return True if both are equals, False otherwise
     */
    bool operator==(const const_iterator &_rhs) const {
        return (m_ptr == _rhs.m_ptr);
    }

    /**
     * @brief Overloads the != operator
     * @param _rhs The element from right side
     * @return True if both aren't equals, False otherwise
     */
    bool operator!=(const const_iterator &_rhs) const {
        return !(*this == _rhs);
    }

 protected:
    //! @brief The Protected constructor
    const_iterator(T *_p) : m_ptr(_p) {}
    T *m_ptr;                //!< The Vector element internal pointer
    friend class Vector<T>;  //!< Makes a friendship with the Vector class
};

template <typename T>
class Vector<T>::iterator : public Vector<T>::const_iterator {
 public:
    /**
     * @brief Public constructor
     */
    iterator() : const_iterator() {}

    /**
     * @brief Overloads the * operator (w/ const modifier)
     * @return The element value (const)
     */
    const T &operator*() const {
        return *(const_iterator::m_ptr);
    }

    /**
     * @brief Overloads the * operator
     * @return The element value
     */
    T &operator*() {
        return *(const_iterator::m_ptr);
    }

    /**
     * @brief Overloads the infix ++ operator
     * @return The increased iterator
     */
    iterator &operator++() {
        const_iterator::m_ptr++;
        return (*this);
    }

    /**
     * @brief Overloads the postfix ++ operator
     * @return A iterator
     */
    iterator operator++(int) {
        iterator cpy(const_iterator::m_ptr);
        const_iterator::m_ptr++;
        return cpy;
    }

    /**
     * @brief Overloads the infix -- operator
     * @return The decreased iterator
     */
    iterator &operator--() {
        const_iterator::m_ptr--;
        return (*this);
    }

    /**
     * @brief Overloads the postfix -- operator
     * @return A iterator
     */
    iterator operator--(int) {
        const_iterator cpy(const_iterator::m_ptr);
        const_iterator::m_ptr--;
        return cpy;
    }

 protected:
    //! @brief The Protected constructor
    iterator(T *_p) : const_iterator(_p) {}
    friend class Vector<T>;  //!< Makes a friendship with the Vector class
};

#include "vector.inl"

#endif
