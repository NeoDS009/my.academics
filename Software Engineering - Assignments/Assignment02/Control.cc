#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control() {
    numScheds = 0;
    school = new School();
    schedules = nullptr;
}

Control::~Control() {
    delete school;
    for (int i = 0; i < numScheds; ++i) {
        delete schedules[i];
    }
    delete[] schedules;
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

bool Control::addSched(Schedule* newSchedule) {
    if (schedules == nullptr) {
        schedules = new Schedule*[1];
    } else {
        Schedule** temp = new Schedule*[numScheds + 1];
        for (int i = 0; i < numScheds; ++i) {
            temp[i] = schedules[i];
        }
        delete[] schedules;
        schedules = temp;
    }

    schedules[numScheds++] = newSchedule;
    return true;
}

bool Control::findSched(string term, Schedule** foundSchedule) {
    for (int i = 0; i < numScheds; ++i) {
        if (schedules[i]->getTerm() == term) {
            *foundSchedule = schedules[i];
            return true;
        }
    }
    return false;
}

void Control::launch() {
    View view;

    initCourses(school);

    int userChoice;
    string selectedTerm = "NONE SELECTED";

    do {
        cout << endl;
        cout << "TERM: " << selectedTerm;
        view.showMenu(userChoice);

        switch (userChoice) {
            case 1:
                view.readStr(selectedTerm);
                Schedule* existingSchedule;
                if (!findSched(selectedTerm, &existingSchedule)) {
                    Schedule* newSchedule = new Schedule(selectedTerm);
                    addSched(newSchedule);
                }
                break;
            case 2:
                school->printCourses(selectedTerm);
                break;
            case 3:
                Schedule* scheduleToShow;
                if (findSched(selectedTerm, &scheduleToShow)) {
                    view.printStr("\nSCHEDULE FOR CURRENT TERM:  " + selectedTerm + "\n");
                    scheduleToShow->print();
                } else {
                    view.printStr("\nERROR: No term selected\n");
                }
                break;
            case 4:
                Schedule* scheduleToAdd;
                if (!findSched(selectedTerm, &scheduleToAdd)) {
                    view.printStr("\nERROR: No term selected \n");
                    break;
                }

                int courseId;
                view.printStr("Enter course ID: ");
                view.readInt(courseId);

                Course* foundCourse;
                if (!school->findCourse(courseId, &foundCourse)) {
                    view.printStr("ERROR: Course with ID " + to_string(courseId) + " not found.\n");
                    break;
                }

                if (foundCourse->getTerm() != selectedTerm) {
                    view.printStr("ERROR: Course with ID " + to_string(courseId) + " is not offered in term " + selectedTerm + ".\n");
                    break;
                }

                if (scheduleToAdd->addCourse(foundCourse) == true) {
                    view.printStr("SUCCESS: Course added to schedule for term " + selectedTerm + ".\n");
                }
                else {
                    view.printStr("ERROR: Course was not added to the schedule\n");
                }
                break;
            case 5:
                Schedule* scheduleToClear;
                if (!findSched(selectedTerm, &scheduleToClear)) {
                    view.printStr("\nERROR: No schedule found for term " + selectedTerm + "\n");
                    break;
                }

                scheduleToClear->clear();
                view.printStr("SUCCESS: Schedule cleared for term " + selectedTerm + ".\n");
                break;
            case 0:
                view.printStr("Exiting program...\n");
                return;
            default:
                view.printStr("Invalid choice. Please try again.\n");
                break;
        }
    } while (userChoice != 0);
}
