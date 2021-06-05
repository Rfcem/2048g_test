#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "include\raylib.h"

#include "include\logic.h"


std::vector<int> findZerosFromBottom( CardInfo grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 12; i < 16; i++) {
        j = i;
        while( j >= 0 ){
            if ( grid[ j ].value == 0) {
                zerosPos.push_back( j );
                j -= 4;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}

std::vector<int> findZerosFromTop( CardInfo grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 0; i < 4; i++) {
        j = i;
        while( j < 16 ){
            if ( grid[ j ].value == 0) {
                zerosPos.push_back( j );
                j += 4;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}

std::vector<int> findZerosFromLeft( CardInfo grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 0; i < 16; i += 4) {
        j = i;
        while( j < (i + 4) ){
            if ( grid[ j ].value == 0) {
                zerosPos.push_back( j );
                ++j;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}

std::vector<int> findZerosFromRight( CardInfo grid[] ){
    int j;
    std::vector<int> zerosPos;
    for ( int i = 3; i < 16; i += 4 ) {
        j = i;
        while( j > ( i - 4 ) ){
            if ( grid[ j ].value == 0) {
                zerosPos.push_back( j );
                --j;
            } else {
                break;
            }
        }
    }
    return zerosPos;
}


checkList addNewNumber( CardInfo grid[], int key ) {
    std::vector<int> zerosPos;
    int zerosQuantity;
    int newNumVectPos;
    checkList chlist1;

    if ( key ==  KEY_UP  ) {
        zerosPos = findZerosFromBottom( grid );

    } else if ( key ==  KEY_DOWN  ) {
        zerosPos =  findZerosFromTop( grid );

    } else if ( key ==  KEY_LEFT  ) {
        zerosPos =  findZerosFromRight( grid );

    } else if ( key ==  KEY_RIGHT  ) {
        zerosPos =  findZerosFromLeft( grid );
    } else {
        return chlist1;
    }

    zerosQuantity = zerosPos.size();

    if ( zerosQuantity == 0 ) {

        return chlist1;

    } else if (zerosQuantity == 1) {
        grid[ zerosPos[ 0 ] ].value = 2;
        chlist1.wasNewNumbAdded = true;
        return chlist1;

    } else {
        srand( time( NULL ) );
        newNumVectPos = rand() % zerosQuantity;
        grid[ zerosPos[ newNumVectPos ] ].value = 2;
    }
    chlist1.wasNewNumbAdded = true;
    chlist1.thereAreZeros = true;

    return chlist1;

}
