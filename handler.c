/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include <stdlib.h>
//#include <dirent.h>
//#include <string.h>
//#include <unistd.h>

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
/*
char *doprompt(char *prompt){        //username and PWD right before user input
    
    size_t size;
    char *buf;
    char *ptr;
    long path_max;
    path_max = pathconf(".", 256);  //check for max path character length
    
    if (path_max == -1){             // make 1024 if problems
        size = 1024;
    } else if (path_max > 10240){     //clip
        size = 10240;
    } else {
        size = path_max;           //or use it if it looks normal
    }
    
    // ******     borrowed from a stack overflow post
    for (buf = ptr = NULL; ptr == NULL; size *= 2)
    {
        if ((buf = realloc(buf, size)) == NULL) {
            printf("warning\n");
        }
        
        ptr = getcwd(buf, size);   //grab the directory [finally!]
        
         if(ptr == NULL) {
             printf("warning: couldn't grab current directory location.\n");
         }
    }
    return buf;
    free (buf);
}

int execute(char *argv[], const char *shell_loc) {
    int pid;
    
    if (argv[0] == NULL)
        return 0;
    if ((pid = fork()) < 0) {
        perror("fork didn't work");
    } else if (pid == 0) {
        signal(SIGINT, SIG_DFL); //reset system so that SIGINT causes a
                                    //termination at any place in our program
        signal(SIGQUIT, SIG_DFL);

        setenv("PARENT", shell_loc, 1); //set env var for parent
        
        if(execv(argv[0], argv) != 0){  //if the binary isn't in ./ then check system
            execvp(argv[0], argv);
        }
        perror("cannot execute command");
        exit(1);
    } else {
        wait(NULL);
    }
    return 0;
}*/
