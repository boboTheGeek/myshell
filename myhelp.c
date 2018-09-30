/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include "myshell.h"

int help (){
    int choice;
    
    clrSc();
    printf("======================================================================\n");
    printf("===============================  HELP  ===============================\n");
    printf("This is the help file where you can find out about the various aspects\n");
    printf("that can be called on in the myshell.c application.  \n\n");
    
    printf("0) Everything below\n1) mycd\n2) myclr\n3) mydir\n4) myecho\n");
    printf("5) myenviron\n6) myhelp\n7) mypause\n8) myquit\n");
    printf("Select the number representing what you want help for:");
    scanf("%d", &choice);
    
    switch (choice) {
        case 0:
            printf("all");
            break;
        case 1:
            printf("mycd");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 7:
            printf("7");
            break;
        case 8:
            printf("8");
            break;
            
        default:
            printf("Sorry, not a valid choice.");
            break;
    }
    printf("\n");
    pause();
    return 0;
}

