//getFirstSquare
//find square that corrsponds with entrance port and side for inputEdge

#include "gridElement.hpp"

void getFirstSquare(gridElement *grid, int &entrancePort, int &currentRow, int &currentCol, int gridSize) {

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i * gridSize + j].isBorderSquare) {
                if (entrancePort == grid[i * gridSize + j].ports[0]) {
                    grid[i * gridSize + j].inputEdge = grid[i * gridSize + j].sidesWithPorts[0];
                    currentRow = i;
                    currentCol = j;
                }
                else if (entrancePort == grid[i * gridSize + j].ports[1]) {
                    grid[i * gridSize + j].inputEdge = grid[i * gridSize + j].sidesWithPorts[1];
                    currentRow = i;
                    currentCol = j;  
                }
            }
        }
    }
}