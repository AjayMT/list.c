
#include <stdlib.h>

#include "list.h"

// Get a node for a specific index
static list *index (list *l, int i)
{
    for (; i > 0; i--)
        l = l->next;

    return l;
}

// memcpy
static void copy (char *dst, char *src)
{
    char *a = dst, *b = src;
    for (; (b - src) < sizeof(src); *a = *b, a++, b++);
}

// Create a new list
list *list_new ()
{
    list *l = malloc(sizeof(list));
    l->val = 0;
    l->next = 0;

    return l;
}

// Get an item at an index
char *list_get (list *l, int i)
{
    l = index(l, i);
    char *val = malloc(sizeof(l->val));
    copy(val, l->val);

    return val;
}

// Append an item
void list_add (list *l, char *val)
{
    while ((int)(l->next) != 0) l = l->next;

    list *new = list_new();
    new->val = malloc(sizeof(val));
    copy(new->val, val);

    if ((int)(l->val) == 0) {
	l->val = malloc(sizeof(val));
	copy(l->val, new->val);
        list_free(new);
    } else l->next = new;
}

// Set an item at an index
void list_set (list *l, int i, char *val)
{
    l = index(l, i);
    free(l->val);
    l->val = malloc(sizeof(val));
    copy(l->val, val);
}

// Free a list
void list_free (list *l)
{
    if ((int)(l->next) != 0)
        list_free(l->next);

    if ((int)(l->val) != 0)
        free(l->val);

    free(l);
}
