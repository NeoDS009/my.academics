#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
using namespace std;

#include "Event.h"


class Calendar
{
public:
    Calendar(const string& = " ");

    bool addEvent(const string&, const string&, const string&, int, int, int, int, int);

    bool addParticipant(int, const string&);

    void print();
    void printByDay(int, int, int);
    void printByCat(const string&);

private:
    string userName;
    Event events[MAX_ARR];
    int numEvents;
    int nextEventId;

    int findInsertIndex(Event&);
    void moveEventsBackward(int);
};

#endif
