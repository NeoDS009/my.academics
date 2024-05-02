#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "View.h"  

class Control
{
  public:
    /*
      Function: Control (constructor)
      Purpose: Initializes an instance of the Control class
      Parameters:
        in: None
        out: None
        in/out: None
      Return: None
    */
    Control();

    /*
      Function: ~Control (destructor)
      Purpose: Destroys an instance of the Control class
      Parameters:
        in: None
        out: None
        in/out: None
      Return: None
    */
    ~Control();

    /*
      Function: launch
      Purpose: Starts the program by initializing courses and students and entering the main loop
      Parameters:
        in: None
        out: None
        in/out: None
      Return: None
    */
    void launch();

  private:
    /*
      Function: initCourses
      Purpose: Initializes the courses for the school
      Parameters:
        in: School pointer
        out: None
        in/out: None
      Return: None
    */
    void initCourses(School*);

    /*
      Function: initStudents
      Purpose: Initializes the students for the school
      Parameters:
        in: School pointer
        out: None
        in/out: None
      Return: None
    */
    void initStudents(School*);

    School* school;
    View view;    

    /*
      Function: adminMenu
      Purpose: Displays the admin menu and handles user input
      Parameters:
        in: None
        out: None
        in/out: None
      Return: None
    */
    void adminMenu();

    /*
      Function: studentMenu
      Purpose: Displays the student menu and handles user input
      Parameters:
        in: Student pointer
        out: None
        in/out: None
      Return: None
    */
    void studentMenu(Student*);
};

#endif
