//get next square
//if output edge is 0 -> go up(row-1), 1 -> go right(col+1), 2 -> go down(row+1), 3 -> go left(col-1)
//input edge of next square = outputedge of prev square + or - 2(+2 for going right or up, -2 for going down or left)

#include "gridElement.hpp"

void getNextSquare(gridElement (&square)[5][5], int &currentRow, int &currentCol, int &nextRow, int &nextCol) {
    switch (square[currentRow][currentCol].outputEdge) {
        case 0: //if topedge is current output edge go up and set input edge of next square
            nextRow = currentRow - 1;
            nextCol = currentCol;
            square[nextRow][nextCol].inputEdge = square[currentRow][currentCol].outputEdge + 2;
            break;
        case 1: //if right edge is current output edge go right and set input edge of next square
            nextRow = currentRow;
            nextCol = currentCol + 1;
            square[nextRow][nextCol].inputEdge = square[currentRow][currentCol].outputEdge + 2;
            break;
        case 2: //if bottom edge is current output edge go down and set input edge of next square
            nextRow = currentRow + 1;
            nextCol = currentCol;
            square[nextRow][nextCol].inputEdge = square[currentRow][currentCol].outputEdge - 2;
            break;
        case 3: //if left edge is current output edge go left and set input edge of next square
            nextRow = currentRow;
            nextCol = currentCol - 1;
            square[nextRow][nextCol].inputEdge = square[currentRow][currentCol].outputEdge - 2;
            break;
    }
}