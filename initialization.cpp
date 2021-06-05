#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "include\logic.h"

CardInfo *initializeGrid( void ){
    int firstPos = 0;
    static CardInfo currentGrid[ 16 ];

    for ( int i = 0; i < 16; i++ ) {
        currentGrid[ i ].futureIndex = i;
        currentGrid[ i ].value = 0;
    }

    srand( time( NULL ) );

    firstPos = rand() % 16;
    currentGrid[ firstPos ].value = 2;
    firstPos = rand() % 16;

    while ( currentGrid[ firstPos ].value == 2 ) {
        firstPos = rand() % 16;
    }
    currentGrid[ firstPos ].value = 2;

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
