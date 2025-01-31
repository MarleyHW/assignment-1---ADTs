//Name: Marley Holt-Williams. This is my code and I did not violate the honor code.
#include <stdio.h>
#include <stdlib.h>
#include "set.h"
typedef struct Node {
    void *data; 
    struct Node *next; 
} Node;
typedef struct Set {
    Node *head; 
    // to check if two elements are equal
    bool (*equals)(void *, void *); 
} Set;
/*
 * Purpose: collect those elements of a set that meet some requirement
 * input:   the set, s, and the requirement, f
 * output:  the collected set
 */
Set *set_collect(Set *s, bool (*f)(void *)) {
    Set *set = set_initialize(s->equals);
    for (Node *node = s->head; node != NULL; node = node->next) {
        if (f(node->data)) {
            set_insert(set, node->data);
        }
    }
    return set;
}
/* 
 * Purpose: iterate over the elements of a set applying a function to every
            element in the set 
 * input:   a set, a function, and up to two additional arguments
 * result:  nothing (other than the side effect of the function)
 */
void set_foreach2(Set *set, void (*function)(void *, void *, void *), void *parm1, void *parm2) {
    Node *node = set->head;
    // function to node data with two additional parameters
    while (node != NULL) {
        function(node->data, parm1, parm2);
        node = node->next;
    }
}
/* 
 * Purpose: iterate over the elements of a set applying a function to every
            element in the set 
 * input:   a set, a function, and up to two additional arguments
 * result:  nothing (other than the side effect of the function)
 */
void set_foreach1(Set *set, void (*function)(void *, void *), void *parm1) {
    Node *node = set->head;
    while (node != NULL) {
        function(node->data, parm1);
        node = node->next;
    }
}
/* 
 * Purpose: iterate over the elements of a set applying a function to every
            element in the set 
 * input:   a set, a function, and up to two additional arguments
 * result:  nothing (other than the side effect of the function)
 */
void set_foreach(Set *set, void (*function)(void *)) {
    Node *node = set->head;
    // iterate until the end of the list
    while (node != NULL) {
        function(node->data);
        node = node->next;
    }
}
/*
 * Purpose: free a set 
 * input:   the set, s
 * output:  nothing (as a side effect the set is freed)
 */
void set_free(Set *s) {
    if (s == NULL) {
        return;
    }
    while (s->head != NULL) {
        // initialize pointer to the start of the list
        Node *node = s->head;
        s->head = node->next;
        free(node);
    }
    free(s);
}
/*
 * Purpose: create a new set
 * input:   functions to compare elements
 * output:  the new set 
 */
Set *set_initialize(bool (*compare_function)(void *, void *)) {
    // allocates memory for a new set
    Set *new_set = (Set *)malloc(sizeof(Set));
    if (new_set == NULL) {
        return NULL;
    }
    new_set->head = NULL;
    new_set->equals = compare_function;
    return new_set;
}
/*
 * Purpose: insert an element into a set
 * input:   the set, s, and the element, e
 * output:  the updated set 
 */
Set *set_insert(Set *s, void *e) {
    if (s == NULL) {
        return NULL;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = e;
    new_node->next = s->head;
    s->head = new_node;
    return s;
}

/*
 * Purpose: intersect two sets
 * input:   the sets s1, and s2 
 *       (that are assumed to have the same compare function)
 * output:  a new set containing the intersections
 */
Set *set_intersection(Set *s1, Set *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    Set *set = set_initialize(s1->equals);
    Node *node = s1->head;
    while (node != NULL) {
        if (set_member(s2, node->data)) {
            set = set_insert(set, node->data);
        }
        node = node->next;
    }
    return set;
}
/*
 * Purpose: determine if a value is in a set
 * input:   the set s, and value e
 * output:  true/false is e is in/not in s
 */
bool set_member(Set *s, void *e) {
    for (Node *node = s->head; node; node = node->next) {
        // returns true if the node matches the element
        if (s->equals(node->data, e)) {
            return true;
        }
    }
    return false;
}
/*
 * Purpose: print a set
 * input:   the set
 * output:  nothing (as a side effect the set is printed);
 */
void set_print(Set *s, void (*print_function)(void *, bool)) {
    Node *node = s->head;
    bool first = true;
    while (node != NULL) {
        print_function(node->data, first);
        if (first) {
            first = false;
        }
        node = node->next;
    }
}
/*
 * Purpose:  compute the union of two sets
 * input:  two sets, s1, and, s2
 * output:   the union of s1 and s2
 */
Set *set_union(Set *s1, Set *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    // initialize a new set with equality comparison 
    tSet set = set_initialize(s1->equals);
    for (Node *node = s1->head; node != NULL; node = node->next) {
        set_insert(set,node->data);
    }
    for (Node *node = s2->head; node != NULL; node = node->next) {
        set_insert(set, node->data);
    }
    return set;
}