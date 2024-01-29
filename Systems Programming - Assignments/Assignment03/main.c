#include <stdio.h>
#include <string.h>

#include "defs.h"


/*
  Function:  main
  Purpose:  Main function of the program. It initializes a book club, loads book data,
            and allows users to interact with the book club by printing a list of books (by author),
            printing top-rated books (by rating), adding new books, and exiting the program.
*/
int main()
{
    BookClubType club;
    int choice = -1;       

    initBookClub(&club, "My Book Club");
    loadBookData(&club);

    while (choice != 0) {

        printMenu(&choice);

        switch (choice) {
            case 1:
              printBooks(&club);
              break;
            case 2:
              printTopRatedBooks(&club);
              break;
            case 3:
              {
                int id, year;
                float rating;
                char title[MAX_STR], firstName[MAX_STR], lastName[MAX_STR];

                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf(" %[^\n]", title);
                printf("Enter author's first name: ");
                scanf(" %[^\n]", firstName);
                printf("Enter author's last name: ");
                scanf(" %[^\n]", lastName);
                printf("Enter publication year: ");
                scanf("%d", &year);
                printf("Enter rating (0 to 5): ");
                scanf("%f", &rating);

                int result = addBookToClub(&club, id, title, firstName, lastName, year, rating);
                if (result == C_OK) {
                    printf("Book added successfully!\n");
                } else {
                    printf("Error: Unable to add the book.\n");
                }
              }
              break;
            case 0:
                printf("Exiting the program. Cleaning up...\n");
                cleanupBookArray(&club.books);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}


/*
  Function:  printMenu
  Purpose:   Prompts the user by printing a menu and updates the value pointed to by `choice`.
  Parameters:
    out: choice - Pointer to the variable where the user's choice will be stored.
*/
void printMenu(int* choice)
{
    int c = -1;
    int numOptions = 3;

    printf("\nMAIN MENU\n");
    printf("  (1) Print all books\n");
    printf("  (2) Print top rated books\n");
    printf("  (3) Add a book\n");
    printf("  (0) Exit\n\n");

    printf("Please enter your selection: ");
    scanf("%d", &c);

    if (c == 0 || (c >= 1 && c <= numOptions)) {
        *choice = c;
    } else {
        printf("Invalid choice. Please try again.\n");
        printMenu(choice);
    }
}


/*
  Function:  initBookClub
  Purpose:   Initializes a book club with the given name and initializes a corresponding array with the specified order.
  Parameters:
    out: club - Pointer to the BookClubType variable to be initialized.
    in:  name - Pointer to the character array containing the name of the book club.
*/
void initBookClub(BookClubType* club, char* name) {          
    strncpy(club->name, name, MAX_STR);
    initBookArray(&(club->books), ORDER_BY_RATING);

}


/*
  Function:  initBookArray
  Purpose:   Initializes an array with size 0 and the given order.
  Parameters:
    out: arr - Pointer to the BookArrayType variable to be initialized.
    in:  order - Specifies the order of the array (ORDER_BY_AUTHOR or ORDER_BY_RATING).
*/
void initBookArray(BookArrayType* arr, OrderType order) {
    arr->size = 0;
    arr->order = order;
}


/*
  Function:  initBook
  Purpose:   Initializes all fields of a BookType with the given parameters.
  Parameters:
    out: b - Pointer to the BookType variable to be initialized.
    in:  id - Book ID.
    in:  t - Pointer to the character array containing the book title.
    in:  af - Pointer to the character array containing the author's first name.
    in:  al - Pointer to the character array containing the author's last name.
    in:  y - Publication year.
    in:  r - Book rating.
*/
void initBook(BookType* b, int id, char* t, char* af, char* al, int y, float r) {
    b->id = id;
    strncpy(b->title, t, MAX_STR);
    snprintf(b->author, sizeof(b->author), "%s, %s", al, af);
    b->year = y;
    b->rating = r;
}


/*
  Function:  addBookToClub
  Purpose:   Allocates memory for a new book, finds a spot to insert it, and adds it to the array.
  Parameters:
    out: club - Pointer to the BookClubType variable where the book will be added.
    in:  id - Book ID.
    in:  t - Pointer to the character array containing the book title.
    in:  af - Pointer to the character array containing the author's first name.
    in:  al - Pointer to the character array containing the author's last name.
    in:  y - Publication year.
    in:  r - Book rating.
  Returns:
    C_OK if the book is added successfully, C_NOK otherwise.
*/
int addBookToClub(BookClubType* club, int id, char* t, char* af, char* al, int y, float r) {
    if (id <= 0 || y <= 0 || r < 0 || r > 5) {
        return C_NOK;
    }

    BookType* newBook = malloc(sizeof(BookType));
    if (newBook == NULL) {
        return C_NOK;
    }

    initBook(newBook, id, t, af, al, y, r);

    int insPt;
    int result = findInsPt(&(club->books), newBook, &insPt);

    if (result != C_OK) {
        free(newBook);
        return result;
    }

    result = addBookToArray(&(club->books), newBook);

    if (result != C_OK) {
        free(newBook);
    }

    return result;
}


/*
  Function:  findInsPt
  Purpose:   Finds the insertion point of a book into the book array. (binary searching)
  Parameters:
    out: arr - Pointer to the BookArrayType variable.
    in:  b - Pointer to the BookType variable representing the book to be inserted.
    out: insPt - Pointer to the variable where the insertion point index will be stored.
  Returns:
    C_OK if the insertion point is found successfully.
*/
int findInsPt(BookArrayType* arr, BookType* b, int* insPt)    
{
    int start = 0;
    int end = arr->size - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr->order == ORDER_BY_AUTHOR) {
            int cmp = strcmp(b->author, arr->elements[mid]->author);

            if (cmp < 0 || (cmp == 0 && strcmp(b->title, arr->elements[mid]->title) < 0)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } 
        else {
            if (b->rating > arr->elements[mid]->rating) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    *insPt = start;
    return C_OK;
}


/*
  Function:  addBookToArray
  Purpose:   Adds a book to an array by using findInsPt.
  Parameters:
    out: arr - Pointer to the BookArrayType variable where the book will be added.
    in:  b - Pointer to the BookType variable representing the book to be added.
  Returns:
    C_OK if the book is added successfully, C_NOK otherwise.
*/
int addBookToArray(BookArrayType* arr, BookType* b)
{
    int insPt;
    int result = findInsPt(arr, b, &insPt);


    if (result == C_OK) {
        for (int i = arr->size; i > insPt; i--) {
            arr->elements[i] = arr->elements[i - 1];
        }

        arr->elements[insPt] = b;
        arr->size++;

        return C_OK;
    } else {
        return C_NOK;
    }
}


/*
  Function:  printBooks
  Purpose:   Prints all the fields of a book.
  Parameters:
    in: b - Pointer to the BookType variable representing the book to be printed.
*/
void printBooks(BookClubType* club)     
{
    if ((&(club->books))->order == ORDER_BY_RATING) {
        (&(club->books))->order = ORDER_BY_AUTHOR;
    }

    sortBooks(&(club->books));
    printf("Book Club: %s\n", club->name);
    printf("All Books:\n");

    for (int i = 0; i < club->books.size; i++) {
        printBook(club->books.elements[i]);
    }
}


/*
  Function:  printTopRatedBooks
  Purpose:   Prints the top-rated books based on the specified ordering.
  Parameters:
    in: club - Pointer to the BookClubType variable containing the book club information.
*/
void printTopRatedBooks(BookClubType* club)     
{

    if ((&(club->books))->order == ORDER_BY_AUTHOR) {
    (&(club->books))->order = ORDER_BY_RATING;
    }

    sortBooks(&(club->books));

    printf("Book Club: %s\n", club->name);
    printf("Top Rated Books:\n");

    int numTopRatedBooks = club->books.size * 0.2;

    if (numTopRatedBooks == 0) {
        numTopRatedBooks = 1;
    }

    for (int i = 0; i < numTopRatedBooks; i++) {
        printBook(club->books.elements[i]);
    }
}



/*
  Function:  printBookArray
  Purpose:   Prints the books in the given array.
  Parameters:
    in: arr - Pointer to the BookArrayType variable containing the books to be printed.
*/
void printBookArray(BookArrayType* arr)
{
    for (int i = 0; i < arr->size; i++) {
        printBook(arr->elements[i]);
    }
}



/*
  Function:  printBook
  Purpose:   Prints all the fields of a book.
  Parameters:
    in: b - Pointer to the BookType variable representing the book to be printed.
*/
void printBook(BookType* b) {
    printf("%d : %-45s : %-30s : %d : %.2f\n", b->id, b->title, b->author, b->year, b->rating);
}


/*
  Function:  cleanupBookArray
  Purpose:   Frees the memory allocated for the book array.
  Parameters:
    out: arr - Pointer to the BookArrayType variable to be cleaned up.
*/
void cleanupBookArray(BookArrayType* arr)
{
    for (int i = 0; i < arr->size; i++) {
        free(arr->elements[i]);
    }
    arr->size = 0;
}


/*
  Function:  sortBooks (self-defined)
  Purpose:   Sorts the books in the given array based on the specified ordering. (bubbleSorting)
  Parameters:
    out: arr - Pointer to the BookArrayType variable containing the books to be sorted.
*/
void sortBooks(BookArrayType* arr) {
    int n = arr->size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareBooks(arr->elements[j], arr->elements[j + 1], arr->order) > 0) {
                BookType* temp = arr->elements[j];
                arr->elements[j] = arr->elements[j + 1];
                arr->elements[j + 1] = temp;
            }
        }
    }
}


/*
  Function:  compareBooks (self-defined)
  Purpose:   Compares two books based on the specified ordering.
  Parameters:
    in: book1 - Pointer to the first BookType variable for comparison.
    in: book2 - Pointer to the second BookType variable for comparison.
    in: order - Specifies the ordering criterion (ORDER_BY_AUTHOR or ORDER_BY_RATING).
  Returns:
    Negative value if book1 < book2, positive value if book1 > book2, and 0 if they are equal.
*/
int compareBooks(BookType* book1, BookType* book2, OrderType order) {
    if (order == ORDER_BY_AUTHOR) {
        int cmp = strcmp(book1->author, book2->author);
        if (cmp == 0) {
            return strcmp(book1->title, book2->title);
        }
        return cmp;
    } else {
        if (book1->rating < book2->rating) {
            return 1;
        } else if (book1->rating > book2->rating) {
            return -1;
        }
        return 0;
    }
}