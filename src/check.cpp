#include <iostream>

#include "include/logic.h"

bool checkPossibleMoves( std::array< CardInfo, 16 > grid ) {
    bool thereArePossib = false;
    int currentValue;

    for (int i = 0; i < 15; i++) {
        currentValue = grid[ i ].value ;
        if ( ( ( i + 1 ) % 4 ) != 0 ) {
            thereArePossib = currentValue == grid[ i + 1 ].value ;
        }
        if ( ( i + 4 ) < 16 ) {
            thereArePossib = ( currentValue == grid[ i + 4 ].value )
                || thereArePossib;
        }
        if ( thereArePossib ) {
            return thereArePossib;
        }
    }
    return thereArePossib;
}
