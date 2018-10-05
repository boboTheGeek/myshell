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

void doheader(){    //pint welcome header and user name
    clear();
    printf("\n");
    printf("===========================================================\n");
    printf("=Welcome to myShell.  A shell that is mine and yours too!!=\n");
    printf("===========================================================\n");
    printf("\n");
    printf("***if you're interested in help at this point, type 'myhelp'\n");
    printf("***commands: mycd, myclear, mydir, myenviron, myecho, myhelp, mypause, myquit\n");
    
    char *myUser = getenv("USER");
    printf("Logged in as: ");
    echo(myUser);
    
}


void doprompt(){                   //username and PWD right before user input
    
    size_t size;
    char *buf;
    char *ptr;
    long path_max;

    path_max = pathconf(".", 256);  //check for max path character length
    
    if (path_max == -1){             // make 1024 if problems
        size = 1024;
    }
    else if (path_max > 10240){     //clip
        size = 10240;
    }
    else {
        size = path_max;           //or use it if it looks normal
    }
    
    /******     borrowed from a stack overflow post  */
    for (buf = ptr = NULL; ptr == NULL; size *= 2)
    {
        if ((buf = realloc(buf, size)) == NULL){
            printf("warning\n");
        }
        
        ptr = getcwd(buf, size);   //grab the directory [finally!]
        
         if(ptr == NULL){
             printf("warning: couldn't grab current directory location.\n");
         }
    }

    printf("%s@", getenv("USER"));     //print username
    printf("%s$ ", buf);               //and path on same line
    free (buf);
}