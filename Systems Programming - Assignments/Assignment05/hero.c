#include "defs.h"

/*
  Function name: initHero
  Purpose: Dynamically allocates and initializes one hero.
  Parameters:
    in: char avatar - Avatar of the hero.
        int col - Initial column position of the hero.
        char* name - Name of the hero.
    out: HeroType** hero - Pointer to the pointer that will store the address of the allocated hero.
    in/out: None
    return: None
*/
void initHero(HeroType** hero, char avatar, int col, char* name) {
    *hero = malloc(sizeof(HeroType));
    (*hero)->partInfo.avatar = avatar;
    (*hero)->partInfo.pos.row = MAX_ROW - 1;
    (*hero)->partInfo.pos.col = col;
    strcpy((*hero)->name, name);
    (*hero)->health = MAX_HEALTH;
    (*hero)->dead = C_FALSE;
}

/*
  Function name: addHero
  Purpose: Adds hero to escape's hero collection.
  Parameters:
    in: HeroArrayType* heroes - Array of heroes.
        HeroType* hero - Hero to be added.
    out: None
    in/out: None
    return: None
*/
void addHero(HeroArrayType* heroes, HeroType* hero) {
    heroes->elements[heroes->size++] = hero;
}

/*
  Function name: moveHero
  Purpose: Computes hero's next move in accordance with the instruction 3.4, and updates hero's position.
  Parameters:
    in: HeroType* hero - Hero to be moved.
        EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: None
*/
void moveHero(HeroType* hero, EscapeType* escape) {
    if (!hero->dead && !heroIsSafe(hero)) {

        int moveType = randomInt(100);

        if (moveType < 50) {
            hero->partInfo.pos.col += 2;
        } else if (moveType < 80) {
            hero->partInfo.pos.col -= 1;
        } else {
            hero->partInfo.pos.col += 1;
        }

        if (hero->partInfo.pos.col < 0) {
            hero->partInfo.pos.col = 0;
        } else if (hero->partInfo.pos.col >= MAX_COL) {
            hero->partInfo.pos.col = MAX_COL - 1;
        }

        if (hero->partInfo.pos.col >= MAX_COL - 1) {
            hero->partInfo.pos.col = MAX_COL - 1;
            hero->dead = C_TRUE;
        }
    }
}

/*
  Function name: heroIsSafe
  Purpose: Determines if a hero has successfully escaped the Hollow.
  Parameters:
    in: HeroType* hero - Hero to be checked.
    out: None
    in/out: None
    return: int - Returns 1 if the hero is safe, 0 otherwise.
*/
int heroIsSafe(HeroType* hero) {
    return hero->partInfo.pos.col >= MAX_COL - 1;
}

/*
  Function name: incurDamage
  Purpose: Decreases hero's health by flyer's strength. If health gets negative, reset to 0. If hero dies, its avatar is changed.
  Parameters:
    in: HeroType* hero - Hero to incur damage.
        FlyerType* flyer - Flyer causing the damage.
    out: None
    in/out: None
    return: None
*/
void incurDamage(HeroType* hero, FlyerType* flyer) {
    hero->health -= flyer->strength;
    
    if (hero->health < 0) {
        hero->health = 0;
    }

    if (hero->health == 0) {
        hero->partInfo.avatar = '+';
        hero->dead = C_TRUE;
    }
}
