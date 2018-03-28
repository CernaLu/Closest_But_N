CC = gcc
CFLAGS   = -O3 -lm -Wall -Wstrict-prototypes -ansi -pedantic
COMMONSRC = libraries.h
EXECUTABLE = ../bin/closest_but_n


$(EXECUTABLE): closest_but_n.o simple_random.o parsing.o output.o $(COMMONSRC)
	$(CC) -o $(EXECUTABLE) closest_but_n.o simple_random.o\
                               parsing.o output.o $(CFLAGS)


closest_but_n.o: closest_but_n.c $(COMMONSRC)
	$(CC) -c -o closest_but_n.o closest_but_n.c $(CFLAGS)

simple_random.o: simple_random.c simple_random.h $(COMMONSRC)
	$(CC) -c -o simple_random.o simple_random.c $(CFLAGS)

output.o: output.c output.h $(COMMONSRC)
	$(CC) -c -o output.o output.c $(CFLAGS)

parsing.o: parsing.c parsing.h $(COMMONSRC)
	$(CC) -c -o parsing.o parsing.c $(CFLAGS)


clean:
	rm -f *.o $(EXECUTABLE)
