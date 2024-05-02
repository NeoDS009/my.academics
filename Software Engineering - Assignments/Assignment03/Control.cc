#include <iostream>
using namespace std;
#include <string>

#include <cstdlib>

#include "Control.h"

Control::Control() : school(new School()) {}

Control::~Control()
{
  delete school;
}

void Control::launch()
{
    initCourses(school);
    initStudents(school);

    int choice;
    while (true)
    {
        view.showAdminMenu(choice);
        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
            school->printStudents();
            break;
        case 2:
            school->printCourses();
            break;
        case 3:
            school->printRegistrations();
            break;
        case 4:
            {
                string studentNum;
                Student* student;
                do
                {
                    view.readStr(studentNum);
                    view.printStr("ERROR: Student not found\n");
                } while (!school->findStudent(studentNum, &student));

                while (true)
                {
                    view.showStudentMenu(student->getName(), choice);
                    if (choice == 0)
                        break;

                    switch (choice)
                    {
                    case 1:
                        {
                            string term;
                            view.printStr("Please enter term: ");   
                            view.readStr(term);                                                 
                            school->printCoursesByTerm(term);
                        }
                        break;
                    case 2:
                        school->printRegistrationsByStu(student);
                        break;
                    case 3:
                        {
                            int courseId;
                            Course* course;
                            do
                            {
                                view.printStr("Please enter course id: ");
                                view.readInt(courseId);

                                if (!school->findCourse(courseId, &course))
                                  view.printStr("ERROR: Course not found\n");
                            } while (!school->findCourse(courseId, &course));
                            school->addRegistration(student, course);
                        }
                        break;
                    }
                }
            }
            break;
        }
    }
}


void Control::initStudents(School* sch)
{
  sch->addStu(new Student("100567888", "Matilda", "CS"));
  sch->addStu(new Student("100333444", "Harold", "Geography"));
  sch->addStu(new Student("100444555", "Joe", "Physics"));
  sch->addStu(new Student("100775588", "Timmy", "CS"));
  sch->addStu(new Student("100111222", "Amy", "Math"));
  sch->addStu(new Student("100222333", "Stanley", "Art History"));
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen"));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill"));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill"));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel"));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin"));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill"));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI"));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier"));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp"));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel"));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel"));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill"));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill"));
}


