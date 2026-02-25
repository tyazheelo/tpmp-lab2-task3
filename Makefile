# Makefile for tpmp-lab2-task3 project

worker2: main.o worker2.o
	gcc -o worker main.o worker2.o

main.o: main.c
	gcc -c main.c

worker2.o: worker2.c
	gcc -c worker2.c

clean:
	rm -f *.o worker2
