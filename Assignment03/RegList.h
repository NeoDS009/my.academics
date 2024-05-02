#ifndef REGLIST_H
#define REGLIST_H

#include "Registration.h"

class RegList
{
  class Node
  {
    public:
      Registration* data;
      Node*    next;
  };

  public:
    /*
      Function: RegList (constructor)
      Purpose: Initializes an instance of the RegList class with default values
    */
    RegList();

    /*
      Function: RegList (copy constructor)
      Purpose: Initializes an instance of the RegList class by copying elements from another list that match a specific student
      Parameters:
        in: Reference to another RegList to be copied
        in: Student pointer representing the student for filtering the copied elements
    */
    RegList(RegList&, Student*);

    /*
      Function: ~RegList (destructor)
      Purpose: Destroys an instance of the RegList class, freeing memory allocated for nodes and associated data
    */
    ~RegList();

    /*
      Function: add
      Purpose: Adds a new registration to the list, maintaining a sorted order
      Parameters:
        in: Registration pointer to be added
    */
    void add(Registration*);

    /*
      Function: del
      Purpose: Deletes a registration from the list based on the student's name
      Parameters:
        in: String representing the name of the student to be deleted
        out: Registration pointer of the deleted registration (if found)
    */
    void del(string, Registration**);

    /*
      Function: print
      Purpose: Displays information about all registrations in the list
    */
    void print() const;

    /*
      Function: cleanData
      Purpose: Frees memory allocated for nodes and associated data, cleaning up the list
    */
    void cleanData();

  private:
    Node* head;
    Node* tail;
};

#endif
