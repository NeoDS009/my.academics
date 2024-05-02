#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  set(h, m);
}

void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

int Time::convertToMins()
{
  return (hours*60 + minutes);
}

void Time::print()
{
  cout << right << setfill('0')<<setw(2)<<hours<<":"
       << right << setfill('0')<<setw(2)<<minutes;
}

bool Time::computeSlot(TimeSlotType& slot)
{
  int totalMinutes = convertToMins();

  if (totalMinutes >= (8 * 60 + 30) && totalMinutes < (10 * 60))
    slot = SLOT_0830;
  else if (totalMinutes >= (10 * 60) && totalMinutes < (11 * 60 + 30))
    slot = SLOT_1000;
  else if (totalMinutes >= (11 * 60 + 30) && totalMinutes < (13 * 60))
    slot = SLOT_1130;
  else if (totalMinutes >= (13 * 60) && totalMinutes < (14 * 60 + 30))
    slot = SLOT_1300;
  else if (totalMinutes >= (14 * 60 + 30) && totalMinutes < (16 * 60))
    slot = SLOT_1430;
  else if (totalMinutes >= (16 * 60) && totalMinutes < (18 * 60))
    slot = SLOT_1600;
  else if (totalMinutes >= (18 * 60) && totalMinutes < (24 * 60))
    slot = SLOT_1800;
  else {
    slot = BAD_TIME_SLOT;
    return false;
  }

  return true;
}

bool Time::setFromSlot(TimeSlotType slot)
{
  switch (slot)
  {
    case SLOT_0830:
      set(8, 30);
      break;
    case SLOT_1000:
      set(10, 0);
      break;
    case SLOT_1130:
      set(11, 30);
      break;
    case SLOT_1300:
      set(13, 0);
      break;
    case SLOT_1430:
      set(14, 30);
      break;
    case SLOT_1600:
      set(16, 0);
      break;
    case SLOT_1800:
      set(18, 0);
      break;
    default:
      return false;
  }

  return true;
}
