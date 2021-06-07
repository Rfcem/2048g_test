#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <array>

#include "raylib.h"

#include "logic.h"


#define CARDCOLOR1   CLITERAL(Color){ 217, 136, 128, 255 }
#define CARDCOLOR2   CLITERAL(Color){ 236, 112,  99, 255 }
#define CARDCOLOR3   CLITERAL(Color){ 195, 155, 211, 255 }
#define CARDCOLOR4   CLITERAL(Color){ 165, 105, 189, 255 }
#define CARDCOLOR5   CLITERAL(Color){ 127, 179, 213, 255 }
#define CARDCOLOR6   CLITERAL(Color){  46, 134, 193, 255 }
#define CARDCOLOR7   CLITERAL(Color){  72, 201, 176, 255 }
#define CARDCOLOR8   CLITERAL(Color){  22, 160, 133, 255 }
#define CARDCOLOR9   CLITERAL(Color){  82, 190, 128, 255 }
#define CARDCOLOR10  CLITERAL(Color){  46, 204, 113, 255 }
#define CARDCOLOR11  CLITERAL(Color){ 244, 208,  63, 255 }
#define CARDCOLOR12  CLITERAL(Color){ 245, 176,  65, 255 }
#define CARDCOLOR13  CLITERAL(Color){ 235, 152,  78, 255 }
#define CARDCOLOR14  CLITERAL(Color){ 211,  84,   0, 255 }
#define CARDCOLOR15  CLITERAL(Color){  44,  62,  80, 255 }



class GraphicGrid {
    protected:
        Rectangle background;
        std::array< Rectangle, 16  > spaces;
        float spaceSize { 0 };
    public:
        GraphicGrid( void );
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
        void drawText( void );

    public:
        Card( void );
        void setParameters( Vector2, float, int );
        void setFuturePos( Vector2 );
        void setValue( int );
        void setPos( Vector2 );
        bool updateCardPos( void );
        void drawCard( void );
        int getValue( void );

};

class StackOfCards {
    protected:
        std::array< Card, 16  > elemets;
        std::array< Vector2, 16  > positions;
        bool cardsUpdated { true };
    public:
        StackOfCards( const std::array< CardInfo, 16 >, GraphicGrid );
        void drawCards( void );
        void updateFuturePos( const std::array< CardInfo, 16 > );
        bool updateCards( void );
        void refresh( const std::array< CardInfo, 16 > );


};

#endif
