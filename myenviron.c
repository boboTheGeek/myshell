/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>

extern char **environ;

int main (){
    
    
    char *s = *environ;
    
    for (int i = 1; s; i++) {
        printf("%s\n", s);
        s = *(environ+i);
    }
    
    return 0;
}
