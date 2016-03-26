// Copyright 2016

#include <iostream>
#include "geometry.hpp"

bool comp1(PointArray, PointArray);
bool comp2(PointArray, PointArray);
PointArray * search_polys(PointArray *, int, PointArray,
    bool (*)(PointArray, PointArray), PointArray * = nullptr);

int main(int argc, char const *argv[]) {
    // Application Example (Like on PDF)
    Point p1(1, 0);
    Point p2(2, 2);
    Point p3(3, 4);
    Point p4(8, 8);

    Point p_a[3] = {p1, p2, p3};
    Point p_b[3] = {p1, p3, p2};
    Point p_c[4] = {p1, p2, p3, p4};
    Point p_d[3] = {p1, p2, p3};

    PointArray a(p_a, 3);
    PointArray b(p_b, 3);
    PointArray c(p_c, 4);
    PointArray d(p_d, 3);

    PointArray myPolys[] = {a, b, c, d};
    PointArray *result1 = search_polys(myPolys, 4, a, comp1);
    PointArray *result2 = search_polys(myPolys, 4, a, comp2);

    std::cout << "Using comp1:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "[ ";
        for (int j = 0; j < (result1+i)->getSize(); j++) {
            std::cout << "(" << (*(result1+i))[j].getX() << ", "
                      << (*(result1+i))[j].getY() << ") ";
        }
        std::cout << "]\n";
    }

    std::cout << "Using comp2:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "[ ";
        for (int j = 0; j < (result2+i)->getSize(); j++) {
            std::cout << "(" << (*(result2+i))[j].getX() << ", "
                      << (*(result2+i))[j].getY() << ") ";
        }
        std::cout << "]\n";
    }

    return EXIT_SUCCESS;
}

PointArray * search_polys(PointArray * MyPolys,
                          int num_Polys,
                          PointArray PolyTarget,
                          bool (*comp)(PointArray, PointArray),
                          PointArray * PA_return) {
    PA_return = new PointArray[num_Polys];
    for (int i = 0; i < num_Polys; i++) {
        if (comp(MyPolys[i], PolyTarget))
            PA_return[i] = MyPolys[i];
    }

    return PA_return;
}

bool comp1(PointArray p1, PointArray p2) {
    if (p1.getSize() != p2.getSize())
        return false;
    for (int i = 0; i < p1.getSize(); i++)
        if (p1[i].getX() != p2[i].getX() || p1[i].getY() != p2[i].getY())
            return false;
    return true;
}

bool comp2(PointArray p1, PointArray p2) {
    if (p1.getSize() != p2.getSize())
        return false;
    for (int i = 0; i < p1.getSize(); i++) {
        bool a = false;
        for (int j = 0; j < p1.getSize(); j++) {
            if (p1[i].getX() == p2[j].getX() && p1[i].getY() == p2[j].getY())
                a = true;
        }
        if (a == false) return a;
    }
    return true;
}
