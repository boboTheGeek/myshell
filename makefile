SOURCES = myshell.c mycd.c myclr.c mydir.c myecho.c myenviron.c myhelp.c mypause.c myquit.c
OBJECTS = myshell.o mycd.o myclr.o mydir.o myecho.o myenviron.o myhelp.o mypause.o myquit.o
HEADERS = myshell.h
CC = gcc
CFLAGS = -g -Wall
sequences :$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o myshell
clean:
	rm -f *o myshell