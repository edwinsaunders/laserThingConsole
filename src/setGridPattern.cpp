//function to set mirror pattern
#include "gridElement.hpp"

void setGridPattern(gridElement *square, char *gridPattern, int gridSize) {
    for (int i = 0; i < gridSize; i++) //rows
    {
        for (int j = 0; j < gridSize; j++) //cols
        {
            square[i * gridSize + j].mirrorConfig = gridPattern[i * gridSize + j];
        }
    }
}