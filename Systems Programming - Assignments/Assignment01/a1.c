#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ROW       15
#define MAX_COL       60
#define MAX_BIRDS    128
#define BIRD_FREQ     90

#define C_TRUE         1
#define C_FALSE        0

void initHollow(char[MAX_ROW][MAX_COL]);  ///
void printHollow(char[MAX_ROW][MAX_COL]); ///
char escapeOver(char, char, int, int);    ///
char isDone(char, int);                   ///
int  moveHero(char, int, char[MAX_ROW][MAX_COL]);
void moveBird(int, int[MAX_BIRDS], int[MAX_BIRDS], char[MAX_ROW][MAX_COL]);
void moveInHollow(char, int, int, int, int, char[MAX_ROW][MAX_COL]);    ///
void printResult(char, char, int, int); ///
int  randomInt(int); ///


/*
  Function:  main
  Purpose:   runs the program
  Parameters:
    in:      n/a
    return:  n/a
*/
int main() {
    char hollow[MAX_ROW][MAX_COL];
    int birdRows[MAX_BIRDS];
    int birdCols[MAX_BIRDS];
    char tAvatar = 'T';
    char hAvatar = 'H';
    int tCol = 0;
    int hCol = 0;

    srand((unsigned)time(NULL)); // Seed the random number generator

    initHollow(hollow); // Initialize the Dragon's Hollow


    // // Initialize bird positions (for example, all birds start at row 0)
    for (int i = 0; i < MAX_BIRDS; ++i) {
        birdRows[i] = 0;

        birdCols[i] = randomInt(MAX_COL);
    }

    int counter = 0;
    int myBirds[MAX_BIRDS];

    
    while (!escapeOver(tAvatar, hAvatar, tCol, hCol)) {

    //   for (int i = 0; i < MAX_BIRDS; ++i) {
    //     birdRows[i] = 0;

    //     birdCols[i] = randomInt(MAX_COL);
    // }

      // Clear the console (Linux/Unix only)
      system("clear");

      // //90% of the time, initialize bird
      int birdAppearance = randomInt(100);
      int randomBird = 0;
      

      if (birdAppearance < BIRD_FREQ) {
        counter++;

        randomBird = randomInt(MAX_BIRDS);

        myBirds[counter-1] = randomBird;        
      }

      if (counter > 0) {
        for (int i; i < counter; i++) {
          moveBird(myBirds[i], birdRows, birdCols, hollow);   ////// good?
        }

      }

      // Move heroes
      tCol = moveHero(tAvatar, tCol, hollow);
      hCol = moveHero(hAvatar, hCol, hollow);

        // // Check for collisions with heroes
        if (birdRows[randomBird] == MAX_ROW - 2) {
          // Bird has reached the ground
          // Check for collisions with Timmy and Harold
          if (birdCols[randomBird] == tCol) {
              // Bird collided with Timmy
              if (tAvatar != '+') {
                  tAvatar = '+'; // Timmy dies
              }
          }
          if (birdCols[randomBird] == hCol) {
              // Bird collided with Harold
              if (hAvatar != '+') {
                  hAvatar = '+'; // Harold dies
              }
          }
        }

      // Print Dragon's Hollow
      printHollow(hollow);

      // Pause execution for a short time to observe the game progress
      usleep(300000); // 300,000 microseconds (0.3 seconds)
    }

    // Print the final outcome
    printResult(tAvatar, hAvatar, tCol, hCol);

    return 0;
}





/*
  Function:  randomInt
  Purpose:   returns a random number in the range [0,max)
  Parameters:
    in:      maximum of range
    return:  randomly generated number
*/

int randomInt(int max)
{
  return(rand() % max);
}



/*
  Function:  initHollow
  Purpose:   initialize a 2D-array
  Parameters:
    in:      empty 2D array (output)
    return:  n/a
*/
void initHollow(char hollow[MAX_ROW][MAX_COL]) {

  for (int i = 0; i < MAX_ROW; i++) {
    for (int j = 0; j < MAX_COL; j++) {


      // only initialize empty spaces
      hollow[i][j] = ' ';

    }
  }

}


