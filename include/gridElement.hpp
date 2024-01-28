//This header defines a gridElement data type with a functions that
//computes an output edge for a given input on a single square.

#ifndef GRIDELEMENT_HPP
#define GRIDELEMENT_HPP


#include <vector>

struct gridElement {
    bool isBorderSquare{0};
    bool isCornerSquare{0};
    std::vector<int> ports{-1, -1};          //must match ports with sides (same index in vector)
    std::vector<int> sidesWithPorts{-1, -1};  //0 is top of square(contains port 0), 3 is left side (contains port 19)
    //bool inputPresent{0};
    bool mirrorPresent{0};
    bool mirrorOrientation{0};  // 0 is "backslash" orientation, 1 is "forwardslash"
    int inputEdge{-1}, outputEdge{-1};  // 0 thru 3 respresent top, right, bottom, left, respectively
    int numAdjacentSquares{0};
    std::vector<int> adjacent1{0}, adjacent2{0}, adjacent3{0}, adjacent4{0};
    std::vector<int> pos{0};
    char mirrorConfig;
    

    //void getOutputEdge() {
    //    if (inputPresent) {  //is there input
    //        //is there a mirror
    //        if (mirrorPresent) {
    //            
    //            if (mirrorOrientation == 0) {                   // if mirror orientation is "backslash"
    //                if (inputEdge % 2 == 0)                     // if input edge is top or bottom
    //                    outputEdge = inputEdge + 1;             // in top(0), out right(1).  in bottom(2), out left(3)
    //                else                                        // if input edge is right or left
    //                    outputEdge = inputEdge - 1;             // in right(1), out top(0).  in left(3), out bottom(2)
    //            }
    //            else {                                          // if mirror is in "forwardslash" orientation
    //                if (inputEdge % 2 == 0)                     // if input edge is top or bottom
    //                    outputEdge = (inputEdge + 3) % 4;       // in top(0), out left(3).  in bottom(2), out right(1)
    //                else                                        // if input edge is right or left
    //                    outputEdge = (inputEdge + 1) % 4;       // in right(1), out bottom(2).  in left(3), out top(0)
    //            }
    //        }
    //        else {
    //            outputEdge = (inputEdge + 2) % 4;               // if no mirror in square, laser comes out opposite side
    //        }
    //    
    //    }
    //}

    //refactored getoutputedge function
    void getOutputEdge() {          
        switch (mirrorConfig)
            {
            case '\\':                                         // mirror at -45 degrees (backslash)
                if (inputEdge % 2 == 0)                     // if input edge is top or bottom
                    outputEdge = inputEdge + 1;             // in top(0), out right(1).  in bottom(2), out left(3)
                else                                        // if input edge is right or left
                    outputEdge = inputEdge - 1;             // in right(1), out top(0).  in left(3), out bottom(2)
                break;
            case '/':                                         // mirror at +45 degrees (forwardslash)
                if (inputEdge % 2 == 0)                     // if input edge is top or bottom
                    outputEdge = (inputEdge + 3) % 4;       // in top(0), out left(3).  in bottom(2), out right(1)
                else                                        // if input edge is right or left
                    outputEdge = (inputEdge + 1) % 4;       // in right(1), out bottom(2).  in left(3), out top(0)
                break;
            default:
                outputEdge = (inputEdge + 2) % 4;           // if no mirror in square, laser comes out opposite side
                break;
            }          
    }          
    // if mirror orientation is "backslash"
    //if input edge is top or bottom
    //in top(0), out right(1).  in bottom(2), out left(3)
    //if input edge is right or left
    //in right(1), out top(0).  in left(3), out bottom(2)
    //if mirror is in "forwardslash" orientation
    //if input edge is top or bottom
    //in top(0), out left(3).  in bottom(2), out right(1)
    //if input edge is right or left
    //in right(1), out bottom(2).  in left(3), out top(0)
    //if no mirror in square, laser comes out opposite side
    
};

void squareParamsSetup(gridElement (&square)[5][5]);
void visualize(gridElement (&square)[5][5]);
void setGridPattern(gridElement (&square)[5][5], char (&gridPattern)[5][5]);
void printZeroGrid();
void getFirstSquare(gridElement (&square)[5][5], int &entrancePort, int &currentRow, int &currentCol);
void getNextSquare(gridElement (&square)[5][5], int &currentRow, int &currentCol, int &nextRow, int &nextCol);

#endif