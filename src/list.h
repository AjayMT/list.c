
// list.h

#ifndef _LIST_H
#define _LIST_H

typedef struct list_node {
    char *val;
    struct list_node *next;
} list;

list *list_new ();
list *list_range (list *l, int beg, int end);
char *list_get (list *l, int i);
void list_add (list *l, char *val);
void list_set (list *l, int i, char *val);
void list_remove (list *l, int i);
int list_len (list *l);
int list_index_of (list *l, char *val);
void list_free (list *l);

#endif
