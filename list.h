/* list.c */

#include <stdbool.h>

typedef struct sList *tList;


/* purpose: search the list for an element
 * input:   a list, an element, and a function that compares elements
 * result:  the element if found, NULL otherwise
 */
void *list_find(tList l, void *e, bool (*compare)());



/* purpose: apply a one argument function to each element of a list
 * input:   a list and a function
 * result:  nothing
 *
 * Note that an addition parameter is passed to f.  This parameter is true 
 * iff the current element being passed to f is the last element in the 
 * list (The same is done for the other list_foreach functions).
 */
void list_foreach(tList l, void (*f)(void *, bool));



/* purpose: apply one argument a function to each element of a list
 *          along with an additional parameter
 * input:   a list, a function, and an additional parameter
 * result:  nothing
 */
void list_foreach1(tList l, void (*f)(), void *parm);



/* purpose: apply two argument a function to each element of a list
 *          along with two additional parameters
 * input:   a list, a function, and two additional parameters
 * result:  nothing
 */
void list_foreach2(tList l, void (*f)(), void *parm1, void *parm2);



/* purpose: free all memory allocated to the list
 * input:   a list
 * result:  nothing
 */
void list_free(tList l);



/* purpose: create new lists
 * input:   nothing
 * result:  an empty list
 */
tList list_initialize();



/* purpose: add an element to the beginning of a list
 * input:   a list and an element
 * result:  the list [element|list]
 */
tList list_insert_beginning(tList l, void *e);



/* purpose: add an element to the end of a list
 * input:   a list and an element
 * result:  the list with element at the end
 */
tList list_insert_end(tList l, void *e);



/* purpose: check if a list is empty
 * input:   a list
 * result:  true if the list is empty, false otherwise
 */
bool list_isempty(tList l);



/* purpose: check if an element is part of a list
 * input:   a list, the element, and function that compares entries
 * result:  true if compare returns true of one of the elements in the list,
 *          false otherwise
 */
bool list_member(tList l, void * e, bool (*compare)());



/* purpose: remove an element from a list
 * input:   a list, an element, and a function that compares entries
 * result:  the list without the first occurrence of the element
 *          (the list is unchanged if the elements in not in the list);
 */
tList list_remove(tList list, void *element, bool (*compare)(void*, void*));
