#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK            0
#define C_NOK          -1
#define C_TRUE          1
#define C_FALSE         0

#define MAX_STR        64
#define MAX_CAP       128

#define PATRON_IDS   1001
#define RES_IDS      4001

typedef struct {
  int   id;
  char  name[MAX_STR];
} PatronType;

typedef struct {
  int day;
  int month;
  int year;
  int hours;
  int minutes;
} ResvTimeType;

typedef struct {
  int           id;
  PatronType   *patron;
  ResvTimeType *resvTime;
} ResvType;

typedef struct {
  PatronType *elements; 
  int size;          
  int nextId;          
} PatronArrayType;

typedef struct NodeType {
  ResvType *data;              
  struct NodeType *next;     
  struct NodeType *prev;     
} NodeType;

typedef struct {
  NodeType *head;  
  int nextId; 
} ResvListType;

typedef struct {
  char name[MAX_STR];      
  ResvListType reservations;   
  PatronArrayType patrons;  
} RestaurantType;


void printMenu(int*);
void loadPatronData(RestaurantType*);
void loadResData(RestaurantType*);

void initPatronArray(PatronArrayType *arr);
void addPatron(PatronArrayType *arr, char *n);
int findPatron(PatronArrayType *arr, int id, PatronType **p);
void printPatrons(PatronArrayType *arr); 
void cleanupPatronArray(PatronArrayType *arr);

void initResvList(ResvListType *list);
void initResvTime(ResvTimeType **rt, int yr, int mth, int day, int hr, int min);
void initResv(ResvType **r, PatronType *p, ResvTimeType *rt);
int lessThan(ResvTimeType *r1, ResvTimeType *r2);
void addResv(ResvListType *list, ResvType *r);
void printReservation(ResvType *r);
void printReservations(ResvListType *list);
void cleanupResvList(ResvListType *list);

void initRestaurant(RestaurantType *r, char *n); 
int validateResvTime(int yr, int mth, int day, int hr, int min);
void createResv(RestaurantType *r, int pId, int yr, int mth, int day, int hr, int min);
void printResByPatron(RestaurantType *r, int id);
void cleanupRestaurant(RestaurantType *r);
