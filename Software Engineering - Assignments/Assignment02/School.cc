#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "School.h"

School::School(string name) : name(name) { }

School::~School() { }

void School::addCourse(Course* course)
{
    courseCollection.add(course);
}

bool School::findCourse(int id, Course** course)
{
    return courseCollection.find(id, course);
}

void School::printCourses(string term)
{
    cout << endl;
    cout << endl;
    cout <<  name << " COURSES FOR TERM " << term << endl;
    courseCollection.print(term);
}
