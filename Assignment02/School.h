#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
using namespace std;

#include "Course.h"
#include "CourseArray.h"

/**
 * Class: School
 * Purpose: Represents a school and manages the collection of courses.
 */
class School
{
  public:
    /**
     * Constructor:
     * Purpose: Initializes a School object with a default name.
     * Parameters:
     *   in: name - The name of the school.
     */
    School(string = "Carleton U. School of Computer Science");

    /**
     * Destructor:
     * Purpose: Cleans up resources associated with the School object.
     */
    ~School();

    /**
     * Function: addCourse
     * Purpose: Adds a course to the school's course collection.
     * Parameters:
     *   in: course - Pointer to the Course object to be added.
     */
    void addCourse(Course*);

    /**
     * Function: findCourse
     * Purpose: Finds a course in the school's course collection.
     * Parameters:
     *   in: id - The ID of the course to find.
     *   out: course - Pointer to the found Course object.
     * Return:
     *   true if the course is found, false otherwise.
     */
    bool findCourse(int id, Course**);

    /**
     * Function: printCourses
     * Purpose: Prints the courses in the school's collection.
     * Parameters:
     *   in: header - Additional header information to print.
     */
    void printCourses(string);

  private:
    string name;
    CourseArray courseCollection;
};

#endif
