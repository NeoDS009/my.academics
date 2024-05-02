#ifndef TIME_H
#define TIME_H

#include "defs.h"

/**
 * Class: Time
 * Purpose: Represents a time with hours and minutes.
 */
class Time
{
  public:
    /**
     * Constructor:
     * Purpose: Initializes a Time object with default hours and minutes.
     * Parameters:
     *   in: hours - The hours of the time.
     *   in: minutes - The minutes of the time.
     */
    Time(int=0, int=0);

    /**
     * Function: print
     * Purpose: Prints the time in HH:MM format.
     */
    void print();

    /**
     * Function: computeSlot
     * Purpose: Computes the time slot based on the current time.
     * Parameters:
     *   out: slot - The computed time slot.
     * Return:
     *   true if successful, false otherwise.
     */
    bool computeSlot(TimeSlotType&);

    /**
     * Function: setFromSlot
     * Purpose: Sets the time from a given time slot.
     * Parameters:
     *   in: slot - The time slot to set the time from.
     * Return:
     *   true if successful, false otherwise.
     */
    bool setFromSlot(TimeSlotType);

  private:
    int  hours;
    int  minutes;

    /**
     * Function: set
     * Purpose: Sets the hours and minutes of the time.
     * Parameters:
     *   in: hours - The hours to set.
     *   in: minutes - The minutes to set.
     */
    void set(int, int);

    /**
     * Function: convertToMins
     * Purpose: Converts the time to total minutes.
     * Return:
     *   The total minutes.
     */
    int  convertToMins();
};

#endif
