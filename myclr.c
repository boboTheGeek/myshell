/*    CSC521 Operating system
Project1 - A MyShell Program
Programm/Users/bobby/myshell/myclr.cer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <unistd.h>

void clrScreen()
{
    const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


void clrSc()
{
    const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
