//function to display a grid of squares to the console
//Right now, it  just displays a zero, a backslash(1) or a forwardslash(2)
#include "gridElement.hpp"
#include <iostream>

void visualize(gridElement *grid, int gridSize) {

    std::cout << "    ";
    for (int i = 0; i < gridSize; i++)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;

    for (int i = 0; i < gridSize; i++) //rows
    {
        std::cout << (gridSize * 4 - 1) - i << "  ";
        
        for (int j = 0; j < gridSize; j++) //cols
        {
            std::cout << grid[i * gridSize + j].mirrorConfig << "  ";
        }

        std::cout << gridSize + i << std::endl;
        //std::cout << std::endl;
    }

    std::cout << "   ";
    for (int i = 0; i < gridSize; i++)
    {
        std::cout << (gridSize * 3 - 1) - i << " ";
    }
    std::cout << std::endl;

    //gridSize * 3 - 1
    //std::cout << "    14 13 12 11 10" << std::endl;
}