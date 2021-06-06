#include <iostream>
#include <cmath>

#include "include/raylib.h"
#include "include/graphics.h"



Color selectColor( int val ) {

    switch ( val ) {
        case 2:
            return CARDCOLOR1;
        case 4:
            return CARDCOLOR2;
        case 8:
            return CARDCOLOR3;
        case 16:
            return CARDCOLOR4;
        case 32:
            return CARDCOLOR5;
        case 64:
            return CARDCOLOR6;
        case 128:
            return CARDCOLOR7;
        case 256:
            return CARDCOLOR8;
        case 512:
            return CARDCOLOR9;
        case 1024:
            return CARDCOLOR10;
        case 2048:
            return CARDCOLOR11;
        case 4096:
            return CARDCOLOR12;
        case 8192:
            return CARDCOLOR13;
        case 16384:
            return CARDCOLOR14;
    }



    return CARDCOLOR15;
}


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

void Card::drawText( void ) {
    float xPosFactor;
    float yPosFactor;
    float sizeFactor;

    if ( value  < 10  ) {
        xPosFactor = 0.4;
        yPosFactor = 0.3;
        sizeFactor = 0.5;
    } else if ( value  < 100 ) {
        xPosFactor = 0.25;
        yPosFactor = 0.3;
        sizeFactor = 0.5;
    } else if ( value  < 1000 ) {
        xPosFactor = 0.2;
        yPosFactor = 0.35;
        sizeFactor = 0.4;
    } else if ( value < 10000 ) {
        xPosFactor = 0.15;
        yPosFactor = 0.4;
        sizeFactor = 0.3;
    } else {
        xPosFactor = 0.2;
        yPosFactor = 0.4;
        sizeFactor = 0.3;
    }

    DrawText( TextFormat( "%d", value ),
        actualPosition.x + size * xPosFactor,
        actualPosition.y + size * yPosFactor,
        size * sizeFactor,
        WHITE
    );

}

void Card::DrawCard( void ) {

    if ( value == 0) {
        return;
    }


    DrawRectangleRounded(
        {actualPosition.x, actualPosition.y, size, size},
        0.1,
        0,
        selectColor( value )
    );

    drawText();


    return;
}

void Card::setFuturePos( Vector2 pos ) {
    futurePosition = pos;
    return;
}

void Card::setValue( int val ) {
    value = val;
    return;
}

void Card::setPos( Vector2 pos ) {
    actualPosition = pos;
    return;
}

bool Card::updateCardPos( void ) {
    float difference = 0;
    if ( actualPosition.x != futurePosition.x ) {

        difference = futurePosition.x - actualPosition.x;

        if ( std::abs( difference ) < size * 0.2 ) {

            actualPosition.x = futurePosition.x;
            return true;


        } else {

            actualPosition.x += ( difference ) / 2 ;
        }

    } else if ( actualPosition.y != futurePosition.y ) {

        difference = futurePosition.y - actualPosition.y;

        if ( std::abs( difference ) < size * 0.2 ) {

            actualPosition.y = futurePosition.y;
            return true;


        } else {

            actualPosition.y += ( difference ) / 2 ;
        }
    } else {

        return true;

    }

    return false;

}

int Card::getValue( void ) {
    return value;
}
