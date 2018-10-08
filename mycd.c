/*    CSC521 Operating system
 Project1 - A MyShell Program
 Programmer:   Rob Miles
 Professor:    Dr.    Lee
 File Created: September 28, 2018
 File Updated:
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int mcd (char *argv[]){
    char *cwd = NULL;
    int argc = 2;   ///testing.........
    if (argc > 2){                           //scold if too many args
        printf("can only use 1 directory argument\n");
        exit(0);
    } else if (argc == 2) {                  //change dir to target
        if (chdir(argv[1]) != 0) {
            perror("chdir() to <path> failed");
        } else {
            if ((cwd = getcwd(cwd, sizeof(cwd))) == NULL)
                perror("getcwd() error");
            else
                setenv("PWD", cwd, 1);      //set environment variable for PWD; overwrite
                printf("current working directory [getcwd()] is: %s,  ", cwd);
                printf("getenv(\"PWD\") is: %s\n", getenv("PWD"));
        }
    } else {
        chdir("/bin");
    }
    
    return 0;
}
