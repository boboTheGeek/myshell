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
#include <unistd.h>
#include <string.h>
#include "myshell.h"

void doheader();
void doprompt();

int main(int argc, char *argv[]){
	
    doheader();
    
    char usrIn[128];   //need to resolve possible buffer overflow
    
    while (strcmp((const char *)usrIn, "close") != 0){
        
        doprompt();
        scanf("%s", usrIn);
        
        if (strcmp((const char *)usrIn, "mycd") == 0){
            cd();
        } else if (strcmp((const char *)usrIn, "clear") == 0){
            clrSc();
        } else if (strcmp((const char *)usrIn, "mydir") == 0){
            dir();
        } else if (strcmp((const char *)usrIn, "myenviron") == 0){
            environ();
        } else if (strcmp((const char *)usrIn, "myhelp") == 0){
            help();
        } else if (strcmp((const char *)usrIn, "myquit") == 0){
            quit();
        } else {
            if (execv("/bin/", (char *const *) usrIn) == -1) {        //do normal shell commands
                perror("external command issue\n");
            }
        }
    }
}


void doheader(){
    clrSc();
    printf("\n");
    printf("===========================================================\n");
    printf("=Welcome to myShell.  A shell that is mine and yours too!!=\n");
    printf("===========================================================\n");
    printf("\n");
    printf("***if you're interested in help at this point, type 'myhelp'\n");
    printf("***commands: mycd, clear, mydir, myenviron, myecho, myhelp, mypause, myquit\n");
    
    char* myUser = getenv("USER");
    printf("Logged in as: ");
    echo(myUser);
    
}


void doprompt(){
    char* myUser = getenv("USER");
    printf("%s@", myUser);
    
    long path_max;
    size_t size;
    char *buf;
    char *ptr;
    path_max = pathconf(".", 256);
    if (path_max == -1)
        size = 1024;
    else if (path_max > 10240)
        size = 10240;
    else
        size = path_max;
    
    
    for (buf = ptr = NULL; ptr == NULL; size *= 2)
    {
        if ((buf = realloc(buf, size)) == NULL)
        {
            printf("warning\n");
        }
        
        
        ptr = getcwd(buf, size);
        /*if (ptr == NULL && errno != ERANGE)
         {
         printf("warning\n");
         }*/
    }
    printf("%s$ ", buf);
    free (buf);
}
