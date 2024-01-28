//function to display a grid of squares to the console
//Right now, it  just displays a zero, a backslash(1) or a forwardslash(2)
#include "gridElement.hpp"
#include <iostream>

void visualize(gridElement (&square)[5][5]) {

    std::cout << "    0  1  2  3  4" << std::endl;

    for (int i = 0; i < 5; i++) //rows
    {
        std::cout << 19 - i << "  ";
        
        for (int j = 0; j < 5; j++) //cols
        {
            std::cout << square[i][j].mirrorConfig << "  ";
            //switch (square[i][j].mirrorConfig)
            //{
            //case 1:
            //    std::cout << "\\  ";
            //    break;
            //case 2:
            //    std::cout << "/  ";
            //    break;
            //default:
            //    std::cout << "0  ";
            //    break;
            //}
            
        }
        std::cout << 5 + i << std::endl;
        //std::cout << std::endl;
    }

    std::cout << "    14 13 12 11 10" << std::endl;
}