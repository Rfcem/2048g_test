

typedef struct checkList {
    bool wasNewNumbAdded = false;
    bool thereAreZeros = false;
} checkList;

int *initializeGrid( void );
void printGrid( int grid[] );
checkList addNewNumber( int grid[], char direction );
bool checkPossibleMoves( int grid[] );
