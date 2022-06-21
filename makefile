default:
	gcc main.c database.c patient.c
	./a.out

compile:
	gcc -c main.c database.c patient.c

link:
	gcc -o main main.o database.o patient.o

run:
	./main

clean:
	rm *.o