/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <sys/types.h>

int main (int argc, char *argv[]){

    struct dirent *ent;
    DIR *dir = opendir(".");                //set default current directory and open it
    
    if (argc > 2){                           //check if too many arguments given
        printf("can only use 1 directory argument\n");  //scold if too many args
        exit(0);                             //exit with no errors
    
    } else if (argc == 2) {                  //if a target directory is provided
        dir = opendir(argv[1]);              //grab directory argument and open it
    }
    
    if (dir != NULL){						 //provided you have a dir to look for
        while ((ent = readdir(dir)) != NULL){//load direcory data to ent struct
            printf("%s\n", ent->d_name);     //run through the list and print file/dir names
        }

    } else {                                 //otherwise warn that you couldn't open a dir
        printf("Can't open requrested directory");
    } 

    closedir(dir);                           //close the direcotry
    return 0;                                //return indicating successful completion
}
