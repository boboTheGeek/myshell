/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>

int main(int argc, char *echoString[]){

    for (int i= 1; i <= sizeof(*echoString); i++){    //grab the input and iterate through
        printf("%s ", echoString[i]);                  //printing strings
    }
    
    printf("\n");              //  newline
    
    return 0;
    
}

