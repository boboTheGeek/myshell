/*    CSC521 Operating system
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
    
    char location[255];                   //make absolute location path
    strcpy(location, shell_loc);              //so executibles work after mycd
    strcat(location, "/");
    strcat(location, argv[0]);
    
    
    if (argv[0] == NULL)
        return 0;
    if ((pid = fork()) < 0) {
        perror("fork didn't work");
    } else if (pid == 0) {
        
        signal(SIGINT, SIG_DFL);            //reset system so that signals have default behavior
        signal(SIGQUIT, SIG_DFL);
        setenv("PARENT", shell_loc, 1);    //set env var for parent
       
        if(execv(location, argv) != 0){     //if the binary isn't in ./ then check system
            execvp(argv[0], argv);
        }
        perror("cannot execute command");
        exit(1);
    } else {
        wait(NULL);
    }
    return 0;
}
