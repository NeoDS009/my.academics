#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"

Course::Course(string term, string subject, int code, char section, string instructor, LectDaysType days, int hours, int minutes)
    :term(term), subject(subject), code(code), section(section), instructor(instructor), days(days)
{
    time = new Time(hours, minutes);
}

Course::~Course()
{
    delete time;
}

int Course::getId() const
{
    return id;
}

string Course::getTerm() const
{
    return term;
}

string Course::getInstructor() const
{
    return instructor;
}

string Course::getCode() const
{
    return subject + " " + to_string(code) + "-" + section;
}

void Course::setId(int courseId)
{
    id = courseId;
}

bool Course::computeDays(WeekDayType& day1, WeekDayType& day2)
{
    switch (days)
    {
        case MON_WED:
            day1 = MON;
            day2 = WED;
            break;
        case TUE_THU:
            day1 = TUE;
            day2 = THU;
            break;
        case WED_FRI:
            day1 = WED;
            day2 = FRI;
            break;
        default:
            return false;
    }

    return true;
}

bool Course::computeSlot(TimeSlotType& slot)
{
    if (time != nullptr) {
        return time->computeSlot(slot);
    }
    else {
        return false;
    }
}

bool Course::lessThan(Course* course)
{
    if (subject != course->subject)
        return subject < course->subject;
    if (code != course->code)
        return code < course->code;
    if (term != course->term)
        return term < course->term;
    return section < course->section;
}

void Course::print()
{
    cout << id << "  " << "Term: " << term << "   " << subject << " " << code << " " << section << "   ";

    WeekDayType day1, day2;
    computeDays(day1, day2);
    switch (days)
    {
        case MON_WED:
            cout << "MW";
            break;
        case TUE_THU:
            cout << "TR";
            break;
        case WED_FRI:
            cout << "WF";
            break;
        default:
            cout << "NA";
            break;
    }
    cout << " ";

    TimeSlotType slot;
    computeSlot(slot);
    switch (slot)
    {
        case SLOT_0830:
            cout << "08:30";
            break;
        case SLOT_1000:
            cout << "10:00";
            break;
        case SLOT_1130:
            cout << "11:30";
            break;
        case SLOT_1300:
            cout << "13:00";
            break;
        case SLOT_1430:
            cout << "14:30";
            break;
        case SLOT_1600:
            cout << "16:00";
            break;
        case SLOT_1800:
            cout << "18:00";
            break;
        default:
            cout << "XX:XX";
            break;
    }

    cout << "   " << "Instr: " << instructor << endl;
}
