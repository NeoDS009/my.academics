#include "Course.h"


int Course::nextId = COURSE_ID;

Course::Course(string term, string subject, int code, char section, string instructor)
    :term(term), subject(subject), code(code), section(section), instructor(instructor)
{
    id = nextId++;
}

bool Course::lessThan(Course* course) const
{
    if (subject != course->subject)
        return subject < course->subject;
    if (code != course->code)
        return code < course->code;
    if (term != course->term)
        return term < course->term;
    return section < course->section;
}

void Course::print() const
{
    cout << setw(6) << left << setfill(' ') << id
    << "Term: " << setw(5) << left << term
    << getCode() << "  "
    << "Instr: " << instructor << endl;
}

int Course::getId() const
{
    return id;
}

string Course::getTerm() const
{
    return term;
}

string Course::getCode() const
{
    return subject + " " + to_string(code) + " " + section;
}