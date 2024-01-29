PREAMBLE
Program author:
Deneo Shi 101271921

Purpose:
The program initializes a restaurant (initRestaurant), loads sample patron and reservation data 
(loadPatronData, loadResData), and enters a loop to display the menu (printMenu), allowing the 
user to interact with 4 main functionalities like printing patrons (printPatrons), reservations 
(printReservations), reservations by a specific patron (printResByPatron), and will continue to 
prompt the user with the same functionalities, until the user chooses to exit the program. 
Moreover, memory cleanup is performed before the program exits (cleanupRestaurant).

Source files:
- main.c
- load.c

Header files:
- defs.h

Data files:
- NONE - n/a


COMPILATION AND LAUNCHING INSTRUCTIONS:
tar -xvf Assignment04.tar
cd Assignment04
gcc -Wall -o a4 main.c load.c
./a4
