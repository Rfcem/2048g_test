#ifndef LOGIC_H
#define LOGIC_H

typedef struct CardInfo {
    int futureIndex { 0 };
    int value { 0 };
} CardInfo;

typedef struct CheckList {
    bool wasNewNumbAdded { false };
    bool thereAreZeros { false };
} CheckList;

CardInfo *initializeGrid( void );
void printGrid( CardInfo grid[] );
bool move( CardInfo *grid, int &key );
CheckList addNewNumber( CardInfo grid[], int key );
CheckList updateGrid( CardInfo grid[], int key );
bool checkPossibleMoves( CardInfo grid[] );

#endif
