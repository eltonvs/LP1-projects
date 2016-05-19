/*!
 *  @file forward_list.hpp
 *  @brief Forward List ADT Header
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Forward List ADT header
 */

#ifndef _forward_list_hpp_
#define _forward_list_hpp_

typedef size_t size_type;

template <typename T>
class Forward_list {
 public:
    /**
     * @brief Forward List Constructor
     */
    Forward_list();

    /**
     * @brief Forward List Copy Constructor
     * @param _fl The list to be copied
     */
    explicit Forward_list(const Forward_list &_fl);

    /**
     * @brief Forward List Move Constructor
     * @param _fl The list to be moved
     */
    explicit Forward_list(Forward_list &&_fl);

    /**
     * @brief Forward List Destructor
     */
    ~Forward_list();

    /**
     * @brief Gets the Forward List size
     * @return The Forward List size
     */
    int size() const;

    /**
     * @brief Verify if the Forward List is empty
     * @return True if is empty, False otherwise
     */
    bool empty() const;

    /**
     * @brief Remove all elements from List
     */
    void clear();

    /**
     * @brief Gets the front element
     * @return A reference to the first element from list
     */
    T &front();

    /**
     * @brief Gets the front element
     * @return A const reference to the first element from list
     */
    const T &front() const;

    /**
     * @brief Gets the last element
     * @return A reference to the last element from list
     */
    T &back();

    /**
     * @brief Gets the last element
     * @return A const reference to the last element from list
     */
    const T &back() const;

    /**
     * @brief Inserts a element at the front of the list
     * @param _x The element to be inserted
     */
    void push_front(const T &_x);

    /**
     * @brief Inserts a element at the end of the list
     * @param _x The element to be inserted
     */
    void push_back(const T &_x);

    /**
     * @brief Removes the first element of the list
     */
    void pop_front();

    /**
     * @brief Removes the last element of the list
     */
    void pop_back();

    /**
     * @brief Assign a value to all elements of the list
     * @param _val Value to be assigned
     */
    void assign(const T &_val);

    /**
     * @brief Assign the list value from a initializer_list
     * @param _val Initializer List with the new List value
     */
    void assign(std::initializer_list<T> _il);

    /**
     * @brief The nested const_iterator class
     */
    class const_iterator;

    /**
     * @brief The nested iterator class
     */
    class iterator;

    /**
     * @brief Gets an iterator pointing to the first element of the list
     * @return An iterator to the first element of the list
     */
    iterator begin();

    /**
     * @brief Gets an iterator pointing to the beginning of the list
     * @return An iterator to the beginning of the list
     */
    iterator before_begin();

    /**
     * @brief Gets an iterator pointing to the end of the list
     * @return An iterator to the end of the list
     */
    iterator end();

    /**
     * @brief Gets a const_iterator pointing to the first element of the list
     * @return A const_iterator to the first element of the list
     */
    const_iterator cbegin() const;

    /**
     * @brief Gets a const_iterator pointing to the beginning of the list
     * @return A const_iterator to the beginning of the list
     */
    const_iterator cbefore_begin() const;

    /**
     * @brief Gets a const_iterator pointing to the end of the list
     * @return A const_iterator to the end of the list
     */
    const_iterator cend() const;

    /**
     * @brief Inserts a element after a position
     * @param _it The iterator at position to be inserted (after)
     * @param _x The element to be inserted
     * @return An iterator to the inserted element
     */
    iterator insert_after(const_iterator _it, const T &_x);

    /**
     * @brief Inserts a initializer_list after a position
     * @param _it The iterator at position to be inserted (after)
     * @param _il The initializer_list to be inserted
     * @return An iterator to the last inserted element
     */
    iterator insert_after(const_iterator _pos, std::initializer_list <T> _il);

    /**
     * @brief Removes the element following a position
     * @param _it The iterator at the position
     * @return The position of the removed element
     */
    iterator erase_after(const_iterator _it);

