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

#include "myshell.h"

int main(){
    
	char shellwd[255];
    const char *shell_loc = getcwd(shellwd, sizeof(shellwd));
    setenv("SHELL", shell_loc, 1);
    
    char *cmdin, **arglist;
    
    doheader();         //clean console and do intro wording for UI
    while ((cmdin = next_cmd(stdin)) != NULL){
        if ((arglist = splitline(cmdin)) != NULL){
            if (strcmp((const char *)arglist[0], "myquit") == 0){
                exit(0);
            }else{
                execute(arglist, shell_loc);
                freelist(arglist);
            }
        }
    }
    return 0;
}



