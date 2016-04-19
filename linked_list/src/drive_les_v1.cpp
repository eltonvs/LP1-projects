// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1

#include "les_v1.h"
#include <iostream>
using std::cout;


int main ( void ) {
    SNPtr pHead = NULL;// nullptr;

    pushFront( pHead, 1 );

    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
