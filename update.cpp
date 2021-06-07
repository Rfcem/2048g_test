
#include "include\logic.h"

void refreshIndex( CardInfo grid[] ) {
    for (int i = 0; i < 16; i++) {
        grid[ i ].futureIndex = i;
    }
}

CheckList updateGrid( CardInfo grid[], int key) {
    CheckList checkL;

    refreshIndex( grid );
    checkL = addNewNumber( grid, key );

    return checkL;
}
