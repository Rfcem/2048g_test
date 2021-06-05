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
void printGrid( int grid[] );
checkList addNewNumber( CardInfo grid[] );
bool checkPossibleMoves( CardInfo grid[] );
bool move( CardInfo *grid );

#endif