/*
  Function:  printHollow
  Purpose:   prints hollow onto console
  Parameters:
    in:      hollow (2d-array) (input)
    return:  n/a
*/
void printHollow(char hollow [MAX_ROW][MAX_COL]) {

  for (int i = 0; i < MAX_ROW; ++i) {
    for (int j = 0; j < MAX_COL; ++j) {

      // specific printing the horizontal borders (-)
      if ((i == 0) || (i == MAX_ROW - 1)) {
        hollow[i][j] = '-';
      }

      // specific printing the vertical borders (|)
      if (((j == 0) && (i != 0)  && (i != MAX_ROW - 2) && (i != MAX_ROW - 1))  || ((j == MAX_COL - 1) && (i != 0) && (i != MAX_ROW - 2) && (i != MAX_ROW - 1))) {
        hollow[i][j] = '|';

      }

      // printing out the out-zones (=)
      if (((j == 0) && (i == MAX_ROW - 2)) || ((j == MAX_COL - 1) && (i == MAX_ROW - 2))) {
        hollow[i][j] = '=';
      }

      //printing out the grid
      printf("%c", hollow[i][j]);

    }

    printf("\n");
  }

}


/*
  Function:  moveInHollow
  Purpose:   moves a character inside Hollow (T, H, v)
  Parameters:
    in:      character (input), old position (row, col) (input), new position (row, col) (output), hollow (input)
    return:  n/a
*/
void moveInHollow(char TorH, int oldRow, int oldCol, int newRow, int newCol, char hollow[MAX_ROW][MAX_COL]) {
  hollow[oldRow][oldCol] = ' ';

  if (TorH == 'T') {  //case for T
  
    hollow[newRow][newCol] = 'T';   //move to new position (Timmy)
  }
  else if (TorH == 'H'){  //case for H
    hollow[newRow][newCol] = 'H';
  }
  else {  // case for v
    hollow[newRow][newCol] = 'v';
  }

}


/*
  Function:  isDone
  Purpose:   checks if the avatar is out of hollow or dead
  Parameters:
    in:      character (input) and its position (col) (input)
    return:  n/a
*/
char isDone(char avatar, int col) {
  // Check if the hero is dead or has escaped
  if (avatar == 'T' || avatar == 'H') {
      // If hero's avatar is 'T' (Timmy) or 'H' (Harold)
      if (col >= MAX_COL - 1) {
          return C_TRUE;
      } else {
          // the hero is still alive and inside the hollow
          return C_FALSE;
      }
  } 
  else {
      // If the hero's avatar is not 'T' or 'H', it means the hero is dead
      return C_TRUE;
    }
}

/*
  Function:  escapeOver
  Purpose:   uses isDone function to check if isDone for both
  Parameters:
    in:      both characters (input) and their positions (input)
    return:  n/a
*/
char escapeOver(char tAvatar, char hAvatar, int tCol, int hCol) {


     // Check if both heroes have escaped or both died (or any of the combination: (dead = 1 AND escaped = 1))
    if ((isDone(tAvatar, tCol) && isDone(hAvatar, hCol))) {
        return C_TRUE;
    }
    // if either or both heroes are still alive
    else {
        return C_FALSE;
    }
}

/*
  Function:  printResult
  Purpose:   print the result of the hollow
  Parameters:
    in:      the characters and their positions (input and input)
    return:  n/a
*/
void printResult(char tAvatar, char hAvatar, int tCol, int hCol) {

  if (isDone(tAvatar, tCol) && isDone(hAvatar, hCol)) {

    if ((tCol >= MAX_COL-1) && (hCol >= MAX_COL-1)) {
      printf("Both heroes have escaped!");
    }

    if ((tCol < MAX_COL) && (hCol < MAX_COL)) {
      printf("Both heroes are dead!");
    }

    if ((tCol >= MAX_COL-1) && (hCol < MAX_COL-1)) {
      printf("Timmy escapes, but Harold dies...");
    }

    if ((tCol < MAX_COL-1) && (hCol >= MAX_COL-1)) {
      printf("Harold escapes, but Timmy dies...");
    }

  }


}

