#ifndef LOGIC_H
#define LOGIC_H

typedef struct CardInfo {
    int futureIndex = 0;
    int value = 0;
} CardInfo;

typedef struct checkList {
    bool wasNewNumbAdded = false;
    bool thereAreZeros = false;
} checkList;

CardInfo *initializeGrid( void );
void printGrid( CardInfo grid[] );
bool move( CardInfo *grid, int &key );
checkList addNewNumber( CardInfo grid[], int key );
checkList updateGrid( CardInfo grid[], int key );
bool checkPossibleMoves( CardInfo grid[] );

#endif
