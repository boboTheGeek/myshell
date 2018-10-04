/*    CSC521 Operating system
Project1 - A MyShell Program
Programmer:   Rob Miles
Professor:    Dr.    Lee
File Created: September 28, 2018
File Updated: 
*/

#include <stdio.h>
#include <dirent.h> 
#include <sys/types.h>

int dir (){

    struct dirent *dent;  
    DIR *dir = opendir("."); 
  
    if (dir == NULL){                       //check if you can open the file
        printf("Can't open directory" ); 
        return 0; 
    } 
  
    while ((dent = readdir(dir)) != NULL){ //print the contents of directory
            printf("%s\n", dent->d_name); 
	}
  
    closedir(dir);     
    return 0; 
}
