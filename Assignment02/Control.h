#ifndef CONTROL_H
#define CONTROL_H

#include <string>
using namespace std;

#include "Schedule.h"
#include "School.h"
#include "View.h"
#include "Course.h"

/**
 * Class: Control
 * Purpose: Controls the main functionality of the program, managing schedules and courses.
 */
class Control
{
public:
    /**
     * Function: Control
     * Purpose: Constructor for the Control class.
     * Parameters: None
     * Return: None
     */
    Control();

    /**
     * Function: ~Control
     * Purpose: Destructor for the Control class.
     * Parameters: None
     * Return: None
     */
    ~Control();

    /**
     * Function: launch
     * Purpose: Launches the main functionality of the program.
     * Parameters: None
     * Return: None
     */
    void launch();

private:
    int numScheds;
    School* school; 
    Schedule** schedules; 

    /**
     * Function: initCourses
     * Purpose: Initializes courses in the School.
     * Parameters:
     *   in: school - A pointer to the School object.
     * Return: None
     */
    void initCourses(School* school);

    /**
     * Function: addSched
     * Purpose: Adds a schedule to the array of schedules.
     * Parameters:
     *   in: schedule - A pointer to the Schedule object to be added.
     * Return:
     *   True if the schedule is added successfully, false otherwise.
     */
    bool addSched(Schedule* schedule);

    /**
     * Function: findSched
     * Purpose: Finds a schedule in the array of schedules based on the term.
     * Parameters:
     *   in: term - The term to search for.
     *   out: schedule - A pointer to the Schedule object found.
     * Return:
     *   True if the schedule is found, false otherwise.
     */
    bool findSched(string term, Schedule** schedule);
};

#endif
