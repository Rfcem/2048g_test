#include <iostream>
#include <set>


#include "include\raylib.h"

#include "include\logic.h"


/*
int portoMain() {
    int *currentGrid;
    char key;
    bool wasMoved;
    CheckList currentChekList;

    currentGrid = initializeGrid();
    std::system("cls");
    std::cout << "New Game" << "\n\n";
    printGrid( currentGrid );

    for ( ; ; ) {
        std::cout << "\n\nPress (a/w/s/d) to move: ";
        std::cin >> key;
        std::cin.ignore();

        switch ( key ) {
            case 'a':
                wasMoved = moveLeft( currentGrid );
                break;
            case 'w':
                wasMoved = moveUp( currentGrid );
                break;

            case 's':
                wasMoved = moveDown( currentGrid );
                break;
            case 'd':
                wasMoved = moveRight( currentGrid );
                break;
            default:
                std::cerr << "Invalid input" << '\n';
                continue;
        }
        if ( !wasMoved ) {
            continue;
        }

        if ( currentChekList.wasNewNumbAdded ) {
            std::system("cls");
            std::cout << "Current Game" << "\n\n";
            printGrid( currentGrid );
        }
        if ( !currentChekList.thereAreZeros ) {
            if ( !checkPossibleMoves( currentGrid ) ) {
                std::cout << "Game Over!!! " << '\n';
                break;
            }
        }

    }

    return 0;
}
*/


bool updateUpPositions( int pos,
    std::array< CardInfo, 16 > &grid,
    std::set<int> &posOfDoubledVals,
    int &sumScore
) {

    int currentValue = grid[ pos].value;
    int previousI = pos;

    int newPos = pos - 4;
    int moved = false;

    while ( newPos >= 0) {
        if ( grid[newPos].value == 0) {
            grid[newPos].value = currentValue;
            grid[ previousI ].futureIndex = newPos;
            grid[ pos ].value = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos].value == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()) {
                return moved;
            }
            grid[newPos].value = 2 * currentValue;
            sumScore += 2 * currentValue;
            grid[ previousI ].futureIndex = newPos;
            posOfDoubledVals.insert(newPos);
            grid[pos].value = 0;
            moved = true;
            return moved;
        } else {
            return moved;
        }
        newPos -= 4;
    }
    return moved;
}

bool updateDownPositions( int pos,
    std::array< CardInfo, 16 > &grid,
    std::set<int> &posOfDoubledVals,
    int &sumScore
) {

    int currentValue = grid[ pos].value;
    int previousI = pos;

    int newPos = pos + 4;
    int moved = false;


    while ( newPos < 16) {
        if ( grid[newPos].value == 0) {
            grid[newPos].value = currentValue;
            grid[ previousI ].futureIndex = newPos;
            grid[ pos ].value = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos].value == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()) {
                return moved;
            }
            grid[newPos].value = 2 * currentValue;
            sumScore += 2 * currentValue;
            grid[ previousI ].futureIndex = newPos;
            posOfDoubledVals.insert(newPos);
            grid[pos].value = 0;

            moved = true;
            return moved;
        } else {
            return moved;
        }
        newPos += 4;
    }
    return moved;
}

bool updateRightPositions( int pos,
    std::array< CardInfo, 16 > &grid,
    std::set<int> &posOfDoubledVals,
    int &sumScore
) {

    int currentValue = grid[ pos].value;
    int previousI = pos;

    int newPos = pos + 1;
    int moved = false;


    while ( ( newPos % 4) != 0 ) {
        if ( grid[newPos].value == 0) {
            grid[newPos].value = currentValue;
            grid[ previousI ].futureIndex = newPos;
            grid[ pos ].value = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos].value == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()) {
                return moved;
            }
            grid[newPos].value = 2 * currentValue;
            sumScore += 2 * currentValue;
            grid[ previousI ].futureIndex = newPos;
            posOfDoubledVals.insert(newPos);
            grid[pos].value = 0;
            moved = true;
            return moved;
        } else {
            return moved;
        }
        ++newPos;
    }
    return moved;
}

bool updateLeftPositions( int pos,
    std::array< CardInfo, 16 > &grid,
    std::set<int> &posOfDoubledVals,
    int &sumScore
) {

    int currentValue = grid[ pos].value;
    int previousI = pos;

    int newPos = pos - 1;
    int moved = false;


    while ( ( (newPos + 1) % 4) != 0) {
        if ( grid[newPos].value == 0) {
            grid[newPos].value = currentValue;
            grid[ previousI ].futureIndex = newPos;
            grid[ pos ].value = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos].value == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()) {
                return moved;
            }
            grid[newPos].value = 2 * currentValue;
            sumScore += 2 * currentValue;
            grid[ previousI ].futureIndex = newPos;
            posOfDoubledVals.insert(newPos);
            grid[pos].value = 0;
            moved = true;
            return moved;
        } else {
            return moved;
        }
        --newPos;
    }
    return moved;
}

bool moveUp( std::array< CardInfo, 16 > &grid, int &sumScore  ) {
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for (int i = 0; i < 16; i++) {
        if ( grid[ i ].value == 0 ) {
            continue;
        }
        wasMoved = updateUpPositions( i, grid, posOfDoubledVals, sumScore )
            || wasMoved;
    }

    return wasMoved;
}

bool moveDown( std::array< CardInfo, 16 > &grid, int &sumScore  ) {
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for (int i = 15; i >= 0; i--) {
        if ( grid[ i ].value == 0 ) {
            continue;
        }
        wasMoved = updateDownPositions( i, grid, posOfDoubledVals, sumScore )
            || wasMoved;
    }

    return wasMoved;
}

bool moveRight( std::array< CardInfo, 16 > &grid, int &sumScore  ) {
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for ( int i = 15; i >= 0; i-- ) {
        if ( grid[ i ].value == 0 ) {
            continue;
        }
        wasMoved = updateRightPositions( i, grid, posOfDoubledVals, sumScore )
            || wasMoved;
    }

    return wasMoved;
}

bool moveLeft( std::array< CardInfo, 16 > &grid, int &sumScore ) {
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for ( int i = 0; i < 16; i++ ) {
        if ( grid[ i ].value == 0 ) {
            continue;
        }
        wasMoved = updateLeftPositions( i, grid, posOfDoubledVals, sumScore )
            || wasMoved;
    }


    return wasMoved;
}

bool move( std::array< CardInfo, 16 > &grid, int &key, int &sumScore ) {
    bool wasMoved = false;

    if ( IsKeyPressed( KEY_UP ) ) {
        key = KEY_UP;
        wasMoved = moveUp( grid, sumScore );

    } else if ( IsKeyPressed( KEY_DOWN ) ) {
        key = KEY_DOWN;
        wasMoved = moveDown( grid, sumScore );

    } else if ( IsKeyPressed( KEY_LEFT ) ) {
        key = KEY_LEFT;
        wasMoved = moveLeft( grid, sumScore );

    } else if ( IsKeyPressed( KEY_RIGHT ) ) {
        key = KEY_RIGHT;
        wasMoved = moveRight( grid, sumScore );
    }

    return wasMoved;
}
