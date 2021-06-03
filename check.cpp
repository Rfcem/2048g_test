#include <iostream>

#include "include/logic.h"

bool checkPossibleMoves( int grid[] ) {
    bool thereArePossib = false;
    int currentValue;

    for (int i = 0; i < 15; i++) {
        currentValue = grid[ i ];
        if ( ( ( i + 1 ) % 4 ) != 0 ) {
            thereArePossib = currentValue == grid[ i + 1 ];
        }
        if ( ( i + 4 ) < 16 ) {
            thereArePossib = ( currentValue == grid[ i + 4 ] ) || thereArePossib;
        }
        if ( thereArePossib ) {
            return thereArePossib;
        }
    }
    return thereArePossib;
}
