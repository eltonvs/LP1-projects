#ifndef _queue_hpp_
#define _queue_hpp_

template <typename Data>
class Queue {
 public:
    Queue(const int _SIZE);
    bool enqueue(const Data);
    bool dequeue(Data &);
    bool front(Data &) const;

 private:
    int m_SIZE;
    int f = -1;
    int b = -1;
};

#endif