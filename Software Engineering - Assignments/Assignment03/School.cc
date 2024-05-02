#include "School.h"


School::School(string name) : name(name) { }

School::~School()
{
    registrations.cleanData();
}

void School::addStu(Student* stu)
{
    students.add(stu);
}

void School::addCourse(Course* course)
{
    courses.add(course);
}

void School::addRegistration(Student* stu, Course* course)
{
    Registration* reg = new Registration(stu, course);
    registrations.add(reg);
}

bool School::findStudent(string num, Student** stu)
{
    return students.find(num, stu);
}

bool School::findCourse(int id, Course** course)
{
    return courses.find(id, course);
}

void School::printStudents()
{
    cout << "STUDENTS OF " << name << endl;
    students.print();
}

void School::printCourses()
{
    cout << "COURSES OF " << name << endl;
    courses.print();
}

void School::printCoursesByTerm(string term)
{
    cout << "COURSES OF " << name << " FOR TERM " << term << endl;
    courses.print(term);
}

void School::printRegistrations()
{
    cout << "REGISTRATIONS OF " << name << endl;
    registrations.print();
}

void School::printRegistrationsByStu(Student* stu)
{
    cout << "REGISTRATIONS FOR " << stu->getName() << endl;
    RegList stuRegistrations(registrations, stu);
    stuRegistrations.print();
}