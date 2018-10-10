/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myshell.h"

void doheader(){    //pint welcome header and user name
    printf("\033[H\033[J");   //clear function that erases the screen
    printf("============================================================\n");
    printf(" Welcome to myShell.  A shell that is actually for us all!! \n");
    printf("============================================================\n");
    printf("\n");
    printf("***if you're interested in help at this point, type 'myhelp'\n");
    printf("***commands: mycd, myclear, mydir, myenviron, myecho, myhelp, mypause, myquit\n");
    
    char *myUser = getenv("USER");
    printf("Logged in as: ");
    printf("%s \n", myUser);
    
}


int block_commands(char **args){
    const char *ovrrdnCMDs[7] = { "cd", "quit", "echo", "ls", "env", "clear", "help" };         //commands that will be overridden
    for (int i = 0; i < 7; i++){
        if (strcmp((const char *)args[0], ovrrdnCMDs[i]) == 0){
            printf("command disabled, try one of: \n");
            printf("***commands: mycd, myclear, mydir, myenviron, myecho, myhelp, mypause, myquit\n");
            printf("***if you're interested in help at this point, type 'myhelp'\n");
            return 1;
        }
    }
    return 0;
}
