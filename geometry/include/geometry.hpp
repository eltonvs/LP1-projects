// Copyright 2016

#ifndef _geometry_hpp_
#define _geometry_hpp_

#include <stdexcept>

// Point class
class Point {
 public:
    // Constructor
    explicit Point(int x = 0, int y = 0);

    // Getters
    int getX() const;
    int getY() const;

    // Setters
    void setX(const int newX);
    void setY(const int newY);

 private:
    int m_x;
    int m_y;
};

// PointArray class
class PointArray {
 public:
    // Constructor
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);

    // Destructor
    ~PointArray();

    // Getters
    const int getSize() const;

    // Methods
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int position);
    void clear();

    // Operators
    const Point operator[] (const int position) const;
    Point &operator[] (const int position);

 private:
    // Methods
    void resize(int n);

    // Vars
    Point *m_point_array;
    int m_point_array_size;
};

#endif
