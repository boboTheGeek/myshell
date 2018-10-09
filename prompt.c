/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#include "myshell.h"

char *doprompt(char *prompt){        //username and PWD right before user input
    /******    pattern borrowed from a stack overflow post  */
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
