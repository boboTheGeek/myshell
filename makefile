#CSC521 Operating system
#Project1 - A MyShell Program
#Programmer:   Rob Miles
#Professor:    Dr.    Lee
#File Created: September 28, 2018


SOURCES = myshell.c mypause.c handler.c splitline.c mycd.c executer.c prompt.c
OBJECTS = myshell.o mypause.o handler.o splitline.o mycd.o executer.o prompt.o
HEADERS = myshell.h
CC = gcc
CFLAGS = -g -Wall

all: myshell mydir myenviron myhelp myclear myecho

myshell:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o myshell

mydir: mydir.c
	$(CC) $(CFLAGS)  -o mydir mydir.c

myenviron: myenviron.c
	$(CC) $(CFLAGS)  -o myenviron myenviron.c

myhelp: myhelp.c
	$(CC) $(CFLAGS)  -o myhelp myhelp.c

myclear: myclear.c
	$(CC) $(CFLAGS)  -o myclear myclear.c

mycd: mycd.c
	$(CC) $(CFLAGS)  -o mycd mycd.c

myecho: myecho.c
	$(CC) $(CFLAGS)  -o myecho myecho.c

clean:
	rm -f *o myshell; \
    rm -f mydir myenviron myhelp myclear mycd
