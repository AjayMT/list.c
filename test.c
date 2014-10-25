
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main (int argc, char *argv[])
{
    printf("\n");

    list *l = list_new();
    list_add(l, "hello");
    list_add(l, "world");

    char *hello = list_get(l, 0);
    char *world = list_get(l, 1);
    printf("should be 'hello world': %s %s\n", hello, world);
    free(hello);
    free(world);

    list_set(l, 0, "hey");
    hello = list_get(l, 0);
    world = list_get(l, 1);
    printf("should be 'hey world': %s %s\n", hello, world);
    free(hello);
    free(world);

    printf("should be 2: %i\n", list_len(l));

    printf("should be 0: %i\n", list_index_of(l, "hey"));
    printf("should be 1: %i\n", list_index_of(l, "world"));
    printf("should be -1: %i\n", list_index_of(l, "foo"));

    list_remove(l, 0);
    world = list_get(l, 0);
    printf("should be 'world': %s\n", world);
    printf("should be 1: %i\n", list_len(l));
    free(world);

    list_add(l, "foo");
    list_add(l, "bar");
    list *sub = list_range(l, 1, list_len(l));
    printf("should be 'foo bar': ");
    for (int i = 0; i < list_len(sub); i++) {
	char *val = list_get(sub, i);
	printf("%s ", val);
	free(val);
    }
    printf("\n");

    list_free(l);

    printf("\n");

    return 0;
}
