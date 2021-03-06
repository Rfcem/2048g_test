#include <iostream>
#include <string>

#include "include/raylib.h"

#include "include/graphics.h"
#include "include/logic.h"

int main(void)
{
    // Initialization
    //----------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;




    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");


    GraphicGrid currentGrid( 220, 10, screenWidth - 230.0f );

    std::array< CardInfo, 16 > data = initializeGrid();
    CheckList currentChekList;
    StackOfCards cards( data, currentGrid );
    int score = 0;
    int addScore = 0;
    bool moved = false;
    int key;



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //------------------------------------------------------------------------
        // TODO: Update your variables here


        // card2.updateCardPos();
        // currentChekList = ( move( data ) )? addNewNumber( data ) : currentChekList;

        if ( !moved ) {
            moved = move( data, key, addScore);
            if( moved ){
                cards.updateFuturePos( data );
            }
        } else {
            if ( cards.updateCards() ) {
                moved = false;
                currentChekList = updateGrid( data, key );
                cards.refresh( data );
                printGrid( data );
                score += addScore;
                addScore = 0;
            }
        }





        //------------------------------------------------------------------------

        // Draw
        //------------------------------------------------------------------------

        BeginDrawing();


        ClearBackground(RAYWHITE);
        currentGrid.drawGrid( { 113, 125, 126, 255 }, { 170, 183, 184, 255 } );

        // TODO: Fix the number font
        cards.drawCards();

        DrawText( TextFormat( "%d", score ), 10, 20, 20, BLACK );




        EndDrawing();



        //------------------------------------------------------------------------
    }

    // De-Initialization
    //----------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------------------------

    return 0;
}
