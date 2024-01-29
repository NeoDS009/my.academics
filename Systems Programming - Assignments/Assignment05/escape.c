#include "defs.h"

/*
  Function name: runEscape
  Purpose: Top-level function for server process; initializes the escape, contains the game loop, handles escape result, and cleans up.
  Parameters: None
    in: None
    out: None
    in/out: None
    return: None
*/
void runEscape() {   
    EscapeType escape;
    initEscape(&escape);

    int flyerSpawnCounter = 0;  

    while (!escapeIsOver(&escape)) {
        moveHero(escape.heroes.elements[0], &escape);
        moveHero(escape.heroes.elements[1], &escape);

        if (randomInt(100) < BIRD_SPAWN_RATE) {
            spawnFlyer(&escape, 'v', 0, randomInt(MAX_COL), randomInt(3) + 3);  
        }

        if (randomInt(100) < MONKEY_SPAWN_RATE) {
            spawnFlyer(&escape, '@', 0, randomInt(MAX_COL), randomInt(4) + 8);
        }

        for (int i = 0; i < escape.flyers.size; ++i) {
            moveFlyer(escape.flyers.elements[i], &escape);
        }

        flyerSpawnCounter++;

        outputHollow(&escape);

        usleep(OUTPUT_INTERVAL);
    }

    handleEscapeResult(&escape);

    cleanupEscape(&escape);
}

/*
  Function name: escapeIsOver
  Purpose: Determines if both heroes are dead or have escaped.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: int - Returns 1 if the escape is over, 0 otherwise.
*/
int escapeIsOver(EscapeType* escape) {

    int hero0Safe = heroIsSafe(escape->heroes.elements[0]);
    int hero1Safe = heroIsSafe(escape->heroes.elements[1]);

    return (hero0Safe && hero1Safe) || (escape->heroes.elements[0]->dead && escape->heroes.elements[1]->dead);
}

/*
  Function name: initEscape
  Purpose: Initializes escape, including seeding PRNG, initializing the hero and flyer arrays, allocating and initializing both heroes, and adding them to the heroes array, initializing sockets and blocking until a client connection request is received.
  Parameters:
    in: None
    out: EscapeType* escape - EscapeType structure to be initialized.
    in/out: None
    return: None
*/
void initEscape(EscapeType* escape) {
    srand((unsigned)time(NULL));  

    escape->heroes.elements = malloc(MAX_ARR * sizeof(HeroType*));
    escape->heroes.size = 0;
    escape->flyers.size = 0;

    setupServerSocket(&escape->listenSocket);
    acceptConnection(escape->listenSocket, &escape->viewSocket);

    initHero(&escape->heroes.elements[0], 'T', 0, "Timmy");
    addHero(&escape->heroes, escape->heroes.elements[0]);

    initHero(&escape->heroes.elements[1], 'H', 4, "Harold");
    addHero(&escape->heroes, escape->heroes.elements[1]);
}

/*
  Function name: handleEscapeResult
  Purpose: Prints out and sends to the client the outcome of the escape.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: None
*/
void handleEscapeResult(EscapeType* escape) {

    int escapedHero1 = heroIsSafe(escape->heroes.elements[0]);
    int escapedHero2 = heroIsSafe(escape->heroes.elements[1]);

    char serializedHollow[MAX_BUFF];
    serializeHollow(escape, serializedHollow);
    sendData(escape->viewSocket, serializedHollow);

    if (escapedHero1 && escapedHero2) {
        printf("Both heroes have escaped!\n");
        sendData(escape->viewSocket, "Both heroes have escaped!\n");
    } else if (!escapedHero1 && !escapedHero2) {
        printf("Both heroes have died!\n");
        sendData(escape->viewSocket, "Both heroes have died!\n");
    } else {
        int escapedHero = (escapedHero1) ? 0 : 1;
        int diedHero = (escapedHero == 0) ? 1 : 0;

        printf("%s has escaped!\n", escape->heroes.elements[escapedHero]->name);
        printf("%s has died!\n", escape->heroes.elements[diedHero]->name);

        char resultMsg[MAX_BUFF];
        sprintf(resultMsg, "%s has escaped!\n%s has died!\n", 
                escape->heroes.elements[escapedHero]->name,
                escape->heroes.elements[diedHero]->name);

        sendData(escape->viewSocket, resultMsg);
    }
}

/*
  Function name: cleanupEscape
  Purpose: Cleans up escape, including deallocating required memory, sending termination (quit) message to the client, and closing sockets.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: None
*/
void cleanupEscape(EscapeType* escape) {
    close(escape->listenSocket);
    close(escape->viewSocket);

    for (int i = 0; i < escape->heroes.size; ++i) {
        free(escape->heroes.elements[i]);
    }
    free(escape->heroes.elements);

    for (int i = 0; i < escape->flyers.size; ++i) {
        free(escape->flyers.elements[i]);
    }
}
