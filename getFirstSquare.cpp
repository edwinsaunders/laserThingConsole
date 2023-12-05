//getFirstSquare
//find square that corrsponds with entrance port and side for inputEdge

#include "gridElement.hpp"

void getFirstSquare(gridElement (&square)[5][5], int &entrancePort, int &currentRow, int &currentCol) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (square[i][j].isBorderSquare) {
                if (entrancePort == square[i][j].ports[0]) {
                    square[i][j].inputEdge = square[i][j].sidesWithPorts[0];
                    currentRow = i;
                    currentCol = j;
                }
                else if (entrancePort == square[i][j].ports[1]) {
                    square[i][j].inputEdge = square[i][j].sidesWithPorts[1];
                    currentRow = i;
                    currentCol = j;  
                }
            }
        }
    }
}