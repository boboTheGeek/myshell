/*    CSC521 Operating system
 Project1 - A MyShell Program
 Programmer:   Rob Miles
 Professor:    Dr.    Lee
 File Created: September 28, 2018
 */

//handler.c
void doheader();
int block_commands(char **args);

//prompt.c
char *doprompt();

//mycd.c
int mcd(char *arglist[]);

//splitline.c
char *next_cmd(FILE *fp);
void *emalloc(size_t);
void *erealloc(void *, size_t);
char **splitline(char *line);
void freelist(char **list);

//executer.c
int execute(char *argv[], const char *shell_loc);

//mypause.c
int pause();
