#ifndef _IntPair_H_
#define _IntPair_H_

#include <iostream>
#include <sstream>
#include <string>

class IntPair {
 public:
    // Constructors
    IntPair(int, int);
    IntPair(const IntPair &);

    // Destructor
    ~IntPair();

    // Setters
    void set_first(int);
    void set_second(int);
    void set(int, int);

    // Getters
    int get_first() const;
    int get_second() const;
    void get(int &, int &) const;

    // Accessors
    std::string print() const;

    // Methods
    void flip();

    // Operators
    IntPair &operator=(const IntPair &_a) {
        if (this != &_a)
            this->set(_a.get_first(), _a.get_second());
        return *this;
    }

    IntPair operator+(const IntPair &_a) {
        IntPair tmp(this->get_first() + _a.get_first(), this->get_second() + _a.get_second());
        return tmp;
    }

    bool operator==(const IntPair &_a) {
        return (*(this->first) == *(_a.first) && *(this->second) == *(_a.second)) ? true : false;
    }

 private:
    int *first;
    int *second;
};

#endif
