#include <iostream>
#include <iomanip>
using namespace std;

#include "Event.h"

/*
  Function: Event::Event
  Purpose: Constructor for the Event class. Initializes event details based on the given parameters.
  Parameters:
    in: int id - event identifier
    in: const string& name - event name
    in: const string& category - event category
    in: const string& participant - main participant
    in: int year - event year
    in: int month - event month
    in: int day - event day
    in: int startHours - event start hours
    in: int startMinutes - event start minutes
*/
Event::Event(int id, const string& name, const string& category, const string& participant,
             int year, int month, int day, int startHours, int startMinutes)
     : eventDate(day, month, year), eventStartTime(startHours, startMinutes)
{
    eventIdentifier = id;
    eventName = name;
    eventCategory = category;
    numParticipants = 0;

    addParticipant(participant);
}

/*
  Function: Event::getId
  Purpose: Returns the event identifier.
  Parameters:
    return: int - event identifier
*/
int Event::getId()
{
    return eventIdentifier;
}

/*
  Function: Event::getCategory
  Purpose: Returns the event category.
  Parameters:
    return: string& - reference to the event category
*/
string& Event::getCategory()
{
    return eventCategory;
}

/*
  Function: Event::getDate
  Purpose: Returns the Date object associated with the event.
  Parameters:
    return: Date& - reference to the Date object
*/
Date& Event::getDate()
{
    return eventDate;
}

/*
  Function: Event::set
  Purpose: Sets the details of the Event object based on another Event object.
  Parameters:
    in: Event& e - reference to another Event object
*/
void Event::set(Event& e)
{
    eventIdentifier = e.eventIdentifier;
    eventName = e.eventName;
    eventCategory = e.eventCategory;
    numParticipants = e.numParticipants;
    eventDate.set(e.eventDate);
    eventStartTime.set(e.eventStartTime);

    for (int i = 0; i < numParticipants; ++i)
    {
        participants[i] = e.participants[i];
    }
}

/*
  Function: Event::addParticipant
  Purpose: Adds a participant to the event's participant list.
  Parameters:
    in: const string& p - participant name
*/
void Event::addParticipant(const string& p)
{
    if (numParticipants < MAX_PART)
    {
        participants[numParticipants++] = p;
    }
    else {
        cout << "The event is full! Cannot add any more participants..." << endl;
    }
}

/*
  Function: Event::lessThan
  Purpose: Checks if the current Event is less than another Event based on date and time.
  Parameters:
    in: Event& e - reference to another Event object
    return: bool - true if current Event is less than e, false otherwise
*/
bool Event::lessThan(Event& e)
{
    if (eventDate.lessThan(e.eventDate)) {
        return true;
    }
    else if (eventDate.equals(e.eventDate) && eventStartTime.lessThan(e.eventStartTime)) {
        return true;
    }
    return false;
}

/*
  Function: Event::print
  Purpose: Prints the details of the Event object in a formatted way.
  Parameters:
*/
void Event::print()
{
    cout << "== " << setw(6) << left << setfill(' ') << eventIdentifier
        << setw(10) << left << setfill(' ') << eventCategory << ":: "
        << setw(35) << left << setfill(' ') << eventName << " :: ";

    eventDate.print();
    cout << " @ ";
    eventStartTime.print();
    cout << " with ";
    for (int i = 0; i < numParticipants; ++i)
    {
        cout << participants[i] << ", ";
        if (i == numParticipants - 1) {
            cout << participants[i];
        }
    }
    
}
