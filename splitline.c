
/***************************************************************************************
 *    Title: Understanding Unix/Linux Programming - chapter 9
 *    Author: Bruce Molay
 *    Date: 2003
 *    Code version: small-shell version 4
 *    Availability: http://wps.prenhall.com/esm_molay_UNIXProg_1/
 *
 ***************************************************************************************/




/**
 * command reading and parsing functions for smsh
 * char *next_cmd() - get next command
 * char **splitline(char *) - parse a string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myshell.h"

void fatal(char *s1, char *s2, int n) {
    fprintf(stderr, "Error: %s, %s\n", s1, s2);
    exit(n);
}

/**
 * purpose: read next command line from fp
 * returns: dynamically allocated string holding command line
 * errors: NULL at EOF
 *         calls fatal()
 * notes: allocates space in BUFSIZ chunks
 */

char *next_cmd(FILE *fp) {
    char *buf;
    int bufspace = 0;
    int pos = 0;
    int c;
    
    printf("myShell~%s$ ", doprompt());
    while ((c = getc(fp)) != EOF) {
        // need space ?
        if (pos + 1 >= bufspace) {
            if (bufspace == 0)
                buf = emalloc(BUFSIZ);
            else
                buf = erealloc(buf, bufspace + BUFSIZ);     //BUFSIZ set in stdio.h
            bufspace += BUFSIZ;
        }
        
        // end of command?
        if (c == '\n')
            break;
        
        // no, add to buffer
        buf[pos++] = c;
    }
    if (c == EOF && pos == 0)
        return NULL;
    buf[pos] = '\0';
    return buf;
}

#define is_delim(x) ((x) == ' ' || (x) == '\t')

/**
 * purpose: split a line into array of white-space separated tokens
 * returns: a NULL-terminated array of pointers to copies of the
 *          tokens or NULL if line if no tokens on the line
 * action: traverse the array, locate strings, make copies
 * note: strtok() could work, but we may want to add quotes later
 */

char ** splitline(char *line) {
    char *newstr();
    char **args;
    int spots = 0;
    int bufspace = 0;
    int argnum = 0;
    char *cp = line;
    char *start;
    int len;
    
    if (line == NULL)
        return NULL;
    
    args = emalloc(BUFSIZ);
    bufspace = BUFSIZ;
    spots = BUFSIZ / sizeof(char *);
    
    while (*cp != '\0') {
        while (is_delim(*cp))
            cp++;
        if (*cp == '\0')
            break;
        
        // make sure the array has romm (+ 1 for NULL)
        if (argnum + 1 >= spots) {
            args = erealloc(args, bufspace + BUFSIZ);
            bufspace += BUFSIZ;
            spots += (BUFSIZ / sizeof(char *));
        }
        
        // mark start, then find end of word
        start = cp;
        len = 1;
        while (*++cp != '\0' && !(is_delim(*cp)))
            len++;
        
        args[argnum++] = newstr(start, len);
    }
    args[argnum] = NULL;
    return args;
}

/**
 * purpose: constructor for strings
 * returns: a string, never NULL
 */
char *newstr(char *s, int len) {
    char *rv = emalloc(len + 1);
    
    rv[len] = '\0';
    strncpy(rv, s, len);
    return rv;
}

/**
 * purpose: free the list returned by splitline
 * returns: nothing
 * action: free all strings in list and then free the list
 */
void freelist(char **list) {
    char **cp = list;
    while (*cp)
        free(*cp++);
    free(list);
}

void *emalloc(size_t n) {
    void *rv;
    if ((rv = malloc(n)) == NULL)
        fatal("out of memory", "", 1);
    return rv;
}

void *erealloc(void *p, size_t n) {
    void *rv;
    if ((rv = realloc(p, n)) == NULL)
        fatal("realloc() failed", "", 1);
    return rv;
}
