#include "gridElement.hpp"

//refactored getoutputedge function, see old one below
void gridElement::getOutputEdge() {          
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
    //old function
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