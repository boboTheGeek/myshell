/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#include "myshell.h"

char *doprompt(char *prompt){        //username and PWD right before user input
                            /******    pattern borrowed from IEEE manpage  */
                            //http://pubs.opengroup.org/onlinepubs/9699919799/functions/getcwd.html
    size_t size;
    char *buf;
    char *ptr;
    long path_max;
    path_max = pathconf(".", _PC_PATH_MAX);  //check the characteristics of "."
    
    if (path_max == -1){             //if the pathconf isn't valid
        size = 1024;                 //use this size
    } else if (path_max > 10240){    //or if it's really big  
        size = 10240;                //limit
    } else {
        size = path_max;             //or use it if it looks normal
    }
    
    for (buf = ptr = NULL; ptr == NULL; size *= 2)
    {
        if ((buf = realloc(buf, size)) == NULL) {  //allocate space according to expected size
            printf("warning\n");      //complain if that doesn't work
        }
        
        ptr = getcwd(buf, size);     //grab the directory
        
         if(ptr == NULL) {           //complain if it returns nothing useful
             printf("warning: couldn't grab current directory location.\n");
         }
    }
    return buf;                      //pass back the value and free buffer
    free (buf);
}
