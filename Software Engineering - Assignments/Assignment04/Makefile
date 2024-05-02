OPT = -Wall

a04:	main.o Position.o Pit.o Participant.o PartArray.o Hero.o Snorc.o Escape.o
	g++ $(OPT) -o a04 main.o Position.o Pit.o Participant.o PartArray.o Hero.o Snorc.o Escape.o

Participant.o:	Participant.cc Participant.h
	g++ $(OPT) -c Participant.cc

Position.o:	Position.cc Position.h
	g++ $(OPT) -c Position.cc

Pit.o:	Pit.cc Pit.h
	g++ $(OPT) -c Pit.cc

PartArray.o:	PartArray.cc PartArray.h
	g++ $(OPT) -c PartArray.cc

Hero.o:	Hero.cc Hero.h
	g++ $(OPT) -c Hero.cc

Snorc.o:	Snorc.cc Snorc.h
	g++ $(OPT) -c Snorc.cc

Escape.o:	Escape.cc Escape.h
	g++ $(OPT) -c Escape.cc

main.o:	main.cc Escape.h
	g++ $(OPT) -c main.cc

clean:
	rm -f *.o a04
