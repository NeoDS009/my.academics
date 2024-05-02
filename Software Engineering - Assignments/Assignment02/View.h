#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/**
 * Class: View
 * Purpose: Handles user interface and interaction.
 */
class View
{
  public:
    /**
     * Constructor:
     * Purpose: Initializes a View object.
     */
    View();
    
    /**
     * Function: showMenu
     * Purpose: Displays the main menu and reads user's choice.
     * Parameters:
     *   out: choice - User's choice from the menu.
     */
    void showMenu(int&);

    /**
     * Function: printStr
     * Purpose: Displays a string to the console.
     * Parameters:
     *   in: str - The string to be displayed.
     */
    void printStr(string);

    /**
     * Function: readInt
     * Purpose: Reads an integer from the console.
     * Parameters:
     *   out: num - The read integer.
     */
    void readInt(int&);

    /**
     * Function: readStr
     * Purpose: Reads a string from the console.
     * Parameters:
     *   out: str - The read string.
     */
    void readStr(string&);
};

#endif
