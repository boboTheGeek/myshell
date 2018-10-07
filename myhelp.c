/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

    int choice;
    char *topic[5];
    topic[0] = "less";
    topic[1] = "-d";
    topic[2] = "+/$";
    topic[3] = "README.md";
    topic[4] = NULL;
    
    char *targetTopic= "";
    
    if(argc > 2){
        
        printf("Select only one topic please.\n");
        exit(0);
    
    } else if (argc == 2){
        
        printf("\033[H\033[J");   //clear function that erases the screen
        char intermediate[32];
        strcpy(intermediate, topic[2]);
        strcat(intermediate, argv[1]);
        topic[2] = intermediate;
        
    } else {
        
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
                topic[2] = "+/# myshell";
                break;
            case 1:
                topic[2] = "+/$mycd";
                break;
            case 2:
                topic[2] = "+/$myclr";
                break;
            case 3:
                topic[2] = "+/$mydir";
                break;
            case 4:
                topic[2] = "+/$myecho";
                break;
            case 5:
                topic[2] = "+/$myenviron";
                break;
            case 6:
                topic[2] = "+/$myhelp";
                break;
            case 7:
                topic[2] = "+/$mypause";
                break;
            case 8:
                topic[2] = "+/$myquit";
                break;
                
            default:
                printf("Sorry, not a valid choice.");
                break;
        }
    }
    
    printf("%s", targetTopic);
    execvp("less", topic);
    return 0;
}

