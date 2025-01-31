/* set.h */


/* copyright (c) David Binkley 2025 */

#ifndef _SET
#define _SET

#include <stdbool.h>

typedef struct sSet *tSet;


/*
 * Purpose: collect those elements of a set that meet some requirement
 * input:   the set, s, and the requirement, f
 * output:  the collected set
 */
tSet set_collect(tSet s, bool (*f)(void *));



/* 
 * Purpose: iterate over the elements of a set applying a function to every
            element in the set 
 * input:   a set, a function, and up to two additional arguments
 * result:  nothing (other than the side effect of the function)
 */
void set_foreach2(tSet set, void (*function)(), void *parm1, void *parm2);
void set_foreach1(tSet set, void (*function)(), void *parm1);
void set_foreach(tSet set, void (*function)());



/*
 * Purpose: free a set 
 * input:   the set, s
 * output:  nothing (as a side effect the set is freed)
 */
void set_free(tSet s);



/*
 * Purpose: create a new set
 * input:   functions to compare elements
 * output:  the new set 
 */
tSet set_initialize(bool (*compare_function)(void *, void*));



/*
 * Purpose: insert an element into a set
 * input:   the set, s, and the element, e
 * output:  the updated set 
 */
tSet set_insert(tSet s, void *e);



/*
 * Purpose: intersect two sets
 * input:   the sets s1, and s2 
 *       (that are assumed to have the same compare function)
 * output:  a new set containing the intersections
 */
tSet set_intersection(tSet s1, tSet s2);



/*
 * Purpose: determine if a value is in a set
 * input:   the set s, and value e
 * output:  true/false is e is in/not in s
 */
bool set_member(tSet s, void *e);



/*
 * Purpose: print a set
 * input:   the set
 * output:  nothing (as a side effect the set is printed);
 */
void set_print(tSet s, void (*print_function)(void *, bool));



/*
 * Purpose:  compute the union of two sets
 * input:  two sets, s1, and, s2
 * output:   the union of s1 and s2
 */
tSet set_union(tSet s1, tSet s2);  /* s1 and s2 unchanged */



/* Other possible functions include the following.
 * Consider producing a header comment for each of these funcitons and if you
 * hve time implmeting some of them.
 * tSet    set_copy (tSet); // shallow copy
 * tSet    set_copy_replicating_elements(tSet, void *(*f)()); // deap copy
 *
 * void    set_foreach3(tSet, void (*f)(), void*, void*, void*);
 * void    set_foreach4(tSet, void (*f)(), void*, void*, void*, void*);
 *
 * int     set_isempty(tSet);
 * void*   set_any_member(tSet);
 * void*   set_remove_any(tSet);
 * void*   set_remove(tSet, void*);
 * int     set_equal(tSet, tSet);
 * tSet    set_difference(tSet, tSet);
 * void    set_remove_all_matching(tSet, void*);
 */

#endif

