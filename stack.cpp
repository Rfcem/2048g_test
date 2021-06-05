#include <iostream>

#include "include/raylib.h"

#include "include/graphics.h"
#include "include/logic.h"

StackOfCards::StackOfCards( const CardInfo *info, GraphicGrid grid ) {
    float size = grid.getSpaceSize();
    for (int i = 0; i < 16; i++) {
        positions[ i ] = grid.getSpacePos( i );
        elemets[ i ].setParameters( positions[ i ],
            size,
            info[ i ].value
        );
    }
    return;
}

void StackOfCards::drawCards( void ) {
    for (int i = 0; i < 16 ; i++) {
        elemets[ i ].DrawCard( BLUE );
    }
}

void StackOfCards::updateFuturePos( const CardInfo *info ) {
    int futureIndex;

    for (int i = 0; i < 16; i++) {
        if ( elemets[ i ].getValue() == 0 ) {
            continue;
        }


        futureIndex = info[ i ].futureIndex;

        std::cout << i << '\n';
        std::cout << futureIndex << '\n';

        elemets[ i ].setFuturePos( positions[ futureIndex ] );
    }
    return;
}

void StackOfCards::updateCards( void ) {
    for (int i = 0; i < 16; i++) {
        elemets[ i ].updateCardPos();
    }
    return;
}
