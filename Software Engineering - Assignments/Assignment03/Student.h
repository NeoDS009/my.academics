#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;
#include <iostream>
#include <iomanip>

class Student
{
private:
    string number;   
    string name;     
    string majorPgm; 

public:
    /*
      Function: Student (constructor)
      Purpose: Initializes an instance of the Student class with default values
      Parameters:
        in: String representing the student number (default is "UNAVAILABLE")
        in: String representing the student name (default is "HEY YOU!")
        in: String representing the major program (default is "DROPOUT")
    */
    Student(string num = "UNAVAILABLE", string n = "HEY YOU!", string m = "DROPOUT");

    /*
      Function: lessThan
      Purpose: Compares two Student objects based on their student numbers
      Parameters:
        in: Pointer to the Student object to compare
      Return: Boolean value indicating whether the current student is less than the provided student
    */
    bool lessThan(Student*) const;

    /*
      Function: print
      Purpose: Prints information about the student
    */
    void print() const;

    /*
      Function: getNumber
      Purpose: Retrieves the student number
      Return: String representing the student number
    */
    string getNumber() const;

    /*
      Function: getName
      Purpose: Retrieves the student name
      Return: String representing the student name
    */
    string getName() const;
};

#endif
