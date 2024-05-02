#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
  public:
    Date(int = 0, int = 0, int = 2000);
    void set(int, int, int);
    void print();

    void set(Date&);
    bool equals(Date&);
    bool lessThan(Date&);
    bool validate(int, int, int);

  private:
    int    day;
    int    month;
    int    year;

    int  lastDayInMonth(int, int);
    bool leapYear(int);
    string getMonthStr(int);
};

#endif
