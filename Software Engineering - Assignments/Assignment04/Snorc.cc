#include "Snorc.h"

Snorc::Snorc(int initialRow, int initialCol, int strength)
    : Participant('s', initialRow, initialCol), strength(strength) {}

void Snorc::move(Pit* p) {
    int rowOffset = rand() % 3 - 1;
    int colOffset = rand() % 3 - 1;

    int newRow = getRow() + rowOffset;
    int newCol = getCol() + colOffset;

    if (newRow < MAX_ROW - 7) {
        newRow = MAX_ROW - 7;
    }

    if (p->withinBounds(newRow, newCol)) {
        position->set(newRow, newCol);
    }
}

void Snorc::incurDamage(Participant* p) {
    // Do nothing
}

int Snorc::causeDamage() {
    return strength;
}

bool Snorc::collide(Participant* p)
{
    return false;
}
