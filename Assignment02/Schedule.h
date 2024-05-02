#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

#include "Course.h"
#include "defs.h"

/**
 * Class: Schedule
 * Purpose: Manages course schedules for a specific term.
 */
class Schedule
{
public:
    /**
     * Function: Schedule
     * Purpose: Constructor for the Schedule class.
     * Parameters:
     *   in: term - The term for which the schedule is created.
     * Return: None
     */
    Schedule(string term = " ");

    /**
     * Function: ~Schedule
     * Purpose: Destructor for the Schedule class.
     * Parameters: None
     * Return: None
     */
    ~Schedule();

    /**
     * Function: addCourse
     * Purpose: Adds a course to the schedule.
     * Parameters:
     *   in: course - A pointer to the Course object to be added.
     * Return:
     *   True if the course is added successfully, false otherwise.
     */
    bool addCourse(Course* course);

    /**
     * Function: print
     * Purpose: Prints the schedule.
     * Parameters: None
     * Return: None
     */
    void print();

    /**
     * Function: clear
     * Purpose: Clears the schedule.
     * Parameters: None
     * Return: None
     */
    void clear();

    /**
     * Function: getTerm
     * Purpose: Gets the term for which the schedule is created.
     * Parameters: None
     * Return:
     *   The term of the schedule.
     */
    string getTerm() const;

private:
    string term; 
    Course* scheduleArray[NUM_DAYS][NUM_SLOTS];  

    /**
     * Function: getArrayIndex
     * Purpose: Computes the array index from enumerated type values.
     * Parameters:
     *   in: day - The day of the week.
     *   in: slot - The time slot of the day.
     * Return:
     *   The array index corresponding to the given day and time slot.
     */
    int getArrayIndex(WeekDayType day, TimeSlotType slot);
};

#endif

