#include <iostream>
using namespace std;

#include "Calendar.h" 

/*
  Function: Calendar::Calendar
  Purpose: Constructor for the Calendar class. Initializes the Calendar with the given user name and default values.
  Parameters:
    in: const string& user - user name associated with the calendar
*/
Calendar::Calendar(const string& user)
{
    userName = user;
    numEvents = 0;
    nextEventId = EVENTS_ID;
}

/*
  Function: Calendar::addEvent
  Purpose: Adds a new event to the calendar.
  Parameters:
    in: const string& n - event name
    in: const string& cat - event category
    in: const string& part - main participant
    in: int yr - event year
    in: int mth - event month
    in: int day - event day
    in: int hrs - event start hours
    in: int mins - event start minutes
    return: bool - true if the event is added successfully, false otherwise
*/
bool Calendar::addEvent(const string& n, const string& cat, const string& part, int yr, int mth, int day, int hrs, int mins)
{

    if (numEvents >= MAX_ARR)
    {
        cout << "ERROR: Calendar is full. Cannot add more events." << endl;
        return false;
    }

    // Create instances of Date and Time
    Date eventDate(day, mth, yr);
    Time eventStartTime(hrs, mins);


    if (!eventDate.validate(day, mth, yr)) {
        cout << "ERROR:  "
        << "date " << yr << ", " << mth << ", " << day
        << " is invalid"
        << endl;
        return false;
    }

    if (!eventStartTime.validate(hrs, mins)) {
        cout << "ERROR:  "
        << "time " << hrs << ", " << mins
        << " is invalid"
        << endl;
        return false;
    }

    Event newEvent(nextEventId++, n, cat, part, yr, mth, day, hrs, mins);

    int insertIndex = findInsertIndex(newEvent);

    moveEventsBackward(insertIndex);

    events[insertIndex].set(newEvent);

    numEvents++;

    return true;
}

/*
  Function: Calendar::addParticipant
  Purpose: Adds a participant to the specified event in the calendar.
  Parameters:
    in: int id - event identifier
    in: const string& n - participant name
    return: bool - true if participant is added successfully, false otherwise
*/
bool Calendar::addParticipant(int id, const string& n)
{
    for (int i = 0; i < numEvents; ++i)
    {
        if (events[i].getId() == id)
        {
            events[i].addParticipant(n);
            return true;
        }
    }

    return false; 
}

/*
  Function: Calendar::print
  Purpose: Prints the entire calendar.
*/
void Calendar::print()
{
    cout << "Calendar for " << userName << ":" << endl;

    for (int i = numEvents - 1; i >= 0; i--)
    {
        events[i].print();
        cout << endl;
    }
}

/*
  Function: Calendar::printByDay
  Purpose: Prints events on a specified day.
  Parameters:
    in: int yr - year
    in: int mth - month
    in: int day - day
*/
void Calendar::printByDay(int yr, int mth, int day)
{
    Date dateInstance(day, mth, yr);     

    if (!dateInstance.validate(day, mth, yr))
    {
        cout << "ERROR: date is invalid" << endl;
        return;
    }

    cout << "Calendar for " << userName << " on ";
    dateInstance.print();
    cout << ":" << endl;

    for (int i = 0; i < numEvents; ++i)
    {
        if (events[i].getDate().equals(dateInstance))
        {
            events[i].print();
            cout << endl;
        }
    }
}

/*
  Function: Calendar::printByCat
  Purpose: Prints events in a specified category.
  Parameters:
    in: const string& cat - category
*/
void Calendar::printByCat(const string& cat)
{
    cout << "Calendar for " << userName << " in category " << cat << ":" << endl;

    for (int i = numEvents - 1; i >= 0; i--)
    {
        if (events[i].getCategory() == cat)
        {
            events[i].print();
            cout << endl;
        }
    }
}

/*
  Function: Calendar::findInsertIndex
  Purpose: Finds the index where a new event should be inserted to maintain chronological order.
  Parameters:
    in: Event& e - reference to the new Event object
    return: int - index where the new event should be inserted
*/
int Calendar::findInsertIndex(Event& e)
{
    int insertIndex = 0;

    while (insertIndex < numEvents && !events[insertIndex].lessThan(e))
    {
        insertIndex++;
    }

    return insertIndex;
}

/*
  Function: Calendar::moveEventsBackward
  Purpose: Moves events in the calendar backward from the specified index.
  Parameters:
    in: int startIndex - index from where events should be moved backward
*/
void Calendar::moveEventsBackward(int startIndex)
{
    for (int i = numEvents; i > startIndex; --i)
    {
        events[i] = events[i - 1];
    }
}
