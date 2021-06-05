#include <iostream>

#include "include/raylib.h"

#include "include/graphics.h"
#include "include/logic.h"

StackOfCards::StackOfCards( const CardInfo *info, GraphicGrid grid ) {
    cardsUpdated = true;
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
        elemets[ i ].DrawCard();
    }
}

void StackOfCards::updateFuturePos( const CardInfo *info ) {
    int futureIndex;
    cardsUpdated = false;
    for (int i = 0; i < 16; i++) {
        if ( elemets[ i ].getValue() == 0 ) {
            continue;
        }


        futureIndex = info[ i ].futureIndex;

        elemets[ i ].setFuturePos( positions[ futureIndex ] );
    }
    return;
}

bool StackOfCards::updateCards( void ) {
    bool updated = true;

    for (int i = 0; i < 16; i++) {
        if (elemets[ i ].getValue() == 0) {
            continue;
        }
        updated = elemets[ i ].updateCardPos() && updated;
    }

    cardsUpdated = updated;

    return cardsUpdated;
}

void StackOfCards::refresh( const CardInfo *info ) {
    for (int i = 0; i < 16; i++) {
        elemets[ i ].setPos( positions[ i ] );
        elemets[ i ].setFuturePos( positions[ i ] );
        elemets[ i ].setValue( info[ i ].value );
    }
}
