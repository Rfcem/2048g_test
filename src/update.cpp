
#include "include\logic.h"

void refreshIndex( std::array< CardInfo, 16 > &grid ) {
    for (int i = 0; i < 16; i++) {
        grid[ i ].futureIndex = i;
    }
}

CheckList updateGrid( std::array< CardInfo, 16 > &grid, const int key) {
    CheckList checkL;

    refreshIndex( grid );
    checkL = addNewNumber( grid, key );

    return checkL;
}
