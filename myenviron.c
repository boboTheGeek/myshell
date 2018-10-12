/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>

extern char **environ;         //grab environment variables from OS

int main (){

    char *s = *environ;        //set up a counter the size of env
    
    for (int i = 1; s; i++) {  //iterate through list of environment variables
        printf("%s\n", s);     //print the value
        s = *(environ+i);      //counter matches the env variable index
    }
    
    return 0;                  //successful completion
}
