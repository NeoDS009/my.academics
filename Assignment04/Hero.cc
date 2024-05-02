#include "Hero.h"

#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

Hero::Hero(char avatar, int row, int col, string name)
    : Participant(avatar, row, col), name(name), health(20) { }

void Hero::move(Pit* p) {
    if (isDead() || isSafe()) {
        return;
    }

    if (p->underLedge(position)) {
        int newRow = getRow();
        
        int colOffset = (rand() % 2 == 0) ? -1 : 1;
        int newCol = getCol() + colOffset;

        if (p->validPos(newRow, newCol)) {
            position->set(newRow, newCol);
        }
    } else {
        int movementType = rand() % 100;

        if (movementType < 50) {
            int newRow = getRow() - 1;
            int newCol = getCol(); 
            if (p->validPos(newRow, newCol)) {
                position->set(newRow, newCol);
            }
        } else if (movementType < 60) {
            int newRow = getRow() - 2;
            int newCol = getCol();
            if (p->validPos(newRow, newCol)) {
                position->set(newRow, newCol);
            }
        } else { 
            int newRow = getRow() + 1; 
            int newCol = getCol(); 
            if (p->validPos(newRow, newCol)) {
                position->set(newRow, newCol);
            }
        }
    }
}

void Hero::incurDamage(Participant* p) {
    int damage = p->causeDamage();

    health -= damage;

    if (health <= 0) {
        dead = true;
        avatar = '+';
    }
}

int Hero::causeDamage() {
    return 0;
}

std::string Hero::getName() const {
    return name;
}

int Hero::getHealth() const {
    return health;
}

bool Hero::collide(Participant* p)
{
    return false;
}
