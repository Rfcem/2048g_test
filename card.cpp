#include <iostream>
#include <cmath>

#include "include/raylib.h"
#include "include/graphics.h"

Card::Card( void ) {
    actualPosition = {0, 0};
    size = 0;
    value = 0;
    futurePosition = {0, 0};
}

void Card::setParameters( Vector2 pos, float sz, int val) {
    actualPosition = pos;
    size = sz;
    value = val;
    futurePosition = pos;
    return;
}

void Card::DrawCard( Color color ) {

    if ( value == 0) {
        return;
    }

    DrawRectangleV( actualPosition,
        {size, size},
        color
    );

    DrawText( TextFormat( "%d", value ),
        actualPosition.x + size * 0.4,
        actualPosition.y + size * 0.4,
        size * 0.25,
        LIGHTGRAY
    );
    return;
}

void Card::setFuturePos( Vector2 pos ) {
    futurePosition = pos;
    return;
}

void Card::updateCardPos( void ) {
    float difference = 0;
    if ( actualPosition.x != futurePosition.x ) {

        difference = futurePosition.x - actualPosition.x;

        if ( std::abs( difference ) < 2 ) {

            actualPosition.x = futurePosition.x;

        } else {

            actualPosition.x += ( difference ) / 4 ;
        }

    } else if ( actualPosition.y != futurePosition.y ) {

        difference = futurePosition.y - actualPosition.y;

        if ( std::abs( difference ) < 2 ) {

            actualPosition.y = futurePosition.y;

        } else {

            actualPosition.y += ( difference ) / 4 ;
        }
    }

    return;

}

int Card::getValue( void ) {
    return value;
}
