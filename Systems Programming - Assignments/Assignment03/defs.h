#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK       0
#define C_NOK     -1

#define MAX_STR   64
#define MAX_CAP  128

typedef enum {ORDER_BY_AUTHOR, ORDER_BY_RATING} OrderType;

typedef struct {
  int   id;
  char  title[MAX_STR];
  char  author[MAX_STR];
  int   year;
  float rating;
} BookType;

typedef struct {
  BookType *elements[MAX_CAP];
  int size;
  OrderType order;
} BookArrayType;

typedef struct {
  char name[MAX_STR];
  BookArrayType books;
} BookClubType;

void printMenu(int*);
void loadBookData(BookClubType*);           

void initBookClub(BookClubType*, char*);

void initBookArray(BookArrayType*, OrderType);
void initBook(BookType*, int, char*, char*, char*, int, float);

int  addBookToClub(BookClubType*, int, char*, char*, char*, int, float);
int  addBookToArray(BookArrayType*, BookType*);
int  findInsPt(BookArrayType*, BookType*, int*);

void printBooks(BookClubType*);
void printTopRatedBooks(BookClubType*);
void printBookArray(BookArrayType*);
void printBook(BookType*);
void cleanupBookArray(BookArrayType*);

void sortBooks(BookArrayType*);
int compareBooks(BookType*, BookType*, OrderType);

#endif /* DEFS_H */
