#include "Pit.h"

Pit::Pit(const char layout[MAX_ROW + 1][MAX_COL + 1]) {
    for (int i = 0; i <= MAX_ROW; ++i) {
        for (int j = 0; j <= MAX_COL; ++j) {
            this->layout[i][j] = layout[i][j];
        }
    }
}

bool Pit::withinBounds(int row, int col)
{
    return (row < MAX_ROW-1 && col >= 0 && col < MAX_COL-1);
}

bool Pit::validPos(int row, int col)
{
    return withinBounds(row, col) && (layout[row][col] != '-'); 
}

bool Pit::underLedge(Position* p)
{
    int row = p->getRow();
    int col = p->getCol();

    return (layout[row - 1][col] == '-');
}

void Pit::print(PartArray* part, Hero* h1, Hero* h2)
{
    char tempGrid[MAX_ROW][MAX_COL];

    for (int i = 0; i < MAX_ROW; ++i) {
        for (int j = 0; j < MAX_COL; ++j) {
            tempGrid[i][j] = layout[i][j];
        }
    }

    for (int i = 0; i < part->getSize(); ++i) {
        Participant* participant = part->get(i);
        int row = participant->getRow();
        int col = participant->getCol();
        if (row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL) {
            tempGrid[row][col] = participant->getAvatar();
        }
    }

    for (int i = 0; i < MAX_ROW; ++i) {
        for (int j = 0; j < MAX_COL; ++j) {
            cout << tempGrid[i][j];
        }
        cout << endl;
    }

    if (h1 != nullptr) {
        cout << h1->getName() << ": " << h1->getHealth() << endl;
    }
    if (h2 != nullptr) {
        cout << h2->getName() << ": " << h2->getHealth() << endl;
    }
}
