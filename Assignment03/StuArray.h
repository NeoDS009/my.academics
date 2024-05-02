#ifndef STUARRAY_H
#define STUARRAY_H

#include "defs.h"
#include "Student.h"

#include <string>
using namespace std;

class StuArray
{
public:
    /*
      Function: StuArray (constructor)
      Purpose: Initializes an instance of the StuArray class
    */
    StuArray();

    /*
      Function: ~StuArray (destructor)
      Purpose: Destroys an instance of the StuArray class, freeing memory allocated for students
    */
    ~StuArray();

    /*
      Function: add
      Purpose: Adds a student to the array
      Parameters:
         in: Pointer to the Student object to be added
    */
    void add(Student*);

    /*
      Function: find
      Purpose: Searches for a student by student number
      Parameters:
        in: String representing the student number to search for
        out: Pointer to the Student object (if found)
      Return: Boolean value indicating whether the student was found
    */
    bool find(string, Student**) const;

    /*
      Function: print
      Purpose: Prints information about all students in the array
    */
    void print() const;

private:
    Student* elements[MAX_ARR]; 
    int size; 

    /*
      Function: shiftElements
      Purpose: Shifts the elements in the StuArray to fill any empty spaces after removal of a student
      Parameters:
        in: Integer representing the index from which to shift elements
    */
    void shiftElements(int);
};

#endif
