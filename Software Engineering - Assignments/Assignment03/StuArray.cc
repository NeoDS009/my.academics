#include <iostream>
using namespace std;

#include "StuArray.h"

StuArray::StuArray()
{
  size = 0;
}

StuArray::~StuArray()
{
  for (int i = 0; i < size; ++i) {
    delete elements[i];
  }
}

void StuArray::add(Student* stu)
{
    if (size >= MAX_ARR)
        return;

    int index = size;
    while (index > 0 && elements[index - 1]->lessThan(stu))
    {
        --index;
    }

    shiftElements(index);

    elements[index] = stu;
    ++size;
}

bool StuArray::find(string stuNum, Student** stu) const
{
    *stu = nullptr;

    for (int i = 0; i < size; ++i)
    {
        if (elements[i]->getNumber() == stuNum)
        {
            *stu = elements[i];
            return true;
        }
    }

    return false;
}

void StuArray::print() const
{
    for (int i = size - 1; i >= 0; i--)
    {
        elements[i]->print();
    }
}

void StuArray::shiftElements(int startIndex)
{
    for (int i = size; i > startIndex; --i)
    {
        elements[i] = elements[i - 1];
    }
}
