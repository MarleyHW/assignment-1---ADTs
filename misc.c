/* misc.c */

// don't hand this out!

// #include "memwatch.h" // /home/class_projects/memwatch-2.71/
#include <stdlib.h>


static char *cr = "copyright (c) David Binkley 2021";

#include <stdio.h>
#include <stdlib.h>

int abort1(char *s)
{
    fprintf(stderr, "%s\n", s);
    exit(-1);
}


void *check_malloc(int size)
{
    char *cp;
    /*printf("check malloc allocating %d bytes\n", size) ;*/

    cp = malloc(size) ;
    if (cp == NULL)
        abort1("check_malloc: No Core") ;

    return (cp) ;
}


void *check_realloc(void *p, int size)
{
    p = realloc(p, size);
    if (p == NULL)
        abort1("check_realloc: No Core") ;
    return(p);
}