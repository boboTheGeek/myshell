/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("\n\n");
    printf("===========================================================\n");
	printf("Welcome to myShell.  A shell that is mine and yours too!!!!\n");
	printf("===========================================================\n");
    char* myUser = getenv("USER");
    
    printf("User: %s\n", myUser);
    
	printf("\n\n");
	printf("*** if you're interested in help at this point, type 'myhelp' and hit enter.\n");
    
    char h[4];   //need to resolve possible buffer overflow
    scanf("%s", &h);

    
    if (strcmp(h, "myhelp") == 0){
        printf("Helpfile\n");
        scanf("%s", &h);
    }


}
