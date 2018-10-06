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
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#include "myshell.h"



int main(){
    
	char cwd[256];
    const char *new_value = getcwd(cwd, sizeof(cwd));
    setenv("SHELL", new_value, 1);
    
    char *cmdin, **arglist;

    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    
    doheader();         //clean console and do intro wording for UI
    while ((cmdin = next_cmd(stdin)) != NULL){
        if ((arglist = splitline(cmdin)) != NULL){
            if (strcmp((const char *)arglist[0], "myquit") == 0){
                exit(0);
            }else{
                execute(arglist);
                freelist(arglist);
            }
        }
    }
    return 0;
}



