/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>


int main(int argc, char *echoString[]){
    
    while(echoString){
        printf("%s ", echoString++);
    }
    printf("%s\n", echoString);
    return 0;
    
}

