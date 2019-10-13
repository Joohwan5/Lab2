
operation: main.o add.o minus.o multiply.o divide.o
	gcc -o operation main.o add.o minus.o multiply.o divide.o
main.o: main.c
	gcc -c main.c
add.o: add.c
	gcc -c add.c
minus.o: minus.c
	gcc -c minus.c
multply.o: multiply.c
	gcc -c multiply.c
divide.o: divide.c
	gcc -c divide.c
clean:
	rm -f operation main.o add.o minus.o multiply.o divide.o
