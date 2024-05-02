#include <iostream>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray()
{
  size = 0;
  nextId = COURSE_ID;
}

CourseArray::~CourseArray()
{
  for (int i = 0; i < size; ++i) {
    delete elements[i];
  }
}

void CourseArray::add(Course* d)
{
    if (size >= MAX_ARR)
        return;

    d->setId(nextId);
    ++nextId;

    int index = size;
    while (index > 0 && elements[index - 1]->lessThan(d))
    {
        --index;
    }

    shiftElements(index);

    elements[index] = d;
    ++size;
}

void CourseArray::print(string term)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (elements[i]->getTerm() == term)
        {
            elements[i]->print();
        }
    }
}

bool CourseArray::find(int id, Course** c)
{
    *c = nullptr;

    for (int i = 0; i < size; ++i)
    {
        if (elements[i]->getId() == id)
        {
            *c = elements[i];
            return true;
        }
    }

    return false;
}

void CourseArray::shiftElements(int startIndex)
{
    for (int i = size; i > startIndex; --i)
    {
        elements[i] = elements[i - 1];
    }
}
