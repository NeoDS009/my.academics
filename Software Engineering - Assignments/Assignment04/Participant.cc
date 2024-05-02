#include "Participant.h"

Participant::Participant(char avatar, int initialRow, int initialCol)
    : avatar(avatar), dead(false), position(nullptr) {
    initializePosition(initialRow, initialCol);
}

Participant::~Participant() {
    if (position != nullptr) {
        delete position;
        position = nullptr;
    }
}

char Participant::getAvatar() const {
    return avatar;
}

int Participant::getRow() const {
    return position->getRow();
}

int Participant::getCol() const {
    return position->getCol();
}

bool Participant::isDead() const {
    return dead;
}

bool Participant::isSafe() const {
    return (position->getRow() == 1);
}

void Participant::initializePosition(int initialRow, int initialCol) {
    position = new Position(initialRow, initialCol);
}
