//function to set mirror pattern
#include "gridElement.hpp"

void setGridPattern(gridElement *grid, std::vector<char>& gridPattern, int gridSize) {
    //std::string line;
    
    for (int i = 0; i < gridSize; i++) //rows
    {
        //line = gridPattern[i];
        for (int j = 0; j < gridSize; j++) //cols
        {
            //char c = line[j];
            grid[i * gridSize + j].mirrorConfig = gridPattern[i * gridSize + j];
        }
    }
}