    /**
     * @brief Removes all elements between two iterators
     * @param _ini The iterator at the initial position
     * @param _end The iterator at the final position
     * @return An iterator to the last removed element
     */
    iterator erase_after(const_iterator _ini, const_iterator _end);

    /**
     * @brief Replaces the list content with copies of the content on iterators
     * @param _ini The iterator at the initial position
     * @param _end The iterator at the final position
     */
    template <class IT>
    void assign(IT _ini, IT _end);

    /**
     * @brief Find an element on List
     * @param _x The element to bo looked for
     * @return An iterator to the last removed element
     */
    const_iterator find(const T &_x) const;

    /**
     * @brief Overload copy assignment
     * @param _fl The element to be copied
     * @return The new (pasted) element
     */
    Forward_list &operator=(const Forward_list &_fl) {
        delete m_head;
        delete m_tail;

        m_head = new Node;
        m_tail = new Node;
        m_head->next = m_tail;
        m_size = 0;
        for (auto it = _fl.cbegin(); it != _fl.cend(); it++)
            push_back(*it);

        return (*this);
    }

    /**
     * @brief Overload move assignment
     * @param _fl The element to be moved
     * @return The new element
     */
    Forward_list &operator=(Forward_list &&_fl) {
        delete m_head;
        delete m_tail;

        m_head = new Node;
        m_tail = _fl.m_tail;
        m_head->next = _fl.m_head->next;
        m_size = _fl.m_size;

        _fl.m_tail = new Node;
        _fl.m_head->next = _fl.m_tail;
        _fl.m_size = 0;

        return (*this);
    }

 private:
    struct Node {
        T data;      //!< Data field
        Node *next;  //!< Pointer to the next node in the list.
        Node(const T &_d = T(), Node *_nxt = nullptr) : data(_d), next(_nxt) {}
    };
    Node *m_head;      //!< A pointer to the List head
    Node *m_tail;      //!< A pointer to the List tail
    size_type m_size;  //!< The List size
};

template <typename T>
class Forward_list<T>::const_iterator {
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
        return m_node->data;
    }

    /**
     * @brief Overloads the infix ++ operator
     * @return The increased const_iterator
     */
    const_iterator &operator++() {
        m_node = m_node->next;
        return (*this);
    }

    /**
     * @brief Overloads the postfix ++ operator
     * @return A const_iterator
     */
    const_iterator operator++(int) {
        const_iterator cpy(m_node);
        m_node = m_node->next;
        return cpy;
    }

    /**
     * @brief Overloads the == operator
     * @param _rhs The element from right side
     * @return True if both are equals, False otherwise
     */
    bool operator==(const const_iterator &_rhs) const {
        return (m_node == _rhs.m_node);
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
    const_iterator(Node *_p) : m_node(_p) {}
    Node *m_node;                  //!< The internal pointer to a Forward_list node
    friend class Forward_list<T>;  //!< Makes a friendship with the Forward_list class
};

template <typename T>
class Forward_list<T>::iterator : public Forward_list<T>::const_iterator {
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
        return const_iterator::m_node->data;
    }

    /**
     * @brief Overloads the * operator
     * @return The element value
     */
    T &operator*() {
        return const_iterator::m_node->data;
    }

    /**
     * @brief Overloads the infix ++ operator
     * @return The increased iterator
     */
    iterator &operator++() {
        const_iterator::m_node = const_iterator::m_node->next;
        return (*this);
    }

    /**
     * @brief Overloads the postfix ++ operator
     * @return A iterator
     */
    iterator operator++(int) {
        iterator cpy(const_iterator::m_node);
        const_iterator::m_node = const_iterator::m_node->next;
        return cpy;
    }

 protected:
    //! @brief The Protected constructor
    iterator(Node *_p) : const_iterator(_p) {}
    friend class Forward_list<T>;  //!< Makes a friendship with the Forward_list class
};

#include "forward_list.inl"

#endif
