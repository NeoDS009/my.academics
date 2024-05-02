#include "Position.h"

Position::Position(int row, int col) : row(row), col(col) { }

void Position::set(int row, int col)
{
    if (row < 0) {
        row = 0;
    } else if (row >= MAX_ROW) {
        row = MAX_ROW - 1;
    }

    if (col < 0) {
        col = 0;
    } else if (col >= MAX_COL) { 
        col = MAX_COL - 1;
    }

    this->row = row;
    this->col = col;
}

bool Position::equals(Position* p) const
{
    return (this->row == p->getRow() && this->col == p->getCol());
}

int Position::getRow() const
{
    return row;
}

int Position::getCol() const
{
    return col;
}
