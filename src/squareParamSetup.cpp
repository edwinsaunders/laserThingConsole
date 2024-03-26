 #include "gridElement.hpp"
 #include <iostream>
 
//how to generalize for any square grid size?

 void squareParamsSetup(gridElement *square, int gridSize) {   
    //setup parameters based on square position (corner square, border square, ports, sides with ports etc.)
    for (int i = 0; i < gridSize; i++) //rows
    {
        for (int j = 0; j < gridSize; j++) //cols
        {
            //not sure if this statement is useful
            square[i * gridSize + j].pos = {i, j};
            //setup corner 
            if ((i == 0 && j == 0) || (i == (gridSize - 1) && j == (gridSize - 1)) || abs(i - j) == (gridSize - 1))
            {
                square[i * gridSize + j].isCornerSquare = 1;
                if (i == 0 && j == 0) {
                    square[i * gridSize + j].sidesWithPorts = {0, 3};
                    square[i * gridSize + j].ports = {0, (gridSize * 4 - 1)};
                }
                else if (i == 0 && j == (gridSize - 1)) {
                    square[i * gridSize + j].sidesWithPorts = {0, 1};
                    square[i * gridSize + j].ports = {(gridSize - 1), gridSize};
                }
                else if (i == (gridSize - 1) && j == (gridSize - 1)) {
                    square[i * gridSize + j].sidesWithPorts = {1, 2};
                    square[i * gridSize + j].ports = {(gridSize * 2 - 1), (gridSize * 2)};
                }
                else {
                    square[i * gridSize + j].sidesWithPorts = {2, 3};
                    square[i * gridSize + j].ports = {(gridSize * 3 - 1), (gridSize * 3)};
                }
            }
            else {
                square[i * gridSize + j].isCornerSquare = 0;
            }
            //set up other border square properties 
            if (i == 0 || i == (gridSize - 1) || j == 0 || j == (gridSize - 1)) {
                square[i * gridSize + j].isBorderSquare = 1;
                if (square[i * gridSize + j].isCornerSquare == 0) {
                    if (i == 0) {  //top of grid
                        square[i * gridSize + j].sidesWithPorts = {0, 0};
                        square[i * gridSize + j].ports = {j, j};
                    }
                    else if (j == 0) { //left side of grid
                        square[i * gridSize + j].sidesWithPorts = {3, 3};
                        square[i * gridSize + j].ports = {(gridSize * 4 - 1) - i, (gridSize * 4 - 1) - i};
                    }
                    else if (i == (gridSize - 1)) { //bottom of grid
                        square[i * gridSize + j].sidesWithPorts = {2, 2};
                        square[i * gridSize + j].ports = {(gridSize * 3 - 1) - j, (gridSize * 3 - 1) - j};
                    }
                    else { // the only squares remaining that meet the conditions should be on the right side of the grid
                        square[i * gridSize + j].sidesWithPorts = {1, 1};
                        square[i * gridSize + j].ports = {i + gridSize, i + gridSize};
                    }
                }
            }
            else {
                square[i * gridSize + j].isBorderSquare = 0;
            }
            
        }
    }
 }

//old function with hard-coded grid size of 5

 //void squareParamsSetup(gridElement (&square)[5][5]) {   
 //   //setup parameters based on square position (corner square, border square, ports, sides with ports etc.)
 //   for (int i = 0; i < 5; i++) //rows
 //   {
 //       for (int j = 0; j < 5; j++) //cols
 //       {
 //           //not sure if this statement is useful
 //           square[i][j].pos = {i, j};
 //           //setup corner 
 //           if ((i == 0 && j == 0) || (i == 4 && j == 4) || abs(i - j) == 4)
 //           {
 //               square[i][j].isCornerSquare = 1;
 //               if (i == 0 && j == 0) {
 //                   square[i][j].sidesWithPorts = {0, 3};
 //                   square[i][j].ports = {0, 19};
 //               }
 //               else if (i == 0 && j == 4) {
 //                   square[i][j].sidesWithPorts = {0, 1};
 //                   square[i][j].ports = {4, 5};
 //               }
 //               else if (i == 4 && j == 4) {
 //                   square[i][j].sidesWithPorts = {1, 2};
 //                   square[i][j].ports = {9, 10};
 //               }
 //               else {
 //                   square[i][j].sidesWithPorts = {2, 3};
 //                   square[i][j].ports = {14, 15};
 //               }
 //           }
 //           else {
 //               square[i][j].isCornerSquare = 0;
 //           }
 //           //set up other border square properties 
 //           if (i == 0 || i == 4 || j == 0 || j == 4) {
 //               square[i][j].isBorderSquare = 1;
 //               if (square[i][j].isCornerSquare == 0) {
 //                   if (i == 0) {  //top of grid
 //                       square[i][j].sidesWithPorts = {0, 0};
 //                       square[i][j].ports = {j, j};
 //                   }
 //                   else if (j == 0) { //left side of grid
 //                       square[i][j].sidesWithPorts = {3, 3};
 //                       square[i][j].ports = {19 - i, 19 - i};
 //                   }
 //                   else if (i == 4) { //bottom of grid
 //                       square[i][j].sidesWithPorts = {2, 2};
 //                       square[i][j].ports = {14 - j, 14 - j};
 //                   }
 //                   else { // the only squares remaining that meet the conditions should be on the right side of the grid
 //                       square[i][j].sidesWithPorts = {1, 1};
 //                       square[i][j].ports = {i + 5, i + 5};
 //                   }
 //               }
 //           }
 //           else {
 //               square[i][j].isBorderSquare = 0;
 //           }
 //           
 //       }
 //   }
 //}