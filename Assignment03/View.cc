#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showAdminMenu(int& choice)
{
  int numOptions = 4;

  cout << endl << endl << "ADMINISTRATOR MENU" << endl << endl;;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) View students" << endl;
  cout << "  (2) View courses" << endl;
  cout << "  (3) View registrations" << endl;
  cout << "  (4) Show student menu" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::showStudentMenu(string name, int& choice)
{
  int numOptions = 3;

  cout << endl << endl << "STUDENT MENU FOR " << name << endl << endl;;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) View courses by term" << endl;
  cout << "  (2) View registrations by student" << endl;
  cout << "  (3) Add registration" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}



