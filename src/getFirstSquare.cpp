//getFirstSquare
//find square that corrsponds with entrance port and side for inputEdge

#include "gridElement.hpp"

void getFirstSquare(gridElement *square, int &entrancePort, int &currentRow, int &currentCol, int gridSize) {

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (square[i * gridSize + j].isBorderSquare) {
                if (entrancePort == square[i * gridSize + j].ports[0]) {
                    square[i * gridSize + j].inputEdge = square[i * gridSize + j].sidesWithPorts[0];
                    currentRow = i;
                    currentCol = j;
                }
                else if (entrancePort == square[i * gridSize + j].ports[1]) {
                    square[i * gridSize + j].inputEdge = square[i * gridSize + j].sidesWithPorts[1];
                    currentRow = i;
                    currentCol = j;  
                }
            }
        }
    }
}