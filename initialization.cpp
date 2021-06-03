#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "include\logic.h"

int *initializeGrid( void ){
    int firstPos = 0;
    static int currentGrid[ 16 ];

    for ( int i = 0; i < 16; i++ ) {
        currentGrid[ i ] = 0;
    }

    srand( time( NULL ) );

    firstPos = rand() % 16;
    currentGrid[ firstPos ] = 2;
    firstPos = rand() % 16;

    while ( currentGrid[ firstPos ] == 2 ) {
        firstPos = rand() % 16;
    }
    currentGrid[ firstPos ] = 2;

    return currentGrid;

}

void printGrid( int grid[] ) {
    int value;

    for (int i = 0; i < 16; i++) {
        value = grid[i];
        if ( ( value / 1000 ) >= 1 ) {
            std::cout << value << ( ( ( i + 1 ) % 4 )? "   ": "\n" );

        } else if ( ( value / 100 ) >= 1 ) {
            std::cout << value << ( ( ( i + 1 ) % 4 )? "    ": "\n" );

        } else if ( ( value / 10 ) >= 1 ) {
            std::cout << value << ( ( ( i + 1 ) % 4 )? "     ": "\n" );

        } else {
            std::cout << value << ( ( ( i + 1 ) % 4 )? "      ": "\n" );

        }

    }

    return;
}
