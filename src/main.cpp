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
//user-defined grid size
//replace vectors with arrays (not sure why i used vectors initially)
//find out if statement on line 10 of squareParamSetup.cpp is useful
//rename 'square' symbol to something like 'fiveSqrd'. Necessary?

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
    //input gridPattern from text file gridPattern.txt
    std::ifstream inputFile("../gridPattern.txt");
    if (!inputFile) {
        std::cerr << "Unable to open the grid pattern text file. Is it in the parent directory?" << std::endl;
        return 1;
    }
    char gridPattern[5][5];
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

    //declare array of squares
    gridElement square[5][5];
    int entrancePort{0};
    int exitPort;
    int currentRow{0}, currentCol{0}, nextRow{0}, nextCol{0};
    //bool mirrorPattern[5][5] = {
    //    0, 0, 1, 0, 1,
    //    1, 1, 0, 0, 1,
    //    0, 0, 1, 0, 0,
    //    1, 1, 0, 1, 0,
    //    0, 1, 1, 0, 0
    //};
    //bool mirrorOrientationPattern[5][5] = {
    //    0, 0, 1, 0, 0,
    //    1, 1, 0, 0, 1,
    //    0, 0, 0, 0, 0,
    //    1, 0, 0, 1, 0,
    //    0, 1, 1, 0, 0
    //};
    //trying to simplify by using a grid of chars that are either /, 0, or \;  or  maybe use a space instead of zero
    //int gridPattern[5][5] = {
    //    0, 0, 2, 0, 1,
    //    2, 2, 0, 0, 2,
    //    0, 0, 1, 0, 0,
    //    2, 1, 0, 2, 0,
    //    0, 2, 2, 0, 0
    //};
    //char gridPattern2[5][5] = {
    //    '0', '0', '/', '0', '\\',
    //    '/', '/', '0', '0',  '/',
    //    '0', '0','\\', '0',  '0',
    //    '/','\\', '0', '/',  '0',
    //    '0', '/', '/', '0',  '0'
    //};
    
    //function to print grid with all zeroes
    //printZeroGrid();
    
    // get a value for the entrance port from the user if no command-line argument provided 
    if (argc < 2) {
        std::cout << "Choose an entrance port (0 thru 19): ";
        std::cin >> entrancePort;
    }
    else {
        entrancePort = atoi(argv[1]);
    }

    std::cout << "You chose entrance port: " << entrancePort << std::endl;

    //take input arg from command line if desired
    //if (argv[1]) {
    //    //entrancePoint = static_cast<int>argv[1];
    //    std::cout << "You chose entrance port: " << std::stoi(argv[1]) << std::endl;
    //}
    //else {
    //    std::cout << "You did not choose an entrance point.  Using default entrance point: " << entrancePort << std::endl;
    //}   
    
    //setup parameters based on square position (corner square, border square, ports, sides with ports etc.)
    squareParamsSetup(square);

    //generate grid pattern (where are mirrors, what orientations, squares with no mirrors) (random eventually?)
    setGridPattern(square, gridPattern);
    
    //print grid to screen
    visualize(square);
    
    getFirstSquare(square, entrancePort, currentRow, currentCol);    
    
    //while output edge of current square is not a port (checks 2 ports, but for squares with only one port, it checks the same port twice)
    //Calculate exit port
    //square[currentRow][currentCol].inputPresent = 1;
    square[currentRow][currentCol].getOutputEdge();
    while (square[currentRow][currentCol].outputEdge != square[currentRow][currentCol].sidesWithPorts[0] && square[currentRow][currentCol].outputEdge != square[currentRow][currentCol].sidesWithPorts[1]) {
        
        //function for finding next square based on pos of current square and output edge
        getNextSquare(square, currentRow, currentCol, nextRow, nextCol);
        
        
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