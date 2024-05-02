#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>
using namespace std;

#include "Student.h"
#include "Course.h"
#include "defs.h"

class Registration
{
    private:
        static int nextId;
        int id;
        Student* student;
        Course* course;

    public:
        /*
          Function: Registration (constructor)
          Purpose: Initializes an instance of the Registration class with specified Student and Course pointers
          Parameters:
             in: Student pointer representing the student being registered
             in: Course pointer representing the course for registration
        */
        Registration(Student* student = nullptr, Course* course = nullptr);

        /*
          Function: lessThan
          Purpose: Compares two Registration instances based on their associated courses
          Parameters:
            in: Registration pointer to be compared
          Return: Boolean indicating if the current Registration's course is less than the input Registration's course
        */
        bool lessThan(Registration*) const;

        /*
          Function: print
          Purpose: Displays information about the registration, including the registration ID, student, and course details
        */
        void print() const;

        /*
          Function: getStudent
          Purpose: Retrieves the Student pointer associated with the registration
          Return: Student pointer
        */
        Student* getStudent() const;
};

#endif
