/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "myshell.h"

int main(){
    
    char *cmdin, **arglist;
	char shellwd[255];
    const char *shell_loc = getcwd(shellwd, sizeof(shellwd));   //grab shell startup directory
    setenv("SHELL", shell_loc, 1);                               //set SHELL environment variable to it
    signal(SIGINT, SIG_DFL);                                      //reset system signals to default behaviours: quit, interrupt
    signal(SIGQUIT, SIG_DFL);

    doheader();                                                   //clean console and do intro wording for UI
    
    while ((cmdin = next_cmd(stdin)) != NULL){                   //create propmt and grab user input
        if (((arglist = splitline(cmdin)) != NULL)
           && (block_commands(arglist)==0)){                     //block BASH commands we're overriding
            
            if (strcmp((const char *)arglist[0], "myquit") == 0){       //quit myshell if myquit is called
                exit(0);
            }else if (strcmp((const char *)arglist[0], "mycd") == 0){   //special case for change directory request
                mcd(arglist);
            }else if (strcmp((const char *)arglist[0], "mypause") == 0){//special case for pause
                pause();
            }else if (strcmp((const char *)arglist[0], "myecho") == 0){ //special case for echo request
                arglist[0] = "myecho";
                arglist[1] = cmdin;
                execute(arglist, shell_loc);
            }else{
                execute(arglist, shell_loc);
                freelist(arglist);
            }
        free(cmdin);
        }
       
    }
    return 0;
}



