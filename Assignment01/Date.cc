#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

/*
  Function: Date::Date
  Purpose: Constructor for the Date class. Initializes day, month, and year based on the given parameters.
  Parameters:
    in: int d - day 
    in: int m - month 
    in: int y - year 
*/
Date::Date(int d, int m, int y)
{
  set(d, m, y);
}

/*
  Function: Date::set
  Purpose: Sets the day, month, and year of the Date object.
  Parameters:
    in: int d - day 
    in: int m - month 
    in: int y - year 
*/
void Date::set(int d, int m, int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth(m, y) ) ? d : 0 );
}

/*
  Function: Date::print
  Purpose: Prints the Date object in the format YYYY-MM-DD.
*/
void Date::print()
{
  cout << right << setfill('0') << setw(4) << year << "-"
       << setw(2) << month << "-"
       << setw(2) << day;
}

/*
  Function: Date::lastDayInMonth
  Purpose: Returns the last day of the month for a given year and month.
  Parameters:
    in: int m - month
    in: int y - year
    return: int - last day of the month
*/
int Date::lastDayInMonth(int m, int y)
{ 
  switch(m)
  {
    case 2:
      if (leapYear(y))
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30; 
  }
}

/*
  Function: Date::leapYear
  Purpose: Checks if a given year is a leap year.
  Parameters:
    in: int y - year
    return: bool - true if leap year, false otherwise
*/
bool Date::leapYear(int y)
{ 
  if ( y%400 == 0 || (y%4 == 0 && y%100 != 0) ) {
    return true;
  }
  else {
    return false; 
  }
}   
  
/*
  Function: Date::getMonthStr
  Purpose: Returns the name of the month for a given month number.
  Parameters:
    in: int m - month
    return: string - month name
*/
string Date::getMonthStr(int m)
{
  string monthStrings[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( m >= 1 && m <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
} 

/*
  Function: Date::set
  Purpose: Sets the day, month, and year of the Date object based on another Date object.
  Parameters:
    in: Date& d - reference to another Date object
*/
void Date::set(Date& d)
{
  day = d.day;
  month = d.month;
  year = d.year;
}

/*
  Function: Date::equals
  Purpose: Checks if the current Date object is equal to another Date object.
  Parameters:
    in: Date& d - reference to another Date object
    return: bool - true if equal, false otherwise
*/
bool Date::equals(Date& d)
{
  return (day == d.day && month == d.month && year == d.year);
}

/*
  Function: Date::lessThan
  Purpose: Checks if the current Date object is less than another Date object.
  Parameters:
    in: Date& d - reference to another Date object
    return: bool - true if current Date is less than d, false otherwise
*/
bool Date::lessThan(Date& d)
{
  if (year < d.year) {
    return true;
  }
  else if (year == d.year && month < d.month) {
    return true;
  }
  else if (year == d.year && month == d.month && day < d.day) {
    return true;
  }
  return false;
}

/*
  Function: Date::validate
  Purpose: Validates if the given day, month, and year are in the correct range.
  Parameters:
    in: int d - day 
    in: int m - month 
    in: int y - year 
    return: bool - true if valid, false otherwise
*/
bool Date::validate(int d, int m, int y)
{
  if (y <= 0 || m < 1 || m > 12) {
    return false;
  }
  if (d < 1 || d > lastDayInMonth(m, y)) {
    return false;
  }
  return true;
}