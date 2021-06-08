#ifndef LOGIC_H
#define LOGIC_H

#include <array>

typedef struct CardInfo {
    int futureIndex { 0 };
    int value { 0 };
} CardInfo;

typedef struct CheckList {
    bool wasNewNumbAdded { false };
    bool thereAreZeros { false };
} CheckList;

std::array< CardInfo, 16 > initializeGrid( void );
void printGrid( const std::array< CardInfo, 16 > );
bool move( std::array< CardInfo, 16 > & , int & , int &);
CheckList addNewNumber( std::array< CardInfo, 16 > & , const int );
CheckList updateGrid( std::array< CardInfo, 16 > & , const int  );
bool checkPossibleMoves( std::array< CardInfo, 16 > );

#endif
