/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>

int main(int argc, char *echoString[]){

	printf("%s ", echoString[1] + 7);                  //print string, clip off the front "myecho "
                                                       //since it's part of echoString[1]
    printf("\n");                                      //print a new line before returning
    
    return 0;                                          //return successfully
    
}

