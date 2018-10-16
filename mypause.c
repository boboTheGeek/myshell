/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>

#include "myshell.h"

int main(){
    int i = 1;      //this won't actually store anything since we'll exit 
    do {            //use while loop to queue up your prompt
        printf("press enter to continue");
    } while ((i = getchar()) == 1);  //continue after you see an ENTER
    return 0;       //after you see enter, can close this process successfully
}