/*
  Function:  moveHero
  Purpose:   moves a character (T or H) from old position into a new one (with moveInHollow) inside Hollow
  Parameters:
    in:      character (input), its position (input), and hollow (2d array) (input)
    return:  the new position (col) of the character 
*/
int moveHero(char avatar, int oldPos, char hollow[MAX_ROW][MAX_COL]) {

  if (avatar == 'T') {
    int randomIntT = randomInt(100);

    if (randomIntT <= 50) {    
      // move right by 3 paces
      moveInHollow('T', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos+3, hollow);

      return oldPos+3;
    }
    else if ((randomIntT > 50) && (randomIntT <= 70)) {
      // move left by 2 paces 
      if ((oldPos-3 >= 0)) {
        moveInHollow('T', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos-3, hollow);
        return oldPos-3;
      }
      else {
        moveInHollow('T', MAX_ROW-2, oldPos, MAX_ROW-2, 0, hollow);
        return 0;
      }
    }
    else { // else if ((randomInt > 50) && (randomInt <= 100))
      // move right by 1 pace
      moveInHollow('T', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos+1, hollow);
      return oldPos+1;
    }

    
  }

  else if (avatar == 'H') {

    int randomIntH = randomInt(100);
      /*
      20% - no move
      10% - move 6 to the right 
      10% - move 4 to the left 
      40% - move 4 to the right
      10% - move 2 to the left
      */
     if ((randomIntH <= 20) && (randomInt >= 0)) {

      moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos, hollow);
      return oldPos;

     }

     else if ((randomIntH > 20) && (randomIntH <= 30)) {
      moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos+6, hollow); 
      return oldPos+6;

     }

     else if ((randomIntH > 30) && (randomIntH <= 40)) {

      if ((oldPos-4 >= 0)) {
        moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos-4, hollow);
        return oldPos-4;
      }
      else {
      moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, 0, hollow);
      return 0;
      }

     }

     else if ((randomIntH > 40) && (randomIntH <= 80)) {
      moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos+4, hollow);
      return oldPos+4;

     }

     else { // else if ((randomIntH > 80) && (randomIntH <= 100))

     if ((oldPos-2 >= 0)) {
        moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, oldPos-2, hollow);
        return oldPos-2;
      }
      else {
      moveInHollow('H', MAX_ROW-2, oldPos, MAX_ROW-2, 0, hollow);
      return 0;
      }

     }
  }

  else {
    return 0;
  }

}


/*
  Function:  moveBird
  Purpose:   moves a bird
  Parameters:
    in:      one of the bird's index (input), its position (input), and hollow (input)
    return:  n/a
*/
void moveBird(int index, int rows[MAX_BIRDS], int cols[MAX_BIRDS], char hollow[MAX_ROW][MAX_COL]) {


  // if (rows[index] < MAX_ROW - 1) {
      
    int downMovement = randomInt(2);

    if (downMovement == 1) {
      moveInHollow('v', rows[index], cols[index], randomInt(15), cols[index], hollow);
    }
    else 
    {
      // moveInHollow('v', rows[index], cols[index], rows[index] + 13, cols[index], hollow);
    }
      
      
    int horizontalMovement = randomInt(3);

    if (horizontalMovement == 0) {
      moveInHollow('v', rows[index], cols[index], rows[index], cols[index], hollow);
    }
    else if (horizontalMovement == 1) {

      if ((cols[index] + 1) > MAX_COL) {
        moveInHollow('v', rows[index], cols[index], rows[index], MAX_COL, hollow);
      }
      else {
        moveInHollow('v', rows[index], cols[index], rows[index], cols[index] + 1, hollow);
      }
      
    }
    else {
      if ((cols[index] - 1) <= 0) {
        moveInHollow('v', rows[index], cols[index], rows[index], 1, hollow);
      }
      else {
        moveInHollow('v', rows[index], cols[index], rows[index], cols[index] - 1, hollow);
      }
    }
  // }
}
