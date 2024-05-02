#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;
#include <iostream>
#include <iomanip>

#include "defs.h" 

class Course
{
private:
    static int nextId; 
    int id;            
    string term;       
    string subject;    
    int code;          
    char section;      
    string instructor; 

public:
    /*
      Function: Course (constructor)
      Purpose: Initializes an instance of the Course class with default or specified values
      Parameters:
        in: Subject of the course
    */
    Course(string subject = " ", string term = " ", int code = 0, char section = ' ', string instructor = " ");

    /*
      Function: lessThan
      Purpose: Compares the current course with another course based on specific criteria
      Parameters:
        in: Course pointer
      Return: Boolean indicating if the current course is less than the given course
    */
    bool lessThan(Course*) const;

    /*
      Function: print
      Purpose: Displays information about the course
    */
    void print() const;

    /*
      Function: getId
      Purpose: Retrieves the unique identifier of the course
      Return: Integer representing the course ID
    */
    int getId() const;

    /*
      Function: getTerm
      Purpose: Retrieves the academic term during which the course is offered
      Return: String representing the academic term
    */
    string getTerm() const;

    /*
      Function: getCode
      Purpose: Retrieves the course code
      Return: String representing the course code
    */
    string getCode() const;
};

#endif
