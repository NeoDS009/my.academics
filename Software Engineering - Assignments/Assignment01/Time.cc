#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

/*
  Function: Time::Time
  Purpose: Constructor for the Time class. Initializes hours and minutes based on the given parameters.
  Parameters:
    in: int h - hours
    in: int m - minutes
*/
Time::Time(int h, int m)
{
  set(h, m);
}

/*
  Function: Time::set
  Purpose: Sets the hours and minutes of the Time object.
  Parameters:
    in: int h - hours
    in: int m - minutes
*/
void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

/*
  Function: Time::convertToMins
  Purpose: Converts the Time object to total minutes.
  Parameters:
    return: int - total minutes
*/
int Time::convertToMins()
{
  return (hours*60 + minutes);

}

/*
  Function: Time::print
  Purpose: Prints the Time object in the format HH:MM.
*/
void Time::print()
{
  cout<<setfill('0')<<setw(2)<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes;
}

/*
  Function: Time::set
  Purpose: Sets the hours and minutes of the Time object based on another Time object.
  Parameters:
    in: Time& t - reference to another Time object
*/
void Time::set(Time& t)
{
  hours = t.hours;
  minutes = t.minutes;
}

/*
  Function: Time::lessThan
  Purpose: Checks if the current Time object is less than another Time object.
  Parameters:
    in: Time& t - reference to another Time object
    return: bool - true if current Time is less than t, false otherwise
*/
bool Time::lessThan(Time& t)
{
  int thisMins = convertToMins();
  int tMins = t.convertToMins();
  return (thisMins < tMins);
}

/*
  Function: Time::validate
  Purpose: Validates if the given hours and minutes are in the correct range.
  Parameters:
    in: int h - hours 
    in: int m - minutes
    return: bool - true if valid, false otherwise
*/
bool Time::validate(int h, int m)
{
  return (h >= 0 && h < 24 && m >= 0 && m < 60);
}

