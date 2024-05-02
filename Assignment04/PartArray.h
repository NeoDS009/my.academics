#ifndef PARTARRAY_H
#define PARTARRAY_H

#include <iostream>
using namespace std;

#include "Participant.h"
#include "defs.h"

class Participant;

class PartArray {
public:
    /*
      Function: PartArray (constructor)
      Purpose: Initializes an instance of the PartArray class with an empty array
    */
    PartArray();

    /*
      Function: ~PartArray (destructor)
      Purpose: Destroys the PartArray instance and releases allocated memory
    */
    ~PartArray();

    /*
      Function: add
      Purpose: Adds a Participant pointer to the PartArray
      Parameters:
        in: Pointer to the Participant to be added
    */
    void add(Participant* p);

    /*
      Function: get
      Purpose: Retrieves the Participant pointer at the specified index
      Parameters:
        in: Integer representing the index of the Participant to retrieve
      Return: Pointer to the Participant at the specified index
    */
    Participant* get(int index);

    /*
      Function: getSize
      Purpose: Retrieves the size of the PartArray
      Return: Integer representing the size of the PartArray
    */
    int getSize();

private:
    Participant* elements[MAX_ARR];
    int size;
};

#endif
