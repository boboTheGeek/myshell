/*    CSC521 Operating system
 Project1 - A MyShell Program
 Programmer:   Rob Miles
 Professor:    Dr.    Lee
 File Created: September 28, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int mcd (char *argv[]){
    char *cwd = NULL;
    int argc = 0;

    while(argv[argc++]!=NULL);              //count the arguments

    if (argc > 3){                           //scold if too many args
        printf("can only use 1 directory argument\n");
        return 1;                           //return unsuccessful
    } else if (argc == 3) {                 //if there are the right number of args
        if (chdir(argv[1]) != 0) {          //try to change directory to arg[1] param
            perror("chdir() to <path> failed");  //if fails then report a problem
        } else {                            //but if it's good
            if ((cwd = getcwd(cwd, sizeof(cwd))) == NULL)  //grab the new (same) working directory
                perror("getcwd() error");  //complain if the verifiction fails
            else {
                setenv("PWD", cwd, 1);      //set environment variable for PWD; overwrite
                printf("current working directory [getcwd()] is: %s,  ", cwd);
                printf("getenv(\"PWD\") is: %s\n", getenv("PWD"));  //print where you now are
            }
        }
    } else {
        printf("no change\n");             //otherwise, you probably didn't enter a location
    }
    return 0;                              //return success
}
