/*!
 *  @file forward_list.inl
 *  @brief Forward List Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with Forward List ADT implementations
 */

#include "forward_list.hpp"

// Constructors
template <typename T>
Forward_list<T>::Forward_list() {
    m_head = new Node;
    m_tail = new Node;
    m_size = 0;
    m_head->next = m_tail;
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T> &_fl) {
    m_head = new Node;
    m_tail = new Node;
    m_head->next = m_tail;
    m_size = 0;
    for (auto it = _fl.cbegin(); it != _fl.cend(); it++)
        push_back(*it);
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T> &&_fl) {
    // "Stole" _fl data
    m_head = new Node;
    m_tail = _fl.m_tail;
    m_head->next = _fl.m_head->next;
    m_size = _fl.m_size;
    // Change _fl
    _fl.m_tail = new Node;
    _fl.m_head->next = _fl.m_tail;
    _fl.m_size = 0;
}

// Destructor
template <typename T>
Forward_list<T>::~Forward_list() {
    clear();
    delete m_head;
    delete m_tail;
}

// Get list size
template <typename T>
int Forward_list<T>::size() const {
    return m_size;
}

// Verify if the list is empty
template <typename T>
bool Forward_list<T>::empty() const {
    return m_size == 0;
}

// Empty list content
template <typename T>
void Forward_list<T>::clear() {
    Node *cp1 = m_head->next;
    while (cp1 != m_tail) {
        Node *cp2 = cp1;
        cp1 = cp1->next;
        delete cp2;
    }
    m_size = 0;
    m_head->next = m_tail;
}

// Gets the first element from List
template <typename T>
T &Forward_list<T>::front() {
    return m_head->next->data;
}

// Gets the first element from List (with const modifier)
template <typename T>
const T &Forward_list<T>::front() const {
    return m_head->next->data;
}

// Gets the last element from List
template <typename T>
T &Forward_list<T>::back() {
    Node *temp = m_head;
    while (temp->next != m_tail)
        temp = temp->next;
    return temp->data;
}

// Gets the last element from List (with const modifier)
template <typename T>
const T &Forward_list<T>::back() const {
    Node *temp = m_head;
    while (temp->next != m_tail)
        temp = temp->next;
    return temp->data;
}

// Inserts a element on the front of the List
template <typename T>
void Forward_list<T>::push_front(const T &_x) {
    Node *_new = new Node(_x, m_head->next);
    m_head->next = _new;
    m_size++;
}

// Inserts a element on the end of the List
template <typename T>
void Forward_list<T>::push_back(const T &_x) {
    // Search for the last element
    Node *temp = m_head;
    while (temp->next != m_tail)
        temp = temp->next;
    // Creates a new element
    Node *_new = new Node(_x, temp->next);
    // Makes the last element point to _new
    temp->next = _new;
    // Increase List size
    m_size++;
}

// Removes the first element from list
template <typename T>
void Forward_list<T>::pop_front() {
    if (m_size > 0) {
        Node *temp = m_head->next;
        m_head->next = temp->next;
        m_size--;
        delete temp;
    }
}

// Removes the last element from list
template <typename T>
void Forward_list<T>::pop_back() {
    if (m_size > 0) {
        Node *aux1 = m_head;
        while (aux1->next->next != m_tail)
            aux1 = aux1->next;
        Node *aux2 = aux1->next;  // Element to be dropped
        aux1->next = aux2->next;
        m_size--;
        delete aux2;
    }
}

// Assign a value to all elements from list
template <typename T>
void Forward_list<T>::assign(const T &_val) {
    Node *temp = m_head;
    while (temp->next != m_tail) {
        temp = temp->next;
        temp->data = _val;
    }
}

// Assign a value to all elements from list with an initializer_list
template <typename T>
void Forward_list<T>::assign(std::initializer_list<T> _il) {
    clear();
    for (auto i = _il.begin(); i != _il.end(); i++)
        push_back(*i);
}

// Returns a iterator pointing to the first element of the list
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin() {
    return typename Forward_list<T>::iterator(m_head->next);
}

// Returns a iterator pointing to the beginning of the list
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::before_begin() {
    return typename Forward_list<T>::iterator(m_head);
}

// Returns a iterator pointing to the end of the list
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end() {
    return typename Forward_list<T>::iterator(m_tail);
}

// Returns a iterator pointing to the first element of the list
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbegin() const {
    return typename Forward_list<T>::const_iterator(m_head->next);
}

// Returns a iterator pointing to the beginning of the list
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbefore_begin() const {
    return typename Forward_list<T>::const_iterator(m_head);
}

// Returns a iterator pointing to the end of the list
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cend() const {
    return typename Forward_list<T>::const_iterator(m_tail);
}

// Insert a element after a const_iterator
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(const_iterator _it, const T &_x) {
    Node *_new = new Node(_x, _it.m_node->next);
    _it.m_node->next = _new;
    m_size++;
    return Forward_list<T>::iterator(_it.m_node->next);
}

// Insert an initializer_list after a const_iterator
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(const_iterator _pos, std::initializer_list <T> _il) {
    for (auto it = _il.begin(); it != _il.end(); it++) {
        Node *_new = new Node(*it, _pos.m_node->next);
        _pos.m_node->next = _new;
        m_size++;
    }
    return Forward_list<T>::iterator(_pos.m_node->next);
}

// Removes all elements after an iterator
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(const_iterator _it) {
    if (_it.m_node != m_tail && _it.m_node->next != m_tail) {
        Node *cpy = _it.m_node->next;
        _it.m_node->next = cpy->next;
        m_size--;
        delete cpy;
        return Forward_list<T>::iterator(_it.m_node->next);
    }
    return Forward_list<T>::iterator(_it.m_node);
}

// Removes all elements between two iterators
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(const_iterator _ini, const_iterator _end) {
    if (_ini.m_node != _end.m_node) {
        Node *cpy = _ini.m_node->next;
        _ini.m_node->next = _end.m_node;
        while (cpy != _end.m_node) {
            Node *aux = cpy;
            cpy = cpy->next;
            m_size--;
            delete aux;
        }
        return Forward_list<T>::iterator(_end.m_node);
    }
    return Forward_list<T>::iterator(_ini.m_node);
}

// Find an element on list
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::find(const T &_x) const {
    auto it = cbegin();
    while (it != cend()) {
        if (*it == _x)
            break;
        it++;
    }
    return it;
}
