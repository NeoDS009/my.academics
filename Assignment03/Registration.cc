#include "Registration.h"



int Registration::nextId = REG_ID;

Registration::Registration(Student* student, Course* course)
    :student(student), course(course)
{
    id = nextId++;
}

bool Registration::lessThan(Registration* reg) const        
{
    return course->lessThan(reg->course);

}

void Registration::print() const
{
    cout << setw(6) << left << setfill(' ') << id
    << setw(15) << left << setfill(' ') << student->getName()
    << setw(5) << left << setfill(' ') << course->getTerm()
    << course->getCode() << endl;
}

Student* Registration::getStudent() const
{
    return student;
}