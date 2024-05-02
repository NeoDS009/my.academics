#ifndef SCHOOL_H
#define SCHOOL_H

#include "Student.h"
#include "Course.h"
#include "RegList.h"
#include "StuArray.h"
#include "CourseArray.h"
#include <string>
using namespace std;


class School
{
    private:
        string name;
        StuArray students;
        CourseArray courses;
        RegList registrations;

    public:
        /*
          Function: School (constructor)
          Purpose: Initializes an instance of the School class with a default name
          Parameters:
            in: Name of the school
        */
        School(string name = "Carleton U's School of Computer Science");

        /*
          Function: ~School (destructor)
          Purpose: Destroys an instance of the School class, freeing memory allocated for students, courses, and registrations
        */
        ~School();

        /*
          Function: addStu
          Purpose: Adds a student to the school
          Parameters:
             in: Pointer to the Student object to be added
        */
        void addStu(Student* stu);

        /*
          Function: addCourse
          Purpose: Adds a course to the school
          Parameters:
             in: Pointer to the Course object to be added
        */
        void addCourse(Course* course);

        /*
          Function: addRegistration
          Purpose: Adds a registration (student-course pair) to the school
          Parameters:
             in: Pointer to the Student object
             in: Pointer to the Course object
        */
        void addRegistration(Student* stu, Course* course);

        /*
          Function: findStudent
          Purpose: Searches for a student by student number
          Parameters:
             in: String representing the student number to search for
             out: Pointer to the Student object (if found)
          Return: Boolean value indicating whether the student was found
        */
        bool findStudent(string num, Student** stu);

        /*
          Function: findCourse
          Purpose: Searches for a course by course ID
          Parameters:
             in: Integer representing the course ID to search for
             out: Pointer to the Course object (if found)
          Return: Boolean value indicating whether the course was found
        */
        bool findCourse(int id, Course** course);

        /*
          Function: printStudents
          Purpose: Prints information about all students in the school
        */
        void printStudents();

        /*
          Function: printCourses
          Purpose: Prints information about all courses in the school
        */
        void printCourses();

        /*
          Function: printCoursesByTerm
          Purpose: Prints information about all courses in a specific term
          Parameters:
            in: String representing the term to filter courses
        */
        void printCoursesByTerm(string term);

        /*
          Function: printRegistrations
          Purpose: Prints information about all registrations (student-course pairs) in the school
        */
        void printRegistrations();

        /*
          Function: printRegistrationsByStu
          Purpose: Prints information about all registrations (courses) for a specific student
          Parameters:
            in: Pointer to the Student object
        */
        void printRegistrationsByStu(Student* stu);
};

#endif
