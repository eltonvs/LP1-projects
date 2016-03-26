// Copyright 2016

#include <iostream>
#include "geometry.hpp"

//
// Point
//

// Constructor
Point::Point(int x, int y) {
    this->setX(x);
    this->setY(y);
}

// Getters
int Point::getX() const {
    return this->m_x;
}
int Point::getY() const {
    return this->m_y;
}

// Setters
void Point::setX(const int newX) {
    this->m_x = newX;
}
void Point::setY(const int newY) {
    this->m_y = newY;
}


//
// PointArray
//

// Constructor
PointArray::PointArray() {
    m_point_array = new Point[0];
    m_point_array_size = 0;
}
PointArray::PointArray(const Point points[], const int size) {
    if (size != this->m_point_array_size) {
        this->m_point_array_size = size;
        this->m_point_array = new Point[size];
    }

    for (int i = 0; i < size; i++) {
        this->m_point_array[i].setX(points[i].getX());
        this->m_point_array[i].setY(points[i].getY());
    }
}
PointArray::PointArray(const PointArray &pv) {
    if (&pv != this) {
        int pv_size = pv.getSize();
        if (this->getSize() != pv_size) {
            this->m_point_array_size = pv_size;
            this->m_point_array = new Point[pv_size];
        }
        for (int i = 0; i < pv_size; i++) {
            this->m_point_array[i].setX(pv.m_point_array[i].getX());
            this->m_point_array[i].setY(pv.m_point_array[i].getY());
        }
    }
}

// Destructor
PointArray::~PointArray() {
    this->m_point_array_size = 0;
    delete[] m_point_array;
}

// Getters
const int PointArray::getSize() const {
    return this->m_point_array_size;
}

// Methods
void PointArray::resize(int n) {
    PointArray tmp(*this);

    if (n != this->m_point_array_size) {
        delete[] m_point_array;
        this->m_point_array_size = n;
        this->m_point_array = new Point[n];
    }

    for (int i = 0; i < n; i++) {
        this->m_point_array[i].setX(tmp.m_point_array[i].getX());
        this->m_point_array[i].setY(tmp.m_point_array[i].getY());
    }
}

void PointArray::push_back(const Point &p) {
    int sz = this->getSize();
    this->resize(sz+1);
    this->m_point_array[sz].setX(p.getX());
    this->m_point_array[sz].setY(p.getY());
}

void PointArray::insert(const int position, const Point &p) {
    if (position < 0)
        throw std::out_of_range("Index out of range!");

    int sz = this->getSize();
    int new_sz = 0;
    if (position > sz)
        new_sz = position;
    else
        new_sz = sz+1;

    this->resize(new_sz);

    for (int i = new_sz - 1; i > position; i--) {
        this->m_point_array[i].setX(this->m_point_array[i-1].getX());
        this->m_point_array[i].setY(this->m_point_array[i-1].getY());
    }
    this->m_point_array[position].setX(p.getX());
    this->m_point_array[position].setY(p.getY());
}

void PointArray::remove(const int position) {
    int sz = this->getSize();

    if (position < 0 || position > sz)
        throw std::out_of_range("Index out of range!");

    PointArray temp(this->m_point_array, sz);

    this->resize(sz-1);

    for (int i = 0, j = 0; i < sz; i++, j++) {
        if (i == position) {
            j--;
            continue;
        }
        this->m_point_array[j].setX(temp.m_point_array[i].getX());
        this->m_point_array[j].setY(temp.m_point_array[i].getY());
    }
}

void PointArray::clear() {
    this->resize(0);
}

const Point PointArray::operator[] (const int position) const {
    if (position < 0 || position > this->getSize())
        throw std::out_of_range("Index out of range!");

    return this->m_point_array[position];
}
Point& PointArray::operator[] (const int position) {
    if (position < 0 || position > this->getSize())
        throw std::out_of_range("Index out of range!");

    return this->m_point_array[position];
}
