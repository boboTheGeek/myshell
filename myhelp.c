/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

    int choice;
    char *topic[4];                //set up args for less command
    topic[0] = "less";             //less used in place of more since it's newer
    topic[1] = "+/### ";
    topic[2] = "README.md";
    topic[3] = NULL;
    
    if(argc > 2){                  //don't allow more than one search term
        
        printf("Select only one topic please.\n");
        exit(0);
    
    } else if (argc == 2){
        
        printf("\033[H\033[J");   //clear function that erases the screen
        char top[32];
        strcpy(top, topic[1]);     //append the input string to pattern prefix
        strcat(top, argv[1]);
        topic[1] = top;
        
    } else {                       //if the user didn't give an arg, bring up a menu to choose from
        
        printf("\033[H\033[J");   //clear function that erases the screen
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
                topic[1] = "+/### myshell";
                break;
            case 1:
                topic[1] = "+/### mycd";
                break;
            case 2:
                topic[1] = "+/### myclear";
                break;
            case 3:
                topic[1] = "+/### mydir";
                break;
            case 4:
                topic[1] = "+/### myecho";
                break;
            case 5:
                topic[1] = "+/### myenviron";
                break;
            case 6:
                topic[1] = "+/### myhelp";
                break;
            case 7:
                topic[1] = "+/### mypause";
                break;
            case 8:
                topic[1] = "+/### myquit";
                break;
            default:
                printf("Sorry, not a valid choice.");
                break;
        }
    }

    execvp("less", topic);         //call myhelp executible and pass args
    return 0;
}

