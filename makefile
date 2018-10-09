SOURCES = myshell.c mypause.c handler.c splitline.c mycd.c executer.c prompt.c
OBJECTS = myshell.o mypause.o handler.o splitline.o mycd.o executer.c prompt.o
HEADERS = myshell.h
CC = gcc
CFLAGS = -g -Wall
CFLAGSNODEBUG = -Wall

all: myshell mydir myenviron myhelp myclear myecho

myshell:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o myshell

mydir: mydir.c
	$(CC) $(CFLAGSNODEBUG)  -o mydir mydir.c

myenviron: myenviron.c
	$(CC) $(CFLAGSNODEBUG)  -o myenviron myenviron.c

myhelp: myhelp.c
	$(CC) $(CFLAGSNODEBUG)  -o myhelp myhelp.c

myclear: myclear.c
	$(CC) $(CFLAGSNODEBUG)  -o myclear myclear.c

mycd: mycd.c
	$(CC) $(CFLAGSNODEBUG)  -o mycd mycd.c

myecho: myecho.c
	$(CC) $(CFLAGSNODEBUG)  -o myecho myecho.c

clean:
	rm -f *o myshell; \
    rm -f mydir myenviron myhelp myclear mycd
