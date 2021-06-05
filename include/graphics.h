#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

#include "logic.h"

class GraphicGrid {
    protected:
        Rectangle background;
        Rectangle spaces[ 16 ];
        float spaceSize;
    public:
        GraphicGrid( float, float, float );
        void drawGrid( Color, Color );
        float getSpaceSize( void );
        Vector2 getSpacePos( int );
};

class Card {
    protected:
        Vector2 actualPosition;
        float size;
        int value;
        Vector2 futurePosition;

    public:
        Card( void );
        void setParameters( Vector2, float, int );
        void setFuturePos( Vector2 );
        void updateCardPos( void );
        void DrawCard( Color );
        int getValue( void );
};

class StackOfCards {
    protected:
        Card elemets[ 16 ];
        Vector2 positions[ 16 ];
    public:
        StackOfCards( const CardInfo*, GraphicGrid );
        void drawCards( void );
        void updateFuturePos( const CardInfo* );
        void updateCards( void );

};

#endif
