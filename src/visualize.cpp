//function to display a grid of squares to the console
//Right now, it  just displays a zero, a backslash(1) or a forwardslash(2)
#include "gridElement.hpp"
#include <iostream>
#include <iomanip>

void visualize(gridElement *grid, int gridSize) {

//print top side port numbers

    std::cout << "    ";
    for (int i = 0; i < gridSize; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << i << " ";
    }
    std::cout << std::endl;

//prints a port number followed by a row of the grid pattern followed by the opposite side port number

    for (int i = 0; i < gridSize; i++) //rows
    {
        std::cout << std::setw(2) << std::setfill('0') << (gridSize * 4 - 1) - i << "  ";
        
        for (int j = 0; j < gridSize; j++) //cols
        {
            std::cout << grid[i * gridSize + j].mirrorConfig << "  ";
        }

        std::cout << std::setw(2) << std::setfill('0') << gridSize + i << std::endl;
    }

//print bottom side port numbers

    std::cout << "    ";
    for (int i = 0; i < gridSize; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << (gridSize * 3 - 1) - i << " ";
    }
    std::cout << std::endl << std::endl;

   
}