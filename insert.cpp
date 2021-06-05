#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "include\raylib.h"

#include "include\logic.h"


std::vector<int> findZerosFromBottom( int grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 12; i < 16; i++) {
        j = i;
        while( j >= 0 ){
            if ( grid[ j ] == 0) {
                zerosPos.push_back( j );
                j -= 4;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}

std::vector<int> findZerosFromTop( int grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 0; i < 4; i++) {
        j = i;
        while( j < 16 ){
            if ( grid[ j ] == 0) {
                zerosPos.push_back( j );
                j += 4;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}

std::vector<int> findZerosFromLeft( int grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 0; i < 16; i += 4) {
        j = i;
        while( j < (i + 4) ){
            if ( grid[ j ] == 0) {
                zerosPos.push_back( j );
                ++j;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}

std::vector<int> findZerosFromRight( int grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 3; i < 16; i += 4 ) {
        j = i;
        while( j > ( i - 4 ) ){
            if ( grid[ j ] == 0) {
                zerosPos.push_back( j );
                --j;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}


checkList addNewNumber( int grid[] ) {
    std::vector<int> zerosPos;
    int zerosQuantity;
    int newNumVectPos;
    checkList chlist1;

    if ( IsKeyPressed( KEY_UP ) ) {
        zerosPos =  findZerosFromBottom( grid );

    } else if ( IsKeyPressed( KEY_DOWN ) ) {
        zerosPos =  findZerosFromTop( grid );

    } else if ( IsKeyPressed( KEY_LEFT ) ) {
        zerosPos =  findZerosFromRight( grid );

    } else if ( IsKeyPressed( KEY_RIGHT ) ) {
        zerosPos =  findZerosFromLeft( grid );
    } else {
        return chlist1;
    }

    zerosQuantity = zerosPos.size();
    srand( time( NULL ) );
    if ( zerosQuantity == 0 ) {

        return chlist1;

    } else if (zerosQuantity == 1) {
        grid[ zerosPos[ 0 ] ] = 2;
        chlist1.wasNewNumbAdded = true;
        return chlist1;

    } else {
        newNumVectPos = rand() % zerosQuantity;
        grid[ zerosPos[ newNumVectPos ] ] = 2;
    }
    chlist1.wasNewNumbAdded = true;
    chlist1.thereAreZeros = true;

    return chlist1;

}
