OBJ = main.o connect.o escape.o hero.o flyer.o hollow.o client.o
EXE = a5
CC = gcc -Wall 

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o: main.c defs.h
	$(CC) -c main.c

connect.o: connect.c defs.h
	$(CC) -c connect.c

escape.o: escape.c defs.h
	$(CC) -c escape.c

hero.o: hero.c defs.h
	$(CC) -c hero.c

flyer.o: flyer.c defs.h
	$(CC) -c flyer.c

hollow.o: hollow.c defs.h
	$(CC) -c hollow.c

client.o: client.c defs.h
	$(CC) -c client.c

clean:
	rm -f $(EXE) $(OBJ)
