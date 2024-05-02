#include "Student.h"

Student::Student(string num, string n, string m)
    : number(num), name(n), majorPgm(m)
{ }

bool Student::lessThan(Student* stu) const
{
    return name < stu->name;
}

void Student::print() const
{
    cout << setw(12) << left << setfill(' ') << number
    << setw(15) << left << setfill(' ') << name
    << majorPgm << endl;
}


string Student::getNumber() const
{
    return number;
}
string Student::getName() const
{
    return name;
}