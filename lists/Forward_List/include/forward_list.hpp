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
     * @brief Forward List Constructor
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
     * @brief Assign a value to all elements from list
     * @param _val Value to be assigned
     */
    void assign(const T &_val);

    void assign(std::initializer_list <T> ilist);
    class const_iterator;
    class iterator;
    iterator begin();
    iterator before_begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cbefore_begin() const;
    const_iterator cend() const;
    iterator insert_after(const_iterator itr, const T &x);
    iterator insert_after(const_iterator pos, std::initializer_list <T> ilist);
    iterator erase_after(const_iterator itr);
    iterator erase_after(const_iterator first, const_iterator last);
    template <class InItr>
    void assign(InItr first, InItr last);
    const_iterator find(const T &x) const;

    /**
     * @brief Overload copy assignment
     * @param _fl The element to be copied
     * @return The new (pasted) element
     */
    Forward_list &operator=(const Forward_list &_fl) {
        delete m_head;
        delete m_tail;

        m_head = new Node(_fl.m_head->data, _fl.m_head->next);
        m_tail = new Node(_fl.m_tail->data, _fl.m_tail->next);
        m_size = _fl.m_size;

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

        m_head = new Node(_fl.m_head->data, _fl.m_head->next);
        m_tail = new Node(_fl.m_tail->data, _fl.m_tail->next);
        m_size = _fl.m_size;

        _fl.m_head->next = _fl.m_tail;
        _fl.m_tail->next = nullptr;
        _fl.size = 0;

        return (*this);
    }

 private:
    struct Node {
        T data;      //!< Data field
        Node *next;  //!< Pointer to the next node in the list.
        Node(const T &_d = T(), Node *_nxt = nullptr) : data(_d), next(_nxt) {}
    };
    Node *m_head;  //!< A pointer to the List head
    Node *m_tail;  //!< A pointer to the List tail
    size_type m_size;    //!< The List size
};

#include "forward_list.inl"

#endif
