/* main.c - maintain a list of integers using the list ADT */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "misc.h"

static void int_print(void *x, bool last)
{
    int *d = (int*) x;
    printf("%d%s ", *d, (last ? "" : ","));
}


static bool int_compare(void *xa, void *xb)
{
    int *a = (int*) xa;
    int *b = (int*) xb;
    return (*a == *b);
}


int main()
{
    int *item, command;
    tList list = list_initialize ();
    item = (int*) check_malloc(sizeof (int));

    while ((command = getchar()) != EOF)
    {
        if (command == 'b' || command == 'd' || command == 'e' || 
            command == 'm' || command == 'f' || command == 'r')
        {
            if (1 != scanf("%d", item))
              abort1("scanf kinda wanted an int\n");
        }

        switch (command)
        {
            case 'b':    list_insert_beginning(list, item);
                         item = (int*) check_malloc(sizeof (int));
                         break;

            case 'e':    list_insert_end(list, item);
                         item = (int*) check_malloc(sizeof (int));
                         break;

            case 'i':    printf("%s empty", list_isempty(list) ? "" : "not ");
                         break;

            case 'm':    // legacy
            case 'f':    if (list_find(list, item, &int_compare) != NULL)
                              printf("Found\n");
                         else
                              printf("Not Found\n");
                         break;

            case 'p':    list_foreach(list, int_print);
                         printf("\n");
                         break;

            case 'q':    list_free(list);
                         exit(0);

            case 'r':    list_remove(list, item, &int_compare);
                         break;
        }
    }
    return 0;
}
