#
# -g debug flag
#
CC = gcc -g -O3 -Wall


    

set: main.o set.o list.o misc.o
	$(CC) -o set main.o set.o list.o misc.o 

list:	lmain.o list.o 
	$(CC) -o list lmain.o list.o misc.o

lmain.o:	lmain.c list.h misc.o
	$(CC) -c -O lmain.c -o lmain.o

list.o:	list.c list.h
	$(CC) -c -O list.c -o list.o

main.o: main.c set.h
	$(CC) -c main.c -o main.o 

set.o: set.c set.h
	$(CC) -c  set.c -o set.o 

clean:
	@-/bin/rm list set *.bak *.o a.out core xx &> /dev/null

sprint:
	a2ps --delegate=no -T 4 -q -Avirtual -2 -o xd set.h set.c main.c  

lprint:
	a2ps --delegate=no -T 4 -q -Avirtual -2 -o xd list.h  list.c  misc.c  main.c 



# rather than providing a separate goal to build each .o file, you can specify
# a rule for converting any .c file to a .o file!
# .c.o:
# 	$(CC) -c $*.c -o $*.o 
#
# this requires running `make depend` to invoke the following comment
# to build all the header file dependences
#
# augment this makefile with the dependence of all .c files in the directory
# depend:
# 	makedepend -I *.c 
#