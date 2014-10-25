
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main (int argc, char *argv[])
{
    list *l = list_new();
    list_add(l, "hello");
    list_add(l, "world");

    printf("%s %s\n", list_get(l, 0), list_get(l, 1));

    list_free(l);

    return 0;
}
