#ifndef HERO_H
#define HERO_H

#include <string>
using namespace std;

#include "Participant.h"
#include "Pit.h"

class Pit;

class Hero : public Participant {
public:
    /*
      Function: Hero (constructor)
      Purpose: Initializes an instance of the Hero class with the specified attributes
      Parameters:
        in: char representing the hero's avatar
        in: int representing the hero's initial row position
        in: int representing the hero's initial column position
        in: string representing the hero's name
    */
    Hero(char avatar, int row, int col, string name);

    /*
      Function: move
      Purpose: Moves the hero within the Pit
      Parameters:
        in: Pointer to the Pit object representing the environment
    */
    void move(Pit* p);

    /*
      Function: incurDamage
      Purpose: Applies damage to the hero based on a collision with another participant
      Parameters:
        in: Pointer to the Participant with which the hero collided
    */
    void incurDamage(Participant* p);

    /*
      Function: causeDamage
      Purpose: Retrieves the damage caused by the hero
      Return: Integer representing the damage caused by the hero
    */
    int causeDamage();

    /*
      Function: collide
      Purpose: Checks if the hero has collided with another participant
      Parameters:
        in: Pointer to the Participant to check collision with
      Return: True if collision detected, otherwise false
    */
    bool collide(Participant* p);

    /*
      Function: getName
      Purpose: Retrieves the name of the hero
      Return: String representing the hero's name
    */
    string getName() const;

    /*
      Function: getHealth
      Purpose: Retrieves the health of the hero
      Return: Integer representing the hero's health
    */
    int getHealth() const;

private:
    string name;
    int health;
};

#endif
