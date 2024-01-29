#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEBUG 0

#define MIN_PORT            60001
#define MAX_PORT            60010

#define MAX_ROW                15
#define MAX_COL                60
#define MAX_HEALTH             20
#define MAX_STR                32
#define MAX_ARR               128
#define MAX_BUFF             2048

#define C_TRUE                  1
#define C_FALSE                 0

#define BIRD_SPAWN_RATE        80
#define MONKEY_SPAWN_RATE      40
#define OUTPUT_INTERVAL    200000

#define DIR_LEFT               -1
#define DIR_SAME                0
#define DIR_RIGHT               1

typedef struct {
  int  row;
  int  col;
} PositionType;

typedef struct {
  char         avatar;
  PositionType pos;
} ParticipantType;

typedef struct {
  ParticipantType partInfo;
  char name[MAX_STR];
  int  health;
  int  dead;
} HeroType;

typedef struct {
  ParticipantType partInfo;
  int strength;
} FlyerType;

typedef struct {
  HeroType **elements;
  int       size;
} HeroArrayType;

typedef struct {
  FlyerType *elements[MAX_ARR];
  int       size;
} FlyerArrayType;

typedef struct {
  HeroArrayType   heroes;
  FlyerArrayType  flyers;
  int             listenSocket;
  int             viewSocket;
} EscapeType;


/* SERVER FUNCTIONS: */

/* top-level function for server process; */
/* initializes the escape, contains game loop, handles escape result, cleans up */
void runEscape();

/* determines if both heroes are dead or have escaped */
int escapeIsOver(EscapeType*);

/* initializes escape, including seeding PRNG, initializing the hero and flyer arrays,
   allocating and initializing both heroes and adding them to the heroes array, 
   initializing sockets and blocking until client connection request is received */
void initEscape(EscapeType*);

/* prints out and sends to client the outcome of the escape */
void handleEscapeResult(EscapeType*);

/* cleans up escape, including deallocating required memory, sending termination
   (quit) message to client, and closing sockets */
void cleanupEscape(EscapeType*);

/* dynamically allocates and initializes one hero */
void initHero(HeroType**, char, int, char*);

/* adds hero to escape's hero collection */
void addHero(HeroArrayType*, HeroType*);

/* computes hero's next move in accordance to instruction 3.4, and updates
   hero's position */
void moveHero(HeroType*, EscapeType*);

/* determines if a hero has successfully escaped the Hollow */
int heroIsSafe(HeroType*);

/* decreases hero's health by flyer's strength (if health gets negative, reset to 0);
   if hero dies, its avatar is changed */
void incurDamage(HeroType*, FlyerType*);

/* dynamically allocates and initializes one flyer, and 
   adds it to escape's flyer collection */
void spawnFlyer(EscapeType*, char, int, int, int);

/* adds flyer to escape's flyer collection */
void addFlyer(FlyerArrayType*, FlyerType*);

/* computes flyer's next move in accordance to instruction 3.4, 
   updates flyer's position, and deals with collisions with heroes */
void moveFlyer(FlyerType*, EscapeType*);

/* computes direction (-1 for left, +1 for right, 0 for same) of closest hero
   that is still alive and participating; direction is returned using parameter  */
void computeHeroDir(EscapeType*, FlyerType*, int*);

/* determines if a flyer has reached the ground */
int  flyerIsDone(FlyerType*);

/* checks if a flyer with the given position has collided with a hero,
   and returns that hero as the return value (NULL if no collision) */
HeroType* checkForCollision(PositionType*, EscapeType*);

/* top-level function for serializing hollow, printing and sending it
   to client */
void outputHollow(EscapeType*);

/* initializes 2D grid with participant avatars in current positions */
void initHollow(EscapeType*, char[][MAX_COL]);

/* constructs 1D array with formatted Hollow output, containing all avatars
   in their positions, with borders, spacing and newlines */
void serializeHollow(EscapeType*, char*);

/* sets a participant's position to given row/col, with values reset
   to closest edge if outside of range */
void setPos(PositionType*, int, int);

/* CLIENT FUNCTION: */
/* top-level function for client process, given server IP address; */
/* sends connection request to server at given IP address, loops and
   waits for data that it prints out, until quit message is received */
void viewEscape(char*);

void setupServerSocket(int*);
void acceptConnection(int, int*);
void setupClientSocket(int*, char*);
int  rcvData(int, char*);
void sendData(int, char*);
int randomInt(int);

#endif
