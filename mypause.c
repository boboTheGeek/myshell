/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>

#include "myshell.h"

int pause(){
    int i = 1;
    do {
        printf("press enter to continue");
    } while ((i = getchar()) == 1);
    return 0;
}
