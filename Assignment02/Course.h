#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

#include "defs.h"
#include "Time.h"

/**
 * Class: Course
 * Purpose: Represents a course with various attributes and functionalities.
 */
class Course
{
public:
    /**
     * Function: Course
     * Purpose: Constructor for the Course class.
     * Parameters:
     *   in: subject - The subject of the course.
     *   in: term - The term in which the course is offered.
     *   in: code - The code of the course.
     *   in: section - The section of the course.
     *   in: instructor - The instructor of the course.
     *   in: days - The days on which the lectures are scheduled.
     *   in: startTime - The start time of the lectures.
     *   in: duration - The duration of each lecture.
     * Return: None
     */
    Course(string subject = " ", string term = " ", int code = 0, char section = ' ', string instructor = " ", LectDaysType days = BAD_LECT_DAYS, int startTime = 0, int duration = 0);

    /**
     * Function: ~Course
     * Purpose: Destructor for the Course class.
     * Parameters: None
     * Return: None
     */
    ~Course();

    /**
     * Function: computeDays
     * Purpose: Computes the two weekdays when the course is offered.
     * Parameters:
     *   out: day1 - The first weekday.
     *   out: day2 - The second weekday.
     * Return:
     *   True if computation is successful, false otherwise.
     */
    bool computeDays(WeekDayType& day1, WeekDayType& day2);

    /**
     * Function: computeSlot
     * Purpose: Computes the time slot when the course is offered.
     * Parameters:
     *   out: slot - The time slot.
     * Return:
     *   True if computation is successful, false otherwise.
     */
    bool computeSlot(TimeSlotType& slot);

    /**
     * Function: lessThan
     * Purpose: Compares two courses based on their start times.
     * Parameters:
     *   in: other - A pointer to the Course to compare with.
     * Return:
     *   True if the current course has an earlier start time, false otherwise.
     */
    bool lessThan(Course* other);

    /**
     * Function: print
     * Purpose: Prints information about the course.
     * Parameters: None
     * Return: None
     */
    void print();

    /**
     * Function: getId
     * Purpose: Gets the ID of the course.
     * Parameters: None
     * Return: The ID of the course.
     */
    int getId() const;

    /**
     * Function: getTerm
     * Purpose: Gets the term of the course.
     * Parameters: None
     * Return: The term of the course.
     */
    string getTerm() const;

    /**
     * Function: getInstructor
     * Purpose: Gets the instructor of the course.
     * Parameters: None
     * Return: The instructor of the course.
     */
    string getInstructor() const;

    /**
     * Function: getCode
     * Purpose: Gets the code of the course.
     * Parameters: None
     * Return: The code of the course.
     */
    string getCode() const;

    /**
     * Function: setId
     * Purpose: Sets the ID of the course.
     * Parameters:
     *   in: id - The ID to set.
     * Return: None
     */
    void setId(int id);

private:
    int id; 
    string term; 
    string subject; 
    int code; 
    char section; 
    string instructor; 
    LectDaysType days;  
    Time* time; 
};

#endif
