// Copyright - 2016

#include "IntPair.h"

// Constructors
IntPair::IntPair(int _a = 0, int _b = 0) {
        this->first = new int;
        this->second = new int;

        this->set(_a, _b);
    }
IntPair::IntPair(const IntPair &_a) {
        this->first = new int;
        this->second = new int;

        this->set(_a.get_first(), _a.get_second());
    }

// Destructor
IntPair::~IntPair() {
    std::cout << "The object is being destructed" << std::endl;
}

// Setters
void IntPair::set_first(int n_1st) {
    *(this->first) = n_1st;
}
void IntPair::set_second(int n_2nd) {
    *(this->second) = n_2nd;
}
void IntPair::set(int n_1st, int n_2nd) {
    this->set_first(n_1st);
    this->set_second(n_2nd);
}

// Getters
int IntPair::get_first() const {
    return *(this->first);
}
int IntPair::get_second() const {
    return *(this->second);
}
void IntPair::get(int &_1st, int &_2nd) const {
    _1st = this->get_first();
    _2nd = this->get_second();
}

// Accessors
std::string IntPair::print() const {
    std::stringstream ss;
    ss << "[" << this->get_first() << ", " << this->get_second() << "]";
    return ss.str();
}

// Methods
void IntPair::flip() {
    auto aux = this->get_first();
    this->set_first(this->get_second());
    this->set_second(aux);
}
