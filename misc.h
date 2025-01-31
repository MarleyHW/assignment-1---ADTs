/* misc.h */

/* copyright (c) David Binkley 2021 */

#define printd      if (DEBUG) printf

#ifndef _MISC
#define _MISC

#ifndef NULL
#define NULL 0
#endif


void abort1(char *);
void *check_malloc(int);
void *check_realloc(void *, int);
#endif

