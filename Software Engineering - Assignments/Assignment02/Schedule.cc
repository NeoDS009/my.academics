#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Schedule.h"

Schedule::Schedule(string term) : term(term)
{
    for (int i = 0; i < NUM_DAYS; ++i)
    {
        for (int j = 0; j < NUM_SLOTS; ++j)
        {
            scheduleArray[i][j] = nullptr;
        }
    }
}

Schedule::~Schedule()
{
    clear();
}

bool Schedule::addCourse(Course* course) {
    if (course == nullptr) {
        cout << "ERROR: There is no Course to be added!" << endl;
        return false;
    }

    if (course->getTerm() != term) {
        cout << "ERROR: The Course term is " << course->getTerm() << ", while the current term is " << term << endl;
        return false;
    }

    WeekDayType day1, day2;
    TimeSlotType slot;

    if (!course->computeDays(day1, day2) || !course->computeSlot(slot)) {
        cout << "ERROR: Failed to compute days or time slot for the course." << endl;
        return false;
    }

    int index1 = getArrayIndex(day1, slot);
    int index2 = getArrayIndex(day2, slot);

    if (index1 < 0 || index1 >= NUM_DAYS * NUM_SLOTS || index2 < 0 || index2 >= NUM_DAYS * NUM_SLOTS) {
        cout << "ERROR: Array indices out of bounds." << endl;
        return false;
    }

    if (scheduleArray[day1][slot] != nullptr || scheduleArray[day2][slot] != nullptr) {
        cout << "ERROR: Time slot is already occupied." << endl;
        return false;
    }

    scheduleArray[day1][slot] = course;
    scheduleArray[day2][slot] = course;

    return true;
}

int Schedule::getArrayIndex(WeekDayType day, TimeSlotType slot) {
    return static_cast<int>(day) % NUM_DAYS * NUM_SLOTS + static_cast<int>(slot) % NUM_SLOTS;
}

void Schedule::print()
{
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(20) << "MON" << setw(20) << "TUE" << setw(20) << "WED" << setw(20) << "THU" << setw(20) << "FRI" << setw(15) << "|" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < NUM_SLOTS; ++i)
    {
        cout << "|" << setw(5) << static_cast<TimeSlotType>(i) << " |";
        for (int j = 0; j < NUM_DAYS; ++j)
        {
            if (scheduleArray[j][i] != nullptr)
            {
                scheduleArray[j][i]->print();
            }
            else
            {
                cout << setw(20) << "|";
            }
        }
        cout << endl;
    }
}

void Schedule::clear()
{
    for (int i = 0; i < NUM_DAYS; ++i)
    {
        for (int j = 0; j < NUM_SLOTS; ++j)
        {
            scheduleArray[i][j] = nullptr;
        }
    }
}

string Schedule::getTerm() const
{
    return term;
}
