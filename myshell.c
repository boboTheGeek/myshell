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

char *inpuT(FILE *fp) {
    char *buf;
    int bufspace = 0;
    int pos = 0;
    int c;

    while ((c = getc(fp)) != EOF) {
        // need space ?
        if (pos + 1 >= bufspace) {
            if (bufspace == 0)
                buf = emalloc(BUFSIZ);
            else
                buf = erealloc(buf, bufspace + BUFSIZ);     //BUFSIZ set in stdio.h
            bufspace += BUFSIZ;
        }
        
        // end of command?
        if (c == '\n')
            break;
        
        // no, add to buffer
        buf[pos++] = c;
    }
    if (c == EOF && pos == 0)
        return NULL;
    buf[pos] = '\0';
    return buf;
}



int main(){
    
    char *cmdin, **arglist;
    //const char *ovrrdnCMDs[7] = { "cd", "quit", "echo", "ls", "env", "clear", "help" };         //commands that will be overridden

	char shellwd[255];
    const char *shell_loc = getcwd(shellwd, sizeof(shellwd));   //grab shell startup directory
    setenv("SHELL", shell_loc, 1);                               //set SHELL environment variable to it
    signal(SIGINT, SIG_DFL);                                      //reset system signals to default behaviours: quit, interrupt
    signal(SIGQUIT, SIG_DFL);

    doheader();                                                   //clean console and do intro wording for UI
    
    while ((cmdin = next_cmd(stdin)) != NULL){
        if ((arglist = splitline(cmdin)) != NULL){                //create propmt and grab user input
            /*for (int i = 0; i < 7; i++){
                if (strcmp((const char *)arglist[0], ovrrdnCMDs[i]) == 0){
                    printf("command disabled, try one of: \n");
                    printf("***commands: mycd, myclear, mydir, myenviron, myecho, myhelp, mypause, myquit\n");
                    printf("***if you're interested in help at this point, type 'myhelp'\n");
                    continue;
                }
            }*/
            
            if (strcmp((const char *)arglist[0], "myquit") == 0){  //quit myshell if myquit is called
                exit(0);
            }else if (strcmp((const char *)arglist[0], "mycd") == 0){  //special case for change directory request
                mcd(arglist);
            }else if (strcmp((const char *)arglist[0], "myecho") == 0){ //special case for echo request
                arglist[0] = "myecho";
                arglist[1] = cmdin;
                execute(arglist, shell_loc);
            }else{
                execute(arglist, shell_loc);
                //freelist(arglist);
            }
        }
        
    }
    return 0;
}



