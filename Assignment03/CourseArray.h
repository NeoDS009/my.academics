#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "Course.h"
#include "defs.h"

class CourseArray
{
public:
    /*
      Function: CourseArray (constructor)
      Purpose: Initializes an instance of the CourseArray class with an empty array
    */
    CourseArray();

    /*
      Function: ~CourseArray (destructor)
      Purpose: Destroys the CourseArray instance and releases allocated memory
    */
    ~CourseArray();

    /*
      Function: add
      Purpose: Adds a Course pointer to the CourseArray
      Parameters:
        in: Course pointer to be added
    */
    void add(Course*);

    /*
      Function: print
      Purpose: Displays information about courses in the array based on a specified term
      Parameters:
        in: String representing the academic term
    */
    void print(string) const;

    /*
      Function: print
      Purpose: Displays information about all courses in the array
    */
    void print() const;

    /*
      Function: find
      Purpose: Searches for a course in the array based on the course ID
      Parameters:
        in: Integer representing the course ID to be found
        out: Course pointer if found
      Return: Boolean indicating if the course was found
    */
    bool find(int, Course**) const;

private:
    Course* elements[MAX_ARR]; 
    int size;                  

    /*
      Function: shiftElements
      Purpose: Shifts elements in the array to create space for a new element
      Parameters:
        in: Integer representing the index where shifting starts
    */
    void shiftElements(int);
};

#endif
