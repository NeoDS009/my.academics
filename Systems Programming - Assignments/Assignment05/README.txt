PREAMBLE
Program author:
Deneo Shi 101271921

Purpose:
A simple game implementing a client-server architecture. The game, titled "Escape", involves two heroes (Timmy and Harold) trying to navigate a game grid, known as the "Hollow". The objective of this game is for the heroes to reach the end of the "Hollow" while avoiding or dealing with obstacles, known as flyers (birds and monkeys), falling from the sky. In other words, the heroes aim to reach the rightmost column of the "Hollow" to escape, before the flyers can completely eliminate the heroes by dealing health damages.

Source files:
- main.c
- client.c
- connect.c
- escape.c
- flyer.c
- hero.c
- hollow.c

Header files:
- defs.h

Makefile
- Makefile

Data files:
- NONE - n/a


COMPILATION AND LAUNCHING INSTRUCTIONS:
tar -xvf Assignment05.tar
cd Assignment05
make

(server side: one terminal)
./a5

(client side: another terminal)
./a5 127.0.0.1
