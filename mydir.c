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
    DIR *dir = opendir(".");                //set default behavior to current directory in case no args
    
    if (argc > 2){                           //scold if too many args
        printf("can only use 1 directory argument\n");
        exit(1);
    } else if (argc == 2) {                  //grab directory argument and set dir
        dir = opendir(argv[1]);
    }
    
    if (dir != NULL){							//check if you opened the directory
        while ((ent = readdir(dir)) != NULL){        //print the contents of directory
            printf("%s\n", ent->d_name);
        }
    } else {
        printf("Can't open requrested directory");
    } 

    closedir(dir);     
    return 0; 
}
