#ifndef PIT_H
#define PIT_H

#include <string>
using namespace std;

#include "defs.h"
#include "Position.h"
#include "PartArray.h"
#include "Hero.h"
#include "Participant.h"

class Hero;

class Pit
{
public:
    /*
      Function: Pit (constructor)
      Purpose: Initializes an instance of the Pit class with the specified layout
      Parameters:
        in: 2D array representing the layout of the pit
    */
    Pit(const char layout[MAX_ROW + 1][MAX_COL + 1]);

    /*
      Function: validPos
      Purpose: Checks if a position within the pit is valid
      Parameters:
        in: Integer representing the row position
        in: Integer representing the column position
      Return: Boolean indicating if the position is valid
    */
    bool validPos(int row, int col);

    /*
      Function: withinBounds
      Purpose: Checks if a position is within the bounds of the pit
      Parameters:
        in: Integer representing the row position
        in: Integer representing the column position
      Return: Boolean indicating if the position is within bounds
    */
    bool withinBounds(int row, int col);

    /*
      Function: underLedge
      Purpose: Checks if a position is underneath a ledge
      Parameters:
        in: Pointer to the Position object representing the position to check
      Return: Boolean indicating if the position is underneath a ledge
    */
    bool underLedge(Position* p);

    /*
      Function: print
      Purpose: Prints the layout of the pit along with the participants (heroes and snorcs)
      Parameters:
        in: Pointer to the PartArray object containing the participants
        in: Pointer to the first Hero object
        in: Pointer to the second Hero object
    */
    void print(PartArray* part, Hero* h1, Hero* h2);

private:
    char layout[MAX_ROW + 1][MAX_COL + 1];
};

#endif 
