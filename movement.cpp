#include <iostream>

int move_up( int currentPos, int grid[]);

int main() {
    int currentGrid[16];
    int newGrid[16];
    int newPos;

    for (int i = 0; i < 16; i++) {
        currentGrid[i] = 0;
        newGrid[i] = 0;
    }
    currentGrid[1] = 4;
    currentGrid[5] = 2;
    currentGrid[9] = 2;

    std::cout << "Initial Grid" << '\n';
    for (int i = 0; i < 16; i++) {
        std::cout << ( (i % 4)? " ": "\n" ) << currentGrid[i];
    }

    for (int i = 0; i < 16; i++) {
        if (currentGrid[i] == 0) {
            continue;
        }
        newPos = move_up(i, currentGrid);
        std::cout << "newPos " << newPos << '\n';
        newGrid[newPos] = currentGrid[i];
        std::cout << "Current Value " << currentGrid[i] << '\n';
    }


    std::cout << "\n\nFinal Grid" << '\n';
    for (int i = 0; i < 16; i++) {
        std::cout << ( (i % 4)? " ": "\n" ) << newGrid[i];
    }

    std::cout << "Initial Grid" << '\n';
    for (int i = 0; i < 16; i++) {
        std::cout << ( (i % 4)? " ": "\n" ) << currentGrid[i];
    }


    return 0;
}

int move_up( int currentPos, int grid[]){
    int freePos = 0;
    int newPos = currentPos;
    bool posibleMerge = true;
    int actualValue = grid[currentPos];

    currentPos -= 4;
    while (currentPos >= 0) {
        if (grid[currentPos] == 0) {
            ++freePos;
        } else if( grid[currentPos] == actualValue && posibleMerge){
            grid[currentPos] += actualValue;
            grid[newPos] = 0;
            posibleMerge = false;
        } else {
            posibleMerge = false;
        }
        currentPos -= 4;
    }

    newPos -= freePos * 4;
    return  newPos;
}
