#ifndef SNORC_H
#define SNORC_H

#include <string>
#include "Participant.h"
#include "Pit.h"

class Pit;

class Snorc : public Participant {
public:
    /*
      Function: Snorc (constructor)
      Purpose: Initializes an instance of the Snorc class with the specified attributes
      Parameters:
        in: int representing the initial row position of the Snorc
        in: int representing the initial column position of the Snorc
        in: int representing the strength of the Snorc
    */
    Snorc(int initialRow, int initialCol, int strength);

    /*
      Function: move
      Purpose: Moves the Snorc within the Pit
      Parameters:
        in: Pointer to the Pit object representing the environment
    */
    void move(Pit* p);

    /*
      Function: incurDamage
      Purpose: Applies damage to the Snorc based on a collision with another participant
      Parameters:
        in: Pointer to the Participant with which the Snorc collided
    */
    void incurDamage(Participant* p);

    /*
      Function: causeDamage
      Purpose: Retrieves the damage caused by the Snorc
      Return: Integer representing the damage caused by the Snorc
    */
    int causeDamage();

    /*
      Function: collide
      Purpose: Checks if the Snorc has collided with another participant
      Parameters:
        in: Pointer to the Participant to check collision with
      Return: True if collision detected, otherwise false
    */
    bool collide(Participant* p);

private:
    int strength;
};

#endif
