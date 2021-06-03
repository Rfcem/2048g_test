#include <iostream>
#include <set>

#include "include\logic.h"

bool moveUp( int grid[]);
bool moveDown( int grid[]);
bool moveRight( int grid[]);
bool moveLeft( int grid[]);

int main() {
    int *currentGrid;
    char key;
    bool wasMoved;
    checkList currentChekList;

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

        currentChekList = addNewNumber( currentGrid, key );
        if ( currentChekList.wasNewNumbAdded ) {
            std::system("cls");
            std::cout << "Current Game" << "\n\n";
            printGrid( currentGrid );
        }
        if ( !currentChekList.thereAreZeros ){
            if ( !checkPossibleMoves( currentGrid ) ) {
                std::cout << "Game Over!!! " << '\n';
                break;
            }
        }

    }

    return 0;
}


bool updateUpPositions( int pos, int grid[], std::set<int> &posOfDoubledVals){
    int currentValue = grid[ pos];
    int newPos = pos - 4;
    int moved = false;

    while ( newPos >= 0) {
        if ( grid[newPos] == 0) {
            grid[newPos] = currentValue;
            grid[pos] = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos] == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()){
                return moved;
            }
            grid[newPos] = 2 * currentValue;
            posOfDoubledVals.insert(newPos);
            grid[pos] = 0;
            moved = true;
            return moved;
        } else {
            return moved;
        }
        newPos -= 4;
    }
    return moved;
}

bool updateDownPositions( int pos, int grid[], std::set<int> &posOfDoubledVals){
    int currentValue = grid[ pos];
    int newPos = pos + 4;
    int moved = false;

    while ( newPos < 16) {
        if ( grid[newPos] == 0) {
            grid[newPos] = currentValue;
            grid[pos] = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos] == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()){
                return moved;
            }
            grid[newPos] = 2 * currentValue;
            posOfDoubledVals.insert(newPos);
            grid[pos] = 0;

            moved = true;
            return moved;
        } else {
            return moved;
        }
        newPos += 4;
    }
    return moved;
}

bool updateRightPositions( int pos, int grid[], std::set<int> &posOfDoubledVals) {
    int currentValue = grid[ pos];
    int newPos = pos + 1;
    int moved = false;

    while ( ( newPos % 4) != 0 ) {
        if ( grid[newPos] == 0) {
            grid[newPos] = currentValue;
            grid[pos] = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos] == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()){
                return moved;
            }
            grid[newPos] = 2 * currentValue;
            posOfDoubledVals.insert(newPos);
            grid[pos] = 0;
            moved = true;
            return moved;
        } else {
            return moved;
        }
        ++newPos;
    }
    return moved;
}

bool updateLeftPositions( int pos, int grid[], std::set<int> &posOfDoubledVals) {
    int currentValue = grid[ pos];
    int newPos = pos - 1;
    int moved = false;

    while ( ( (newPos + 1) % 4) != 0) {
        if ( grid[newPos] == 0) {
            grid[newPos] = currentValue;
            grid[pos] = 0;
            pos = newPos;
            moved = true;
        } else if ( grid[newPos] == currentValue) {
            if( posOfDoubledVals.find(newPos) != posOfDoubledVals.end()){
                return moved;
            }
            grid[newPos] = 2 * currentValue;
            posOfDoubledVals.insert(newPos);
            grid[pos] = 0;
            moved = true;
            return moved;
        } else {
            return moved;
        }
        --newPos;
    }
    return moved;
}

bool moveUp( int grid[]){
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for (int i = 0; i < 16; i++) {
        if (grid[i] == 0) {
            continue;
        }
        wasMoved = updateUpPositions( i, grid, posOfDoubledVals ) || wasMoved;
    }

    return wasMoved;
}

bool moveDown( int grid[]){
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for (int i = 15; i >= 0; i--) {
        if (grid[i] == 0) {
            continue;
        }
        wasMoved = updateDownPositions( i, grid, posOfDoubledVals ) || wasMoved;
    }

    return wasMoved;
}

bool moveRight( int grid[]){
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for ( int i = 15; i >= 0; i-- ) {
        if ( grid[i] == 0 ) {
            continue;
        }
        wasMoved = updateRightPositions( i, grid, posOfDoubledVals ) || wasMoved;
    }

    return wasMoved;
}

bool moveLeft( int grid[]){
    std::set<int> posOfDoubledVals;
    bool wasMoved = false;

    for ( int i = 0; i < 16; i++ ) {
        if ( grid[i] == 0 ) {
            continue;
        }
        wasMoved = updateLeftPositions( i, grid, posOfDoubledVals ) || wasMoved;
    }


    return wasMoved;
}
