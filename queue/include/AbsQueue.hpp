// Copyright - 2016

#ifndef _AbsQueue_hpp_
#define _AbsQueue_hpp_

template <class Object>
class AbsQueue {
 public:
    AbsQueue() {/* Empty */}
    // Default constructor
    virtual ~AbsQueue() {/* Empty */}  // Default destructor
    // Basic members
    virtual void enqueue(const Object &x) = 0;
    virtual Object dequeue() = 0;
    virtual Object getFront() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void makeEmpty() = 0;

 private:
    // Disable copy constructor
    AbsQueue(const AbsQueue &) {/* Empty */}
};

#endif
