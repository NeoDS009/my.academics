#ifndef POSITION_H
#define POSITION_H

#include <string>
using namespace std;

#include "defs.h"

class Position
{
public:
    /*
      Function: Position (constructor)
      Purpose: Initializes an instance of the Position class with the specified row and column values
      Parameters:
        in: Integer representing the row position
        in: Integer representing the column position
    */
    Position(int row = 0, int col = 0);

    /*
      Function: equals
      Purpose: Checks if the current position is equal to another position
      Parameters:
        in: Pointer to the Position object to compare with
      Return: Boolean indicating if the positions are equal
    */
    bool equals(Position*) const;

    /*
      Function: set
      Purpose: Sets the row and column values of the position
      Parameters:
        in: Integer representing the new row position
        in: Integer representing the new column position
    */
    void set(int, int);

    /*
      Function: getRow
      Purpose: Retrieves the row position of the position
      Return: Integer representing the row position
    */
    int getRow() const;

    /*
      Function: getCol
      Purpose: Retrieves the column position of the position
      Return: Integer representing the column position
    */
    int getCol() const;

private:
    int row;
    int col;
};

#endif
