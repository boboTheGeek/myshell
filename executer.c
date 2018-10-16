/*    
CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#include "myshell.h"

int execute(char *argv[], const char *shell_loc) {
    int pid;
    char location[255];                     //make variable to store path
    strcpy(location, shell_loc);            //grab myshell path location from args
    strcat(location, "/");                  //append trailing slash
    strcat(location, argv[0]);              //path of executibles saved to args for execution

    signal(SIGINT, SIG_IGN);                //block [parent] interrupt so only child stops if interrupted
    signal(SIGQUIT, SIG_IGN);               //block [parent] interrupt so only child stops if stop signal

    if ((pid = fork()) < 0) {               //fork here, check if fails at creating the fork
        perror("fork didn't work");         //complain if it failed
        exit(1);
    
    } else if (pid == 0) {                  //if it succeeded and this is the child process
        signal(SIGINT, SIG_DFL);            //reset system so child signals have default interrupt behavior
        signal(SIGQUIT, SIG_DFL);           //reset system so child signals have default stop behavior
        setenv("PARENT", shell_loc, 1);     //set env var for path of PARENT process
        if(execv(location, argv) != 0){     //run the executible if it's in the ./ same dir as myshell (our subcommands)
            if(execvp(argv[0], argv) != 0){          //otherwise, try to run command from any PATH env var location
                printf("command not found");       //notify if command not found
            }
        }
        perror("cannot execute command");   //if exec() didn't succed and exit you had a problem so complain
        exit(1);                            //exit and signify failure
    
    } else {                                //otherwise you're the parent process
        wait(NULL);                         //wait for the child to complete it's execution to continue here
        signal(SIGINT, SIG_DFL);            //reset system so child signals have default interrupt behavior
        signal(SIGQUIT, SIG_DFL);           //reset system so child signals have default stop behavior  
    }
    return 0;                               //indicate successful completion
}
