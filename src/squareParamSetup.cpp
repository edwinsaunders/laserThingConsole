 #include "gridElement.hpp"
 #include <iostream>
 
//how to generalize for any square grid size?

 void squareParamsSetup(gridElement *grid, int gridSize) {   
    //setup parameters based on square position (corner square, border square, ports, sides with ports etc.)
    for (int i = 0; i < gridSize; i++) //rows
    {
        for (int j = 0; j < gridSize; j++) //cols
        {
            //not sure if this statement is useful
            grid[i * gridSize + j].pos = {i, j};
            //setup corner 
            if ((i == 0 && j == 0) || (i == (gridSize - 1) && j == (gridSize - 1)) || abs(i - j) == (gridSize - 1))
            {
                grid[i * gridSize + j].isCornerSquare = 1;
                if (i == 0 && j == 0) {
                    grid[i * gridSize + j].sidesWithPorts = {0, 3};
                    grid[i * gridSize + j].ports = {0, (gridSize * 4 - 1)};
                }
                else if (i == 0 && j == (gridSize - 1)) {
                    grid[i * gridSize + j].sidesWithPorts = {0, 1};
                    grid[i * gridSize + j].ports = {(gridSize - 1), gridSize};
                }
                else if (i == (gridSize - 1) && j == (gridSize - 1)) {
                    grid[i * gridSize + j].sidesWithPorts = {1, 2};
                    grid[i * gridSize + j].ports = {(gridSize * 2 - 1), (gridSize * 2)};
                }
                else {
                    grid[i * gridSize + j].sidesWithPorts = {2, 3};
                    grid[i * gridSize + j].ports = {(gridSize * 3 - 1), (gridSize * 3)};
                }
            }
            else {
                grid[i * gridSize + j].isCornerSquare = 0;
            }
            //set up other border square properties 
            if (i == 0 || i == (gridSize - 1) || j == 0 || j == (gridSize - 1)) {
                grid[i * gridSize + j].isBorderSquare = 1;
                if (grid[i * gridSize + j].isCornerSquare == 0) {
                    if (i == 0) {  //top of grid
                        grid[i * gridSize + j].sidesWithPorts = {0, 0};
                        grid[i * gridSize + j].ports = {j, j};
                    }
                    else if (j == 0) { //left side of grid
                        grid[i * gridSize + j].sidesWithPorts = {3, 3};
                        grid[i * gridSize + j].ports = {(gridSize * 4 - 1) - i, (gridSize * 4 - 1) - i};
                    }
                    else if (i == (gridSize - 1)) { //bottom of grid
                        grid[i * gridSize + j].sidesWithPorts = {2, 2};
                        grid[i * gridSize + j].ports = {(gridSize * 3 - 1) - j, (gridSize * 3 - 1) - j};
                    }
                    else { // the only squares remaining that meet the conditions should be on the right side of the grid
                        grid[i * gridSize + j].sidesWithPorts = {1, 1};
                        grid[i * gridSize + j].ports = {i + gridSize, i + gridSize};
                    }
                }
            }
            else {
                grid[i * gridSize + j].isBorderSquare = 0;
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
 //           grid[i][j].pos = {i, j};
 //           //setup corner 
 //           if ((i == 0 && j == 0) || (i == 4 && j == 4) || abs(i - j) == 4)
 //           {
 //               grid[i][j].isCornerSquare = 1;
 //               if (i == 0 && j == 0) {
 //                   grid[i][j].sidesWithPorts = {0, 3};
 //                   grid[i][j].ports = {0, 19};
 //               }
 //               else if (i == 0 && j == 4) {
 //                   grid[i][j].sidesWithPorts = {0, 1};
 //                   grid[i][j].ports = {4, 5};
 //               }
 //               else if (i == 4 && j == 4) {
 //                   grid[i][j].sidesWithPorts = {1, 2};
 //                   grid[i][j].ports = {9, 10};
 //               }
 //               else {
 //                   grid[i][j].sidesWithPorts = {2, 3};
 //                   grid[i][j].ports = {14, 15};
 //               }
 //           }
 //           else {
 //               grid[i][j].isCornerSquare = 0;
 //           }
 //           //set up other border square properties 
 //           if (i == 0 || i == 4 || j == 0 || j == 4) {
 //               grid[i][j].isBorderSquare = 1;
 //               if (grid[i][j].isCornerSquare == 0) {
 //                   if (i == 0) {  //top of grid
 //                       grid[i][j].sidesWithPorts = {0, 0};
 //                       grid[i][j].ports = {j, j};
 //                   }
 //                   else if (j == 0) { //left side of grid
 //                       grid[i][j].sidesWithPorts = {3, 3};
 //                       grid[i][j].ports = {19 - i, 19 - i};
 //                   }
 //                   else if (i == 4) { //bottom of grid
 //                       grid[i][j].sidesWithPorts = {2, 2};
 //                       grid[i][j].ports = {14 - j, 14 - j};
 //                   }
 //                   else { // the only squares remaining that meet the conditions should be on the right side of the grid
 //                       grid[i][j].sidesWithPorts = {1, 1};
 //                       grid[i][j].ports = {i + 5, i + 5};
 //                   }
 //               }
 //           }
 //           else {
 //               grid[i][j].isBorderSquare = 0;
 //           }
 //           
 //       }
 //   }
 //}