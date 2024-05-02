#include "PartArray.h"

PartArray::PartArray()
{
  size = 0;
}

PartArray::~PartArray() { }

void PartArray::add(Participant* d)
{
  if (size >= MAX_ARR)
    return;

  elements[size] = d;
  ++size;
}

Participant* PartArray::get(int p)
{
  if (p >= 0 && p < size) {
      return elements[p];
  }
  return nullptr;
}

int PartArray::getSize()
{
    return size;
}

