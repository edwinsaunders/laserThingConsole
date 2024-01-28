//function to set mirror pattern
#include "gridElement.hpp"

void setGridPattern(gridElement (&square)[5][5], char (&gridPattern)[5][5]) {
    for (int i = 0; i < 5; i++) //rows
    {
        for (int j = 0; j < 5; j++) //cols
        {
            square[i][j].mirrorConfig = gridPattern[i][j];
        }
    }
}