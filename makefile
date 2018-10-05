SOURCES = myshell.c mycd.c mydir.c myecho.c myenviron.c myhelp.c mypause.c myquit.c handler.c
OBJECTS = myshell.o mycd.o mydir.o myecho.o myenviron.o myhelp.o mypause.o myquit.o handler.o
HEADERS = myshell.h
CC = gcc
CFLAGS = -g -Wall
sequences :$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o myshell
clean:
	rm -f *o myshell