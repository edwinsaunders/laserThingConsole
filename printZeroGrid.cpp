//print grid with all zeroes for visualization of ports (hidden mirror configuration)
#include <iostream>

void printZeroGrid() {
    std::cout << "    0  1  2  3  4" << std::endl;

    for (int i = 0; i < 5; i++) //rows
    {
        std::cout << 19 - i << "  ";
        
        for (int j = 0; j < 5; j++) //cols
        {
            std::cout << "0  ";
        }
        std::cout << 5 + i << std::endl;
        //std::cout << std::endl;
    }

    std::cout << "    14 13 12 11 10" << std::endl;
}