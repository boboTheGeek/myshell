
void doheader();
char *doprompt();
int cd();
//int echo(char* echoString);
int quit();

void executeExternal();

char *next_cmd(FILE *fp);

int execute(char *argv[], const char *shell_loc);

void *emalloc(size_t);
void *erealloc(void *, size_t);

char **splitline(char *line);
void freelist(char **list);
