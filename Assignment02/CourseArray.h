#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "Course.h"

/**
 * Class: CourseArray
 * Purpose: Represents an array of courses with functionalities for addition, printing, and finding.
 */
class CourseArray
{
public:
    /**
     * Function: CourseArray
     * Purpose: Constructor for the CourseArray class.
     * Parameters: None
     * Return: None
     */
    CourseArray();

    /**
     * Function: ~CourseArray
     * Purpose: Destructor for the CourseArray class.
     * Parameters: None
     * Return: None
     */
    ~CourseArray();

    /**
     * Function: add
     * Purpose: Adds a course to the array.
     * Parameters:
     *   in: course - The Course pointer to be added.
     * Return: None
     */
    void add(Course* course);

    /**
     * Function: print
     * Purpose: Prints information about courses in the array.
     * Parameters:
     *   in: header - The header information to be printed.
     * Return: None
     */
    void print(string header);

    /**
     * Function: find
     * Purpose: Finds a course in the array based on its ID.
     * Parameters:
     *   in: id - The ID of the course to find.
     *   out: foundCourse - A pointer to the found Course.
     * Return:
     *   True if the course is found, false otherwise.
     */
    bool find(int id, Course** foundCourse);

private:
    Course* elements[MAX_ARR];
    int size; 

    int nextId;
    
    /**
     * Function: shiftElements
     * Purpose: Shifts elements in the array to accommodate a new course.
     * Parameters:
     *   in: startIndex - The index from which shifting should begin.
     * Return: None
     */
    void shiftElements(int startIndex);
};

#endif
