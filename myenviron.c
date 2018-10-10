/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>

extern char **environ;         //grab environment variables from OS

int main (){

    char *s = *environ;
    
    for (int i = 1; s; i++) {  //iterate through list and print each
        printf("%s\n", s);
        s = *(environ+i);
    }
    
    return 0;
}
