#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include "Position.h"

class Pit;

class Participant {
public:
    /*
      Function: Participant (constructor)
      Purpose: Initializes an instance of the Participant class with the specified avatar and position
      Parameters:
        in: Character representing the avatar
        in: Integer representing the initial row position
        in: Integer representing the initial column position
    */
    Participant(char avatar, int initialRow, int initialCol);

    /*
      Function: ~Participant (destructor)
      Purpose: Destroys the Participant instance and releases allocated memory
    */
    virtual ~Participant();

    /*
      Function: move (pure virtual)
      Purpose: Moves the participant within the pit
      Parameters:
        in: Pointer to the Pit object
    */
    virtual void move(Pit* p) = 0;

    /*
      Function: incurDamage (pure virtual)
      Purpose: Inflicts damage on the participant
      Parameters:
        in: Pointer to the Participant object causing the damage
    */
    virtual void incurDamage(Participant* p) = 0;

    /*
      Function: causeDamage (pure virtual)
      Purpose: Computes the damage caused by the participant
      Return: Integer representing the damage caused
    */
    virtual int causeDamage() = 0;

    /*
      Function: collide (pure virtual)
      Purpose: Handles collision between participants
      Parameters:
        in: Pointer to the Participant object colliding with
      Return: Boolean indicating if a collision occurred
    */
    virtual bool collide(Participant* p) = 0;

    /*
      Function: getAvatar
      Purpose: Retrieves the avatar of the participant
      Return: Character representing the avatar
    */
    char getAvatar() const;

    /*
      Function: getRow
      Purpose: Retrieves the row position of the participant
      Return: Integer representing the row position
    */
    int getRow() const;

    /*
      Function: getCol
      Purpose: Retrieves the column position of the participant
      Return: Integer representing the column position
    */
    int getCol() const;

    /*
      Function: isDead
      Purpose: Checks if the participant is dead
      Return: Boolean indicating if the participant is dead
    */
    bool isDead() const;

    /*
      Function: isSafe
      Purpose: Checks if the participant is safe
      Return: Boolean indicating if the participant is safe
    */
    bool isSafe() const;

protected:
    char avatar;
    bool dead;
    Position* position;

    /*
      Function: initializePosition
      Purpose: Initializes the position of the participant
      Parameters:
        in: Integer representing the initial row position
        in: Integer representing the initial column position
    */
    void initializePosition(int initialRow, int initialCol);
};

#endif
