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
//ALMOST DONE: user-defined grid size 
//      code has been generalized so that you only have to change a single variable, gridSize, in the main declarations
//replace vectors with arrays (not sure why i used vectors initially)
//find out if statement on line 10 of squareParamSetup.cpp is useful
//rename 'square' symbol to something like 'fiveSqrd'. Necessary?
//generalize or remove printZeroGrid.cpp.  Is this function necessary for anything?

/*
Get input port number


Iterate through all squares to find which square contains that port number
Store row, col of that square in a vector
Starting with that square 
    set input present flag to 1
    Get output edge (0 thru 3)
    Is there a square there? If not, print exit port and quit
        If yes, convert output edge of previous square to input edge of next cube (0<->2, 1<->3)
        set input of next square based on current output edge
        determine if current square output edge is an also an exit port
Repeat while output edge does not correspond to an exit port
*/


int main(int argc, char *argv[]) {
    
    //declarations
    const int gridSize{6};
    gridElement square[gridSize][gridSize];
    int entrancePort{0};
    int exitPort;
    int currentRow{0}, currentCol{0}, nextRow{0}, nextCol{0};
    char gridPattern[gridSize][gridSize];
    
    //open gridPattern text file gridPattern.txt
    std::ifstream inputFile("../gridPattern.txt");
    if (!inputFile) {
        std::cerr << "Unable to open the grid pattern text file. Is it in the parent directory?" << std::endl;
        return 1;
    }    
    
    //read file
    std::string line;
    int i = 0;
    while (std::getline(inputFile, line)) { 
        int k = 0;       
        for(int j = 0; j < line.size(); j += 2) {
            gridPattern[i][k] = line[j];
            k++;
        }
        i++;
    }

    
    
    // get a value for the entrance port from the user if no command-line argument provided 
    if (argc < 2) {
        std::cout << "Choose an entrance port (0 thru 19): ";
        std::cin >> entrancePort;
    }
    else {
        entrancePort = atoi(argv[1]);
    }

    std::cout << "You chose entrance port: " << entrancePort << std::endl;
 
    
    //setup parameters based on square position (corner square, border square, ports, sides with ports etc.)
    squareParamsSetup(&square[0][0], gridSize);

    //generate grid pattern (where are mirrors, what orientations, squares with no mirrors) (random eventually?)
    setGridPattern(&square[0][0], &gridPattern[0][0], gridSize);
    
    //print grid to screen
    visualize(&square[0][0], gridSize);
    
    getFirstSquare(&square[0][0], entrancePort, currentRow, currentCol, gridSize);    
    
    //while output edge of current square is not a port (checks 2 ports, but for squares with only one port, it checks the same port twice)
    //Calculate exit port
    //square[currentRow][currentCol].inputPresent = 1;
    square[currentRow][currentCol].getOutputEdge();
    while (square[currentRow][currentCol].outputEdge != square[currentRow][currentCol].sidesWithPorts[0] && square[currentRow][currentCol].outputEdge != square[currentRow][currentCol].sidesWithPorts[1]) {
        
        //function for finding next square based on pos of current square and output edge
        getNextSquare(&square[0][0], currentRow, currentCol, nextRow, nextCol, gridSize);
        
        
        //square[nextRow][nextCol].inputPresent = 1;
        square[nextRow][nextCol].getOutputEdge();
        currentRow = nextRow;
        currentCol = nextCol;
        
    }
    
    //if output edge matches sideWithPort 0 or 1, set exit port to that 
    //square's port 0 or port 1 and visualize(print grid port to screen)
    if (square[currentRow][currentCol].outputEdge == square[currentRow][currentCol].sidesWithPorts[0]) {
        exitPort = square[currentRow][currentCol].ports[0];
    }
    else {
        exitPort = square[currentRow][currentCol].ports[1];
    }   
    
    //Print exit port to screen
    std::cout << "Your exit port is: " << exitPort << std::endl;    

    return 0;
}