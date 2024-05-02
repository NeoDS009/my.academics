#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

class View
{
public:
    /*
      Function: showAdminMenu
      Purpose: Displays the admin menu and retrieves the user's choice
      Parameters:
        out: Reference to an integer to store the user's choice
    */
    void showAdminMenu(int&);

    /*
      Function: showStudentMenu
      Purpose: Displays the student menu with the given name and retrieves the user's choice
      Parameters:
        in: String representing the student's name
        out: Reference to an integer to store the user's choice
    */
    void showStudentMenu(string, int&);

    /*
      Function: printStr
      Purpose: Prints a string to the console
      Parameters:
        in: String to be printed
    */
    void printStr(string);

    /*
      Function: readInt
      Purpose: Reads an integer from the console
      Parameters:
        out: Reference to an integer to store the user input
    */
    void readInt(int&);

    /*
      Function: readStr
      Purpose: Reads a string from the console
      Parameters:
        out: Reference to a string to store the user input
    */
    void readStr(string&);
};

#endif
