
# list.c
list.c is an implementation of a linked list in C.

Example:

```c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (int argc, char *argv[])
{
    list *l = list_new();
    list_add(l, "hello");
    list_add(l, "world");

    char *hello = list_get(l, 0);
    char *world = list_get(l, 1);
    printf("%s %s\n", hello, world);
    free(hello);
    free(world);

    list_free(l);

    return 0;
}
```

Look at `./test.c` for a longer example.

## Installation
With [clib](http://github.com/clibs/clib):

```sh
$ clib install AjayMT/list.c
```

Or `make` it and use the `list.o` file.

## API
### list *list_new()
Create a new list. This function returns a pointer to the list.

### list *list_range(list *l, int beg, int end)
Return a new list containing items from `beg` to `end` (excluding `end`) in `l`.

### char *list_get(list *l, int i)
Return the value at `i` in `l`. You should `free` the value you get.

### void list_add(list *l, char *val)
Append `val` to `l`.

### void list_set(list *l, int i, char *val)
Set the value at `i` to `val` in `l`.

### void list_remove(list *l, int i)
Remove item at `i` in `l`.

### int list_len(list *l)
Return the number of items in `l`.

### int list_index_of(list *l, char *val)
Return the index of `val` in `l`.

### void list_free(list *l)
Free everything in `l`.

## Running tests

```sh
$ make test
```

## License
MIT. See `./LICENSE` for details.
