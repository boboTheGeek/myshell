/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>

extern char **environ;

int environm (){
    
    int i = 1;
    char *s = *environ;
    
    for (; s; i++) {
        printf("%s\n", s);
        s = *(environ+i);
    }
    
    return 0;
}
