/*!
 *  @file list.inl
 *  @brief List Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with List ADT implementations
 */

#include "list.hpp"

// Constructors
template <typename T>
List<T>::List() {
    m_head = new Node;
    m_tail = new Node;
    m_size = 0;
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

template <typename T>
List<T>::List(const List<T> &_fl) {
    m_head = new Node;
    m_tail = new Node;
    m_head->next = m_tail;
    m_tail->prev = m_head;
    m_size = 0;
    for (auto it = _fl.cbegin(); it != _fl.cend(); it++)
        push_back(*it);
}

template <typename T>
List<T>::List(List<T> &&_fl) {
    // "Stole" _fl data
    m_head = new Node;
    m_tail = _fl.m_tail;
    m_head->next = _fl.m_head->next;
    m_size = _fl.m_size;
    // Change _fl
    _fl.m_tail = new Node;
    _fl.m_head->next = _fl.m_tail;
    _fl.m_tail->prev = _fl.m_head;
    _fl.m_size = 0;
}

// Destructor
template <typename T>
List<T>::~List() {
    clear();
    delete m_head;
    delete m_tail;
}

// Get list size
template <typename T>
int List<T>::size() const {
    return m_size;
}

// Verify if the list is empty
template <typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

// Empty list content
template <typename T>
void List<T>::clear() {
    Node *cp1 = m_head->next;
    while (cp1 != m_tail) {
        Node *cp2 = cp1;
        cp1 = cp1->next;
        delete cp2;
    }
    m_size = 0;
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

// Gets the first element from List
template <typename T>
T &List<T>::front() {
    return m_head->next->data;
}

// Gets the first element from List (with const modifier)
template <typename T>
const T &List<T>::front() const {
    return m_head->next->data;
}

// Gets the last element from List
template <typename T>
T &List<T>::back() {
    return m_tail->prev->data;
}

// Gets the last element from List (with const modifier)
template <typename T>
const T &List<T>::back() const {
    return m_tail->prev->data;
}

// Inserts a element on the front of the List
template <typename T>
void List<T>::push_front(const T &_x) {
    Node *_new = new Node(_x, m_head->next, m_head);
    m_head->next->prev = _new;
    m_head->next = _new;
    m_size++;
}

// Inserts a element on the end of the List
template <typename T>
void List<T>::push_back(const T &_x) {
    Node *_new = new Node(_x, m_tail, m_tail->prev);
    m_tail->prev->next = _new;
    m_tail->prev = _new;
    m_size++;
}

// Removes the first element from list
template <typename T>
void List<T>::pop_front() {
    if (m_size > 0) {
        Node *temp = m_head->next;
        temp->next->prev = m_head;
        m_head->next = temp->next;
        m_size--;
        delete temp;
    }
}

// Removes the last element from list
template <typename T>
void List<T>::pop_back() {
    if (m_size > 0) {
        Node *temp = m_tail->prev;
        temp->prev->next = m_tail;
        m_tail->prev = temp->prev;
        m_size--;
        delete temp;
    }
}

// Assign a value to all elements from list
template <typename T>
void List<T>::assign(const T &_val) {
    Node *temp = m_head;
    while (temp->next != m_tail) {
        temp = temp->next;
        temp->data = _val;
    }
}

// Assign a value to all elements from list with an initializer_list
template <typename T>
void List<T>::assign(std::initializer_list<T> _il) {
    clear();
    for (auto it = _il.begin(); it != _il.end(); it++)
        push_back(*it);
}

// Returns a iterator pointing to the first element of the list
template <typename T>
typename List<T>::iterator List<T>::begin() {
    return typename List<T>::iterator(m_head->next);
}

// Returns a iterator pointing to the beginning of the list
template <typename T>
typename List<T>::iterator List<T>::before_begin() {
    return typename List<T>::iterator(m_head);
}

// Returns a iterator pointing to the end of the list
template <typename T>
typename List<T>::iterator List<T>::end() {
    return typename List<T>::iterator(m_tail);
}

// Returns a iterator pointing to the first element of the list
template <typename T>
typename List<T>::const_iterator List<T>::cbegin() const {
    return typename List<T>::const_iterator(m_head->next);
}

// Returns a iterator pointing to the beginning of the list
template <typename T>
typename List<T>::const_iterator List<T>::cbefore_begin() const {
    return typename List<T>::const_iterator(m_head);
}

// Returns a iterator pointing to the end of the list
template <typename T>
typename List<T>::const_iterator List<T>::cend() const {
    return typename List<T>::const_iterator(m_tail);
}

// Insert a element after a const_iterator
template <typename T>
typename List<T>::iterator List<T>::insert_after(const_iterator _it, const T &_x) {
    Node *_new = new Node(_x, _it.m_node->next);
    _it.m_node->next->prev = _new;
    _it.m_node->next = _new;
    m_size++;
    return List<T>::iterator(_it.m_node->next);
}

// Insert an initializer_list after a const_iterator
template <typename T>
typename List<T>::iterator List<T>::insert_after(const_iterator _pos, std::initializer_list <T> _il) {
    for (auto it = _il.begin(); it != _il.end(); it++) {
        Node *_new = new Node(*it, _pos.m_node->next);
        _pos.m_node->next->prev = _new;
        _pos.m_node->next = _new;
        m_size++;
    }
    return List<T>::iterator(_pos.m_node->next);
}

// Removes all elements after an iterator
template <typename T>
typename List<T>::iterator List<T>::erase_after(const_iterator _it) {
    if (_it.m_node != m_tail && _it.m_node->next != m_tail) {
        Node *cpy = _it.m_node->next;
        cpy->next->prev = _it.m_node;  // ATTENTION HERE
        _it.m_node->next = cpy->next;
        m_size--;
        delete cpy;
        return List<T>::iterator(_it.m_node->next);
    }
    return List<T>::iterator(_it.m_node);
}

// Removes all elements between two iterators
template <typename T>
typename List<T>::iterator List<T>::erase_after(const_iterator _ini, const_iterator _end) {
    if (_ini.m_node != _end.m_node) {
        Node *cpy = _ini.m_node->next;
        _ini.m_node->next = _end.m_node;
        _end.m_node->prev = _ini.m_node;
        while (cpy != _end.m_node) {
            Node *aux = cpy;
            cpy = cpy->next;
            m_size--;
            delete aux;
        }
        return List<T>::iterator(_end.m_node);
    }
    return List<T>::iterator(_ini.m_node);
}

// Find an element on list
template <typename T>
typename List<T>::const_iterator List<T>::find(const T &_x) const {
    auto it = cbegin();
    while (it != cend()) {
        if (*it == _x) break;
        it++;
    }
    return it;
}
