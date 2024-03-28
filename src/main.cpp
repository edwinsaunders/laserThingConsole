#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "gridElement.hpp"

//Goals:
//DONE: Single grid mirrorConfig: change struct member variables to eliminate mirrorPresent and mirrorOrientation
//DONE:  make gridPattern and mirrorConfig array of chars, since math needs to done with them
//DONE:  Input grid config from text file
//DONE: grid size is now determined at runtime based on the grid size in the text file
//      ALMOST DONE: user-defined grid size 
//      code has been generalized so that you only have to change a single variable, gridSize, in the main declarations
//replace some of the vectors with arrays (not sure why i used vectors initially)
//find out if statement on line 10 of squareParamSetup.cpp is useful
//rename 'square' symbol to something like 'fiveSqrd'. Necessary?
//generalize or remove printZeroGrid.cpp.  Is this function necessary for anything?




int main(int argc, char *argv[]) {
    
    //declarations
    
    int entrancePort{0};
    int exitPort;
    int currentRow{0}, currentCol{0}, nextRow{0}, nextCol{0};

    //vector implementation of gridPattern so it can change dynamically at runtime
    std::vector<char> gridPattern;
    
    //open grid pattern text file gridPattern.txt
    std::ifstream inputFile("../gridPattern.txt");
    if (!inputFile) {
        std::cerr << "Unable to open the grid pattern text file. Is it in the parent directory?" << std::endl;
        return 1;
    }    
    
    //read file into vector of chars, gridPattern

    std::string line;
    int i = 0;
    while (std::getline(inputFile, line)) { 
        int k = 0;       
        for(int j = 0; j < line.size(); j += 2) {
            gridPattern.push_back(line[j]);
            k++;
        }
        i++;
    }

    //store size of grid that was read from the text file based on number of rows (only doing square grids)

    int gridSize = i;


    //declare array of grid elements

    gridElement grid[gridSize][gridSize];
    

    // get a value for the entrance port from the user if no command-line argument provided 

    if (argc < 2) {
        std::cout << "Choose an entrance port (0 thru " << gridSize * 4 - 1 << "): ";
        std::cin >> entrancePort;
    }
    else {
        entrancePort = atoi(argv[1]);
    }

    std::cout << "You chose entrance port: " << entrancePort << std::endl;
 
    
    //setup parameters based on square position (corner square, border square, ports, sides with ports etc.)
    squareParamsSetup(&grid[0][0], gridSize);

    //generate grid pattern (where are mirrors, what orientations, squares with no mirrors) (random eventually?)
    setGridPattern(&grid[0][0], gridPattern, gridSize);
    
    //print grid to screen
    visualize(&grid[0][0], gridSize);
    
    getFirstSquare(&grid[0][0], entrancePort, currentRow, currentCol, gridSize);    
    
    //while output edge of current square is not a port (checks 2 ports, but for squares with only one port, it checks the same port twice)
    //Calculate exit port
    //square[currentRow][currentCol].inputPresent = 1;
    grid[currentRow][currentCol].getOutputEdge();
    while (grid[currentRow][currentCol].outputEdge != grid[currentRow][currentCol].sidesWithPorts[0] && grid[currentRow][currentCol].outputEdge != grid[currentRow][currentCol].sidesWithPorts[1]) {
        
        //function for finding next square based on pos of current square and output edge
        getNextSquare(&grid[0][0], currentRow, currentCol, nextRow, nextCol, gridSize);
        
        
        //square[nextRow][nextCol].inputPresent = 1;
        grid[nextRow][nextCol].getOutputEdge();
        currentRow = nextRow;
        currentCol = nextCol;
        
    }
    
    //if output edge matches sideWithPort 0 or 1, set exit port to that 
    //square's port 0 or port 1 and visualize(print grid port to screen)
    if (grid[currentRow][currentCol].outputEdge == grid[currentRow][currentCol].sidesWithPorts[0]) {
        exitPort = grid[currentRow][currentCol].ports[0];
    }
    else {
        exitPort = grid[currentRow][currentCol].ports[1];
    }   
    
    //Print exit port to screen
    std::cout << "Your exit port is: " << exitPort << std::endl;    

    return 0;
}