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

int main (int argc, char *argv[]){
    char cwd[256];
    if (argc > 2){                           //scold if too many args
        printf("can only use 1 directory argument\n");
        exit(1);
    } else if (argc == 2) {                  //change dir to target
        if (chdir(argv[1]) != 0) {
            perror("chdir() to <path> failed");
        } else {
            if (getcwd(cwd, sizeof(cwd)) == NULL)
                perror("getcwd() error");
            else
                printf("current working directory is: %s\n", cwd);
        }
    } else {
        chdir("/bin");
    }
    
    return 0;
}
