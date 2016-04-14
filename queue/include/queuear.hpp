// Copyright - 2016

#ifndef _queuear_hpp_
#define _queuear_hpp_

#include "AbsQueue.hpp"

template <typename Object>
class QueueAr : public AbsQueue<Object> {
 public:
    // Constructor
    QueueAr(const int _sz);
    // Destructor
    ~QueueAr();  // Default destructor
    // Basic members
    void enqueue(const Object &_x);
    Object dequeue();
    Object getFront() const;
    bool isEmpty() const;
    void makeEmpty();

 private:
    unsigned size() const;

    Object *m_list = nullptr;
    int m_SIZE = 0;
    int m_f = -1;
    int m_r = -1;
};

#include "queuear.inl"

#endif
