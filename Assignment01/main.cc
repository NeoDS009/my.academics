#include <iostream>
#include <string>
using namespace std;

#include "defs.h"
#include "Calendar.h"

/*
  Function: main
  Purpose: The main function of the program, which runs the interactive calendar application.
  Parameters:
    return: int - exit status
*/
int main()
{
  Calendar timmysCalendar("Timmy Tortoise");

  loadEvents(timmysCalendar);

  int choice;
  do
  {
    showMenu(choice);

    switch (choice)
    {
      case 1:
        {
          cout << endl;
          timmysCalendar.print();
        }
        break;

      case 2:
        {
          int year, month, day;

          cout << "Please enter year, month, and day: ";
          cin >> year >> month >> day;
          cout << endl;
          
          timmysCalendar.printByDay(year, month, day);
        }
        break;

      case 3:
        {
          string category;
          cout << "Enter category: ";
          cin >> category;
          cout << endl;
          timmysCalendar.printByCat(category);
        }
        break;

      case 4:
        {
          string name, category, participant;
          int year, month, day, hours, minutes;

          cout << "Enter the event name: ";
          cin.ignore();
          getline(cin, name);

          cout << "Enter the category: ";
          getline(cin, category);

          cout << "Enter the main participant: ";
          getline(cin, participant);

          cout << "Enter the year: ";
          cin >> year;

          cout << "Enter the month: ";
          cin >> month;

          cout << "Enter the day: ";
          cin >> day;

          cout << "Enter the start hours: ";
          cin >> hours;

          cout << "Enter the start minutes: ";
          cin >> minutes;

          bool success = timmysCalendar.addEvent(name, category, participant, year, month, day, hours, minutes);

          if (success) {
            cout << endl;
            cout << "Event added successfully!" << endl;
          }
          else {
            cout << endl;
            cout << "Error adding event. Please check your input." << endl;
          }
        }
        break;

      case 0:
        cout << "Exiting the program. Goodbye!" << endl;
        break;

      default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }

  } while (choice != 0);

  return 0;
}

/*
  Function: showMenu
  Purpose: Displays the menu options for the user and prompts for their choice.
  Parameters:
    in: int& choice - reference to store the user's choice
*/
void showMenu(int& choice)
{
 int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) View calendar" << endl;
  cout << "  (2) View day calendar" << endl;
  cout << "  (3) View category calendar" << endl;
  cout << "  (4) Add an event" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

/*
  Function: loadEvents
  Purpose: Loads a set of predefined events into the given calendar.
  Parameters:
    in: Calendar& cal - reference to the calendar to load events into
*/
void loadEvents(Calendar& cal)
{
  cal.addEvent("2024 National Heroes Conference", "Work",  "Timmy", 2024,  2, 25,  8, 30);
  cal.addEvent("2023 National Heroes Conference", "Work",  "Timmy", 2023,  2, 24,  8, 30);
  cal.addEvent("Slay dragon",                     "Work",  "Timmy", 2024,  4, 11,  9, 30);
  cal.addEvent("Climb Mount of Dooom",            "Work",  "Timmy", 2024,  4,  8, 10,  0);
  cal.addEvent("some thing",                      "Work",  "Timmy", 2024,  3, 32, 10,  0);
  cal.addEvent("some other thing",                "Other", "Timmy", 2023,  2,  1, 24,  0);
  cal.addEvent("some new thing",                  "Test",  "Timmy", 2023,  2, 18, 14,  0);
  cal.addEvent("Lunch with Gwendolyn",            "Home",  "Timmy", 2024,  3, 29, 11, 45);
  cal.addEvent("Heroes meeting",                  "Work",  "Timmy", 2024,  1,  8,  9,  0);
  cal.addEvent("Practice sparring",               "Work",  "Timmy", 2024,  1, 10, 13, 45);
  cal.addEvent("Sharpen sword",                   "Work",  "Timmy", 2024,  1, 10, 13,  5);
  cal.addEvent("Dinner with Harold",              "Home",  "Timmy", 2024,  3, 30, 18, 30);
  cal.addEvent("Theatre with Harold",             "Home",  "Timmy", 2024,  3, 30, 16,  0);
  cal.addEvent("Grocery shopping",                "Home",  "Timmy", 2024,  1, 20,  9, 45);
  cal.addEvent("Meeting with Wizard",             "Work",  "Timmy", 2024,  3, 28,  6, 15);
  cal.addEvent("some bad thing",                  "Home",  "Timmy", 2023, 22, 18, 14,  0);

  cal.addParticipant(3012, "Harold");
  cal.addParticipant(3011, "Harold");
  cal.addParticipant(3004, "Harold");
  cal.addParticipant(3009, "Harold");
  cal.addParticipant(3004, "Dorc friends");
  cal.addParticipant(3003, "Harold");
  cal.addParticipant(3007, "Gwendolyn");
}

