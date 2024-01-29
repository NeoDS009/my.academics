#include "defs.h"

/*
  Function name: spawnFlyer
  Purpose: Dynamically allocates and initializes one flyer, and adds it to escape's flyer collection.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
        char type - Type of flyer.
        int row - Initial row position of the flyer.
        int col - Initial column position of the flyer.
        int strength - Strength of the flyer.
    out: None
    in/out: None
    return: None
*/
void spawnFlyer(EscapeType* escape, char type, int row, int col, int strength) {
    FlyerType* flyer = malloc(sizeof(FlyerType));
    flyer->partInfo.avatar = type;
    flyer->partInfo.pos.row = row;
    flyer->partInfo.pos.col = col;
    flyer->strength = strength;

    addFlyer(&escape->flyers, flyer);
}

/*
  Function name: addFlyer
  Purpose: Adds flyer to escape's flyer collection.
  Parameters:
    in: FlyerArrayType* flyers - Array of flyers.
        FlyerType* flyer - Flyer to be added.
    out: None
    in/out: None
    return: None
*/
void addFlyer(FlyerArrayType* flyers, FlyerType* flyer) {
    flyers->elements[flyers->size++] = flyer;
}

/*
  Function name: moveFlyer
  Purpose: Computes flyer's next move in accordance with instruction 3.4, updates flyer's position, and deals with collisions with heroes.
  Parameters:
    in: FlyerType* flyer - Flyer to be moved.
        EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: None
*/
void moveFlyer(FlyerType* flyer, EscapeType* escape) {
    if (!flyerIsDone(flyer)) {
        int verticalMove, horizontalMove;

        if (flyer->partInfo.avatar == 'v') { 
            verticalMove = 1;
            horizontalMove = randomInt(3) - 1;
        } else if (flyer->partInfo.avatar == '@') { 
            int heroDir;
            computeHeroDir(escape, flyer, &heroDir);

            verticalMove = randomInt(7) - 3;
        
            horizontalMove = (heroDir == DIR_LEFT) ? -randomInt(3) : 
                             (heroDir == DIR_RIGHT) ? randomInt(3) : 0;

        }

        flyer->partInfo.pos.row += verticalMove;
        flyer->partInfo.pos.col += horizontalMove;

        HeroType* collidedHero = checkForCollision(&flyer->partInfo.pos, escape);
        if (collidedHero != NULL) {
            incurDamage(collidedHero, flyer);
        }
    }
}

/*
  Function name: computeHeroDir
  Purpose: Computes direction (-1 for left, +1 for right, 0 for same) of the closest hero that is still alive and participating.
           Direction is returned using the parameter.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
        FlyerType* flyer - Flyer to compute direction for.
    out: int* direction - Pointer to an integer that will store the computed direction.
    in/out: None
    return: None
*/
void computeHeroDir(EscapeType* escape, FlyerType* flyer, int* direction) {
    int minDist = MAX_COL;
    int closestHeroDir = DIR_SAME;

    for (int i = 0; i < escape->heroes.size; ++i) {
        HeroType* hero = escape->heroes.elements[i];        
        if (!hero->dead) {
            int dist = hero->partInfo.pos.col - flyer->partInfo.pos.col;

            if (abs(dist) < minDist) {
                minDist = abs(dist);
                closestHeroDir = (dist > 0) ? DIR_RIGHT : DIR_LEFT;
            }
        }
    }

    if (direction != NULL) {
        *direction = closestHeroDir;
    }
}

/*
  Function name: flyerIsDone
  Purpose: Determines if a flyer has reached the ground.
  Parameters:
    in: FlyerType* flyer - Flyer to be checked.
    out: None
    in/out: None
    return: int - Returns 1 if the flyer is done, 0 otherwise.
*/
int flyerIsDone(FlyerType* flyer) {
    return flyer->partInfo.pos.row >= MAX_ROW;
}

/*
  Function name: checkForCollision
  Purpose: Checks if a flyer with the given position has collided with a hero, and returns that hero as the return value (NULL if no collision).
  Parameters:
    in: PositionType* pos - Position of the flyer.
        EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: HeroType* - Returns the hero involved in the collision, or NULL if no collision.
*/
HeroType* checkForCollision(PositionType* pos, EscapeType* escape) {
    for (int i = 0; i < escape->heroes.size; ++i) {
        HeroType* hero = escape->heroes.elements[i];     
        if (!hero->dead && hero->partInfo.pos.row == pos->row && hero->partInfo.pos.col == pos->col) {
            return hero;
        }
    }
    return NULL;
}
