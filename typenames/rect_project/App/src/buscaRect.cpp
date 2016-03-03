// -------------------------------------------------------------------

#include <cmath>
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <new>
using std::bad_alloc;


#include "rect.h"
using namespace MyRectangle;


// Predicates
bool same_vertex(Rect A, Rect B) {
    return A.getX() == B.getX() && A.getY() == B.getY();
}

bool same_shape(Rect A, Rect B) {
    return A.getWidth() == B.getWidth() && A.getHeight() == B.getHeight();
}

bool same_area(Rect A, Rect B) {
    return A.area() == B.area();
}

bool same_distance(Rect A, Rect B) {
    return sqrt(pow(A.getX(), 2) + pow(A.getY(), 2)) == sqrt(pow(B.getX(), 2) + pow(B.getY(), 2));
}


// Standard linear search.
template <typename T>
int linearSearch(T _V[], int _iSz, const T &_target, bool (*comp)(T, T)) {
    // Run through the array looking for the target.
    for (int i(0); i < _iSz; i++) {
        // We rely on the operator==() from Rect to do the comparison!
        if (comp(_V[i], _target))  // Have we found it yet?
            return i;
    }
    return -1;  // Sorry, it's not here...
}

int main() {
    Rect myContainer[] = {
        Rect(1, 1, 2, 4),
        Rect(2, 2, 2, 1),
        Rect(2, 4, 1, 1),
        Rect(5, 3, 3, 1),
        Rect(4, 10, 2, 7),
        Rect(-2, 3, 5, 6),
        Rect(-1, -4, 10, 2),
        Rect(3, -3, 8, 8)
    };
    const int iSz = sizeof(myContainer)/sizeof(Rect);
    int iIdxTarget = -1;

    // Target in the container.
    Rect target1(-1, -4, 10, 2);
    // Target NOT in the container, but it's got the same area as
    // the last rectangle: [ 3, -3, 8, 8 ].
    Rect target2(0,  0, 8 , 8);

    // Target NOT in the container, but it's got the same distance to origin as
    // the second rectangle: [ 2, 2, 2, 1 ].
    Rect target3(2,  2, 20 , 20);

    for(int i(0); i < iSz; i++) {
        // Stores the distance from the rectangle's corner to the origin.
        float fDist2Origin = sqrt(myContainer[i].getX()* myContainer[i].getX() + myContainer[i].getY()* myContainer[i].getY() );
        cout << "\n >> Rect[ " << i << " ] = " << myContainer[i]
             << "; area = " << myContainer[i].area()
             << "; dist. p/ origem = " << fDist2Origin;
    }


    // First search.
    cout << "\n\n>>> Looking for rectangle "
         << target1 << " in the container...\n";
    iIdxTarget = linearSearch(myContainer, iSz, target1, same_vertex);
    if (iIdxTarget != -1)
        cout << ">>> Successfull search! Target located at the position "
             << iIdxTarget << " of the container!\n";
    else
        cout << ">>> Search failed! Target has not been located inside the container, sorry.\n";

    // Second search.
    cout << "\n>>> Looking for rectangle " << target2 << " in the container...\n";
    iIdxTarget = linearSearch(myContainer, iSz, target2, same_vertex);
    if (iIdxTarget != -1)
        cout << ">>> Successfull search! Target located at the position "
             << iIdxTarget << " of the container!\n";
    else
        cout << ">>> Search failed! Target has not been located inside the container, sorry.\n";

    // Second search.
    cout << "\n>>> Looking for rectangle " << target3 << " in the container...\n";
    iIdxTarget = linearSearch(myContainer, iSz, target3, same_vertex);
    if (iIdxTarget != -1)
        cout << ">>> Successfull search! Target located at the position "
             << iIdxTarget << " of the container!\n";
    else
        cout << ">>> Search failed! Target has not been located inside the container, sorry.\n";


    cout << "\n>>> Normal exiting...\n\n";
    return EXIT_SUCCESS;
}
