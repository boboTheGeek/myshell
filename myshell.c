/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include  <sys/wait.h>

#include "myshell.h"


void clear() {
    printf("\033[H\033[J");   //clear function that erases the screen
}

void executeExternal();

int main(){
	
    doheader();         //clean console and do intro wording for UI
    
    char usrIn[128];    //need to resolve possible buffer overflow
    
    while (strcmp((const char *)usrIn, "myquit") != 0){
        
        doprompt();

        scanf("%s", usrIn);
        
        if (strcmp((const char *)usrIn, "mycd") == 0){
            cd();
        } else if (strcmp((const char *)usrIn, "myclear") == 0){
            clear();
        } else if (strcmp((const char *)usrIn, "mydir") == 0){
            dir();
        } else if (strcmp((const char *)usrIn, "myenviron") == 0){
            environm();
        } else if (strcmp((const char *)usrIn, "myhelp") == 0){
            help();
        }  else if (strcmp((const char *)usrIn, "myquit") == 0){
           continue;
        } else {
           pid_t pid;
            if ((pid = fork()) < 0) {        //do normal shell commands in fork
                perror("non-myshell command fork issue\n");
            } else if (pid == 0){
                printf("do %s\n", usrIn);
                executeExternal(usrIn);
            } else {
                wait(NULL);                   //wait for fork() to complete before going on
            }
        }
    }
}



void executeExternal(char *thething[]){
    
    /*char    *arglist[3];

    arglist[0] = thething;
    arglist[1] = NULL;
    arglist[2] = 0 ;

    printf("%s\n", thething);

    execvp( thething , arglist );*/

   char *args[2] = { "./helloworld" ,NULL };
   execvp(args[0], args);
 
}


