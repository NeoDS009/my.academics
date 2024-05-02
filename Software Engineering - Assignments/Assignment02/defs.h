#ifndef DEFS_H
#define DEFS_H

#define MAX_ARR     256

#define COURSE_ID  4001
#define NUM_DAYS      5
#define NUM_SLOTS     7

typedef enum { MON_WED, TUE_THU, WED_FRI, BAD_LECT_DAYS } LectDaysType;

typedef enum { MON, TUE, WED, THU, FRI, BAD_WEEK_DAY } WeekDayType;

typedef enum { SLOT_0830, SLOT_1000, SLOT_1130, SLOT_1300, 
               SLOT_1430, SLOT_1600, SLOT_1800, BAD_TIME_SLOT } TimeSlotType;

#endif

