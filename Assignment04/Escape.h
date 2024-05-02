#ifndef ESCAPE_H
#define ESCAPE_H

#include "Participant.h"
#include "Pit.h"
#include "PartArray.h"
#include "Hero.h"
#include "Snorc.h"

#include <thread>
#include <chrono>

class Escape {
public:
    /*
      Function: Escape (constructor)
      Purpose: Initializes an instance of the Escape class with default values
    */
    Escape();

    /*
      Function: ~Escape (destructor)
      Purpose: Destroys the Escape instance and releases allocated memory
    */
    ~Escape();

    /*
      Function: runEscape
      Purpose: Runs the escape simulation until it's over
    */
    void runEscape();

private:
    int numSnorcs;
    
    PartArray participants;
    Pit* pit;
    Hero* hero1; 
    Hero* hero2;

    /*
      Function: spawnSnorc
      Purpose: Spawns a new snorc in the simulation
    */
    void spawnSnorc();

    /*
      Function: moveParticipants
      Purpose: Moves all participants in the simulation
    */
    void moveParticipants();

    /*
      Function: checkForCollision
      Purpose: Checks for collisions between participants
      Parameters:
        in: Pointer to the participant to check collisions for
      Return: Pointer to the collided participant if found, otherwise nullptr
    */
    Participant* checkForCollision(Participant* p);

    /*
      Function: isOver
      Purpose: Determines if the simulation is over
      Return: True if the simulation is over, otherwise false
    */
    bool isOver();

    /*
      Function: printOutcome
      Purpose: Prints the outcome of the simulation
    */
    void printOutcome();
};

#endif
