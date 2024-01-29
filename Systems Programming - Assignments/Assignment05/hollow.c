#include "defs.h"

/*
  Function name: outputHollow
  Purpose: Top-level function for serializing hollow, printing, and sending it to the client.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
    out: None
    in/out: None
    return: None
*/
void outputHollow(EscapeType* escape) {      
    char hollow[MAX_ROW][MAX_COL];
    initHollow(escape, hollow);

    printf("\033[2J\033[H");

    char serializedHollow[MAX_BUFF];
    serializeHollow(escape, serializedHollow);
    printf("%s", serializedHollow);

    sendData(escape->viewSocket, serializedHollow);
}

/*
  Function name: initHollow
  Purpose: Initializes 2D grid with participant avatars in current positions.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
        char hollow[][MAX_COL] - 2D array to be initialized.
    out: None
    in/out: None
    return: None
*/
void initHollow(EscapeType* escape, char hollow[][MAX_COL]) {     
    for (int i = 0; i < MAX_ROW; ++i) {
        for (int j = 0; j < MAX_COL; ++j) {
            hollow[i][j] = ' ';
        }
    }

    for (int i = 0; i < escape->heroes.size; ++i) {
        HeroType* hero = escape->heroes.elements[i];     

        if (hero->partInfo.pos.row >= 0 && hero->partInfo.pos.row < MAX_ROW &&
                hero->partInfo.pos.col >= 0 && hero->partInfo.pos.col < MAX_COL) {
                hollow[hero->partInfo.pos.row][hero->partInfo.pos.col] = hero->partInfo.avatar;
            }


        // char heroAvatar = (hero->dead) ? '+' : hero->partInfo.avatar;
        // if (hero->partInfo.pos.row >= 0 && hero->partInfo.pos.row < MAX_ROW &&
        //     hero->partInfo.pos.col >= 0 && hero->partInfo.pos.col < MAX_COL) {
        //     hollow[hero->partInfo.pos.row][hero->partInfo.pos.col] = heroAvatar;
        // }
      
        for (int i = 0; i < escape->flyers.size; ++i) {
            FlyerType* flyer = escape->flyers.elements[i];
            if (!flyerIsDone(flyer)) {
                if (flyer->partInfo.pos.row >= 0 && flyer->partInfo.pos.row < MAX_ROW &&
                    flyer->partInfo.pos.col >= 0 && flyer->partInfo.pos.col < MAX_COL) {
                    hollow[flyer->partInfo.pos.row][flyer->partInfo.pos.col] = flyer->partInfo.avatar;
                }
            }
        }
    }
}

/*
  Function name: serializeHollow
  Purpose: Constructs 1D array with formatted Hollow output, containing all avatars in their positions, with borders, spacing, and newlines.
  Parameters:
    in: EscapeType* escape - EscapeType structure containing information about the game state.
    out: char* serializedHollow - Pointer to a character array that will store the serialized hollow.
    in/out: None
    return: None
*/
void serializeHollow(EscapeType* escape, char* serializedHollow) {    
    char temp[MAX_ROW][MAX_COL];  

    initHollow(escape, temp);

    sprintf(serializedHollow, "--------------------------------------------------------------\n");

    for (int i = 0; i < MAX_ROW; ++i) {
        if (i == MAX_ROW - 1) {
          sprintf(serializedHollow + strlen(serializedHollow), "=");
        }
        else {
          sprintf(serializedHollow + strlen(serializedHollow), "|");
        }

        for (int j = 0; j < MAX_COL; ++j) {
            sprintf(serializedHollow + strlen(serializedHollow), "%c", temp[i][j]);
        }

        if (i == MAX_ROW - 1) {
          sprintf(serializedHollow + strlen(serializedHollow), "=\n");
        }
        else {
          sprintf(serializedHollow + strlen(serializedHollow), "|\n");
        }
    }

    sprintf(serializedHollow + strlen(serializedHollow), "--------------------------------------------------------------\n");

    sprintf(serializedHollow + strlen(serializedHollow), "   Timmy : %d lives\n", escape->heroes.elements[0]->health);
    sprintf(serializedHollow + strlen(serializedHollow), "   Harold: %d lives\n", escape->heroes.elements[1]->health);
}

/*
  Function name: setPos
  Purpose: Sets a participant's position to the given row/col, with values reset to the closest edge if outside of range.
  Parameters:
    in: PositionType* pos - Pointer to the position structure to be set.
        int row - Row position.
        int col - Column position.
    out: None
    in/out: None
    return: None
*/
void setPos(PositionType* pos, int row, int col) {
    pos->row = row;
    pos->col = col;
}

/*
  Function name: randomInt
  Purpose: Generates a random integer.
  Parameters: None
    in: None
    out: None
    in/out: None
    return: int - Returns a random integer.
*/
int randomInt(int max) {
  return(rand() % max);
}