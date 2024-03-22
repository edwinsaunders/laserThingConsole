//This header defines a gridElement data type with a functions that
//computes an output edge for a given input on a single square.

//UNNECESSARY MEMBER VARIABLES (just keeping them here as a memory aid of how i was thinking earlier in the project)
//bool inputPresent{0};
//bool mirrorPresent{0};
//bool mirrorOrientation{0};  // 0 is "backslash" orientation, 1 is "forwardslash"

#ifndef GRIDELEMENT_HPP
#define GRIDELEMENT_HPP


#include <vector>

struct gridElement {
    bool isBorderSquare{0};
    bool isCornerSquare{0};
    std::vector<int> ports{-1, -1};          //must match ports with sides (same index in vector)
    std::vector<int> sidesWithPorts{-1, -1};  //0 is top of square(contains port 0), 3 is left side (contains port 19)
    
    int inputEdge{-1}, outputEdge{-1};  // 0 thru 3 respresent top, right, bottom, left, respectively
    int numAdjacentSquares{0};
    std::vector<int> adjacent1{0}, adjacent2{0}, adjacent3{0}, adjacent4{0};
    std::vector<int> pos{0};
    char mirrorConfig;
    

    
    void getOutputEdge();
             
   
    
};

void squareParamsSetup(gridElement (&square)[5][5]);
void visualize(gridElement (&square)[5][5]);
void setGridPattern(gridElement (&square)[5][5], char (&gridPattern)[5][5]);
void printZeroGrid();
void getFirstSquare(gridElement (&square)[5][5], int &entrancePort, int &currentRow, int &currentCol);
void getNextSquare(gridElement (&square)[5][5], int &currentRow, int &currentCol, int &nextRow, int &nextCol);

#endif