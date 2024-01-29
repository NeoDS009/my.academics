#include <stdio.h>
#include <string.h>

#include "defs.h"


/*
  Function: main
  Purpose: The main function where the program execution begins.
  Parameters:
    in: None
    out: None
    in/out: None
    return: int - exit code (0 for successful execution)
  Description:
    This function serves as the starting and entry point for the program. It intializes the
    restaurant (initRestaurant), loads sample patron and reservation data (loadPatronData, 
    loadResData), and enters a loop to display the menu (printMenu), allowing the user to
    interact with 4 main functionalities like printing patrons (printPatrons), reservations
    (printReservations), reservations by a specific patron (printResByPatron), and will continue
    to prompt the user with the same functionalities, until the user chooses to exit the program.
    Moreover, memory cleanup is performed before the program exits (cleanupRestaurant).
*/
int main() {

  int choice;
  RestaurantType restaurant;
  initRestaurant(&restaurant, "My Restaurant");

  loadPatronData(&restaurant);
  loadResData(&restaurant);

  do {
      printMenu(&choice);
      switch (choice) {
        case 1:
          printPatrons(&restaurant.patrons);
          break;
        case 2:
          printReservations(&restaurant.reservations);
          break;
        case 3: {
          int patronId;
          printf("Enter patron id: ");

          while (scanf("%d", &patronId) != 1) {
            printf("Invalid input. Please enter a valid patron id: ");

            while (getchar() != '\n');
          }

          printResByPatron(&restaurant, patronId);
        }
        break;

        default:
          break;
      }
  } while (choice != 0);

  cleanupRestaurant(&restaurant);

  return 0;
}


/*
  Function: printMenu
  Purpose: Display the main menu options and prompt the user to enter a selection.
  Parameters:
    in: int* choice - pointer to store the user's menu choice
    out: None
    in/out: None
    return: None
*/
void printMenu(int *choice) {
  int c;
  int numOptions = 3;
  int scanfResult;

  do {
    printf("\nMAIN MENU\n");
    printf("  (1) Print patrons\n");
    printf("  (2) Print reservations\n");
    printf("  (3) Print reservations by patron\n");
    printf("  (0) Exit\n\n");

    printf("Please enter your selection: ");

    scanfResult = scanf("%d", &c);

    if (scanfResult != 1 || (c < 0 || c > numOptions)) {
      printf("Invalid input. Please enter a valid option.\n");

      while (getchar() != '\n');

      c = -1;
    }

  } while (c == -1);

  *choice = c;
}


/*
  Function: initPatronArray
  Purpose: Initialize a PatronArrayType structure by allocating memory and setting default values.
  Parameters:
    in: PatronArrayType* arr - pointer to the PatronArrayType structure
    out: None
    in/out: None
    return: None
*/
void initPatronArray(PatronArrayType *arr) {
  arr->elements = malloc(MAX_CAP * sizeof(PatronType));
  arr->size = 0;
  arr->nextId = PATRON_IDS;
}


/*
  Function: addPatron
  Purpose: Add a new patron to the given patron collection with the provided name.
  Parameters:
    in: PatronArrayType* arr - pointer to the patron collection
    in: char* n - name of the new patron
    out: None
    in/out: None
    return: None
*/
void addPatron(PatronArrayType *arr, char *n) {
  arr->elements[arr->size].id = arr->nextId++;
  strcpy(arr->elements[arr->size].name, n);
  arr->size++;
}


/*
  Function: findPatron
  Purpose: Search for a patron with the given ID in the patron collection.
  Parameters:
    in: PatronArrayType* arr - pointer to the patron collection
    in: int id - ID of the patron to find
    out: PatronType** p - pointer to store the found patron
    in/out: None
    return: int - success (C_OK) or failure (C_NOK) flag
*/
int findPatron(PatronArrayType *arr, int id, PatronType **p) {
  for (int i = 0; i < arr->size; i++) {
    if (arr->elements[i].id == id) {
      *p = &arr->elements[i];
      return C_OK;
    }
  }
  return C_NOK;
}


/*
  Function: printPatrons
  Purpose: Print details of every patron in the given patron collection.
  Parameters:
    in: PatronArrayType* arr - pointer to the patron collection
    out: None
    in/out: None
    return: None
*/
void printPatrons(PatronArrayType *arr) {
  printf("\nREGISTERED PATRONS at Deneo's Bistro:\n");
  for (int i = 0; i < arr->size; i++) {
    printf("Patron #%d: %s\n", arr->elements[i].id, arr->elements[i].name);
  }
}


/*
  Function: cleanupPatronArray
  Purpose: Deallocate dynamically allocated memory for the given patron collection.
  Parameters:
    in: PatronArrayType* arr - pointer to the patron collection
    out: None
    in/out: None
    return: None
*/
void cleanupPatronArray(PatronArrayType *arr) {
  free(arr->elements);
  arr->size = 0;
  arr->nextId = PATRON_IDS;
}


/*
  Function: initResvList
  Purpose: Initialize a ResvListType structure by setting default values.
  Parameters:
    in: ResvListType* list - pointer to the ResvListType structure
    out: None
    in/out: None
    return: None
*/
void initResvList(ResvListType *list) {
  list->head = NULL;
  list->nextId = RES_IDS;
}


/*
  Function: initResvTime
  Purpose: Dynamically allocate memory for a ResvTimeType structure and initialize its fields.
  Parameters:
    in: ResvTimeType** rt - pointer to store the new ResvTimeType structure
    in: int yr, int mth, int day, int hr, int min - date and time components
    out: None
    in/out: None
    return: None
*/
void initResvTime(ResvTimeType **rt, int yr, int mth, int day, int hr, int min) {
  *rt = (ResvTimeType *)malloc(sizeof(ResvTimeType));

  (*rt)->year = yr;
  (*rt)->month = mth;
  (*rt)->day = day;
  (*rt)->hours = hr;
  (*rt)->minutes = min;
}


/*
  Function: initResv
  Purpose: Dynamically allocate memory for a ResvType structure and initialize its fields.
  Parameters:
    in: ResvType** r - pointer to store the new ResvType structure
    in: PatronType* p - pointer to the patron associated with the reservation
    in: ResvTimeType* rt - pointer to the reservation time
    out: None
    in/out: None
    return: None
*/
void initResv(ResvType **r, PatronType *p, ResvTimeType *rt) {
  *r = malloc(sizeof(ResvType));
  (*r)->id = 0;
  (*r)->patron = p;
  (*r)->resvTime = rt;
}


/*
  Function: lessThan
  Purpose: Compare two reservation times and determine if the first one is earlier than the second.
  Parameters:
    in: ResvTimeType* r1, ResvTimeType* r2 - pointers to the reservation times to compare
    out: None
    in/out: None
    return: int - constant associated with true (C_TRUE) or false (C_FALSE)
*/
int lessThan(ResvTimeType *r1, ResvTimeType *r2) {
  if (r1->year < r2->year || (r1->year == r2->year && r1->month < r2->month) ||
    (r1->year == r2->year && r1->month == r2->month && r1->day < r2->day) ||
    (r1->year == r2->year && r1->month == r2->month && r1->day == r2->day && r1->hours < r2->hours) ||
    (r1->year == r2->year && r1->month == r2->month && r1->day == r2->day && r1->hours == r2->hours && r1->minutes < r2->minutes)) {
    return C_TRUE;
  } else {
    return C_FALSE;
  }
}


/*
  Function: addResv
  Purpose: Add a reservation to the given reservation list in its correct position based on time.
  Parameters:
    in: ResvListType* list - pointer to the reservation list
    in: ResvType* r - pointer to the reservation to add
    out: None
    in/out: None
    return: None
*/
void addResv(ResvListType *list, ResvType *r) {
  NodeType *newNode = malloc(sizeof(NodeType));
  newNode->data = r;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    NodeType *current = list->head;

    while (current != NULL && lessThan(r->resvTime, current->data->resvTime)) {
      current = current->next;
    }

    if (current == NULL) {
      NodeType *prev = list->head;
      while (prev->next != NULL) {
        prev = prev->next;
      }
      prev->next = newNode;
      newNode->prev = prev;
    } else {
      newNode->next = current;
      newNode->prev = current->prev;

      if (current->prev != NULL) {
        current->prev->next = newNode;
      } else {
        list->head = newNode;
      }

      current->prev = newNode;
    }
  }

  r->id = list->nextId++;

  list->nextId++;
}


/*
  Function: printReservation
  Purpose: Print details of a single reservation with a certain format.
  Parameters:
    in: ResvType* r - pointer to the reservation
    out: None
    in/out: None
    return: None
*/
void printReservation(ResvType *r) {
  printf("%d :: %d-%-2d-%-2d @ %2d:%-2d :: %s\n", r->id, r->resvTime->year, r->resvTime->month, r->resvTime->day, r->resvTime->hours, r->resvTime->minutes, r->patron->name);
}


/*
  Function: printReservations
  Purpose: Print details of every reservation in the given reservation list in both forward and backward directions.
  Parameters:
    in: ResvListType* list - pointer to the reservation list
    out: None
    in/out: None
    return: None
*/
void printReservations(ResvListType *list) {
  printf("\nRESERVATIONS at Deneo's Bistro:\n");
  printf("--- FORWARD direction:\n");
  NodeType *current = list->head;

  while (current != NULL && current->next != NULL) {
    current = current->next;
  }

  while (current != NULL) {
    printReservation(current->data);
    current = current->prev;
  }

  printf("\n--- BACKWARD direction:\n");
  current = list->head;

  while (current != NULL) {
    printReservation(current->data);
    current = current->next;
  }
}


/*
  Function: cleanupResvList
  Purpose: Deallocate dynamically allocated memory for the given reservation list.
  Parameters:
    in: ResvListType* list - pointer to the reservation list
    out: None
    in/out: None
    return: None
*/
void cleanupResvList(ResvListType *list) {
  NodeType *current = list->head;
  NodeType *next;

  while (current != NULL) {
    next = current->next;
    free(current->data->resvTime);
    free(current->data);
    free(current);
    current = next;
  }

  list->head = NULL;
  list->nextId = RES_IDS;
}


/*
  Function: initRestaurant
  Purpose: Initialize a RestaurantType structure with the provided name and call existing functions for initialization.
  Parameters:
    in: RestaurantType* r - pointer to the RestaurantType structure
    in: char* n - name of the restaurant
    out: None
    in/out: None
    return: None
*/
void initRestaurant(RestaurantType *r, char *n) {
  strcpy(r->name, n);
  initResvList(&r->reservations);
  initPatronArray(&r->patrons);
}


/*
  Function: validateResvTime
  Purpose: Check if the provided date and time components represent a valid date and time.
  Parameters:
    in: int yr, int mth, int day, int hr, int min - date and time components
    out: None
    in/out: None
    return: int - success (C_OK) or failure (C_NOK) flag
*/
int validateResvTime(int yr, int mth, int day, int hr, int min) {
  if (yr < 2023 || mth < 1 || mth > 12 || day < 1 || day > 31 || hr < 0 || hr > 23 || min < 0 || min > 59) {
    return C_NOK;
  }

  return C_OK;
}


/*
  Function: createResv
  Purpose: Create a new reservation for the given restaurant with the provided details.
  Parameters:
    in: RestaurantType* r - pointer to the restaurant
    in: int pId - ID of the patron making the reservation
    in: int yr, int mth, int day, int hr, int min - date and time components
    out: None
    in/out: None
    return: None
*/
void createResv(RestaurantType *r, int pId, int yr, int mth, int day, int hr, int min) {

  if (validateResvTime(yr, mth, day, hr, min) != C_OK) {
    printf("ERROR: Date %d-%2d-%-2d or time %2d:%-2d is invalid\n", yr, mth, day, hr, min);
    return;
  }

  PatronType *patron;
  if (findPatron(&r->patrons, pId, &patron) != C_OK) {
    printf("ERROR: Patron id %d was not found\n", pId);
    return;
  }

  ResvTimeType *resvTime;
  initResvTime(&resvTime, yr, mth, day, hr, min);

  ResvType *reservation;
  initResv(&reservation, patron, resvTime);

  addResv(&r->reservations, reservation);
}


/*
  Function: printResByPatron
  Purpose: Print details of every reservation made by the patron with the given ID in reverse order.
  Parameters:
    in: RestaurantType* r - pointer to the restaurant
    in: int id - ID of the patron
    out: None
    in/out: None
    return: None
*/
void printResByPatron(RestaurantType *r, int id) {
    PatronType *patron;
    if (findPatron(&r->patrons, id, &patron) != C_OK) {
        printf("ERROR: Patron id %d was not found\n", id);
        return;
    }

    NodeType *current = r->reservations.head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    printf("\nRESERVATION BY PATRON #%d at Deneo's Bistro:\n", patron->id);
    while (current != NULL) {
        if (current->data->patron == patron) {
            printReservation(current->data);
        }
        current = current->prev;
    }
}


/*
  Function: cleanupRestaurant
  Purpose: Deallocate dynamically allocated memory for the given restaurant structure.
  Parameters:
    in: RestaurantType* r - pointer to the restaurant
    out: None
    in/out: None
    return: None
*/
void cleanupRestaurant(RestaurantType *r) {

  cleanupPatronArray(&r->patrons);
  cleanupResvList(&r->reservations);
}
