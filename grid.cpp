#include "include/raylib.h"
#include "include/graphics.h"

GraphicGrid::GraphicGrid( float xPosition, float yPosition, float size ) {
    float separation = size * 0.02;
    float spacePosX = xPosition;
    float spacePosY = yPosition;

    spaceSize = ( size * 0.9 ) / 4;

    background.x = xPosition;
    background.y = yPosition;
    background.width = size;
    background.height = size;

    for ( int i = 0; i < 16; i++ ) {
        spaces[ i ].width = spaceSize;
        spaces[ i ].height = spaceSize;

        if ( ( i % 4 ) == 0 ) {
            spacePosX = separation + xPosition;
            if ( i == 0 ) {
                spacePosY += separation;
            } else {
                spacePosY += spaceSize + separation;
            }

        } else {
            spacePosX += spaceSize + separation;
        }
        spaces[ i ].x = spacePosX;
        spaces[ i ].y = spacePosY;

    }
}

void GraphicGrid::drawGrid( Color backgroundColor, Color spaceColor ){
    DrawRectangleRounded( background, 0.05, 0, backgroundColor );
    for ( int i = 0; i < 16; i++ ) {
        DrawRectangleRounded( spaces[ i ], 0.1, 0, spaceColor );
    }
}

float GraphicGrid::getSpaceSize( void ) {
    return spaceSize;
}

Vector2 GraphicGrid::getSpacePos( int spaceNumber ) {
    Vector2 position { spaces[ spaceNumber ].x, spaces[ spaceNumber ].y };
    return position;
}
