#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

#include "Date.h"
#include "Time.h"
#include "defs.h"

class Event
{
public:
    Event(int = 0, const string& = " ", const string& = " ", const string& = " ", int = 0, int = 0, int = 0, int = 0, int = 0);

    int getId();
    string& getCategory();
    Date& getDate();

    void set(Event&);
    void addParticipant(const string&);
    bool lessThan(Event&);
    void print();


private:
    int eventIdentifier;
    string eventName;
    string eventCategory; 

    string participants[MAX_PART]; 
    int numParticipants;

    Date eventDate;
    Time eventStartTime;
};

#endif