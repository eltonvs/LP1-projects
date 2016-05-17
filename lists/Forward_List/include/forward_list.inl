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

/*
template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T> &_fl) {
    m_head = _fl.m_head;
    m_tail = _fl.m_tail;
    m_size = _fl.m_size;
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T> &&_fl) {
    m_head = _fl.m_head;
    m_tail = _fl.m_tail;
    m_size = _fl.m_size;

    _fl.m_head->next = m_tail;
    _fl.m_tail->next = nullptr;
    _fl.m_size = 0;
}
*/

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
template <typename T>
void Forward_list<T>::assign(std::initializer_list<T> _il) {
    clear();
    for (auto i = _il.begin(); i != _il.end(); i++)
        push_back(*i);
}