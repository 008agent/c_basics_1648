#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "stack.h"
#include "list.h"


int main(int argc, char **argv)
{
    clock_t c_start, c_end;

    struct list *l = list_new(0);

    for (int i = 1; i <= 10; i++) {
        list_add(l, i);
    }

    list_print(l);

    struct list *l_find = list_find(l, 20);
    if (l_find) {
        printf("l == 20 found %p\n", l_find);
    }

    l_find = list_get_i(l, 100);
    if (l_find) {
        printf("l[5] found %p %d\n", l_find, l_find->data);
    }

    printf("List length %d\n", list_length(l));

    c_start = clock();
    for (int i = 0; i < 1000; i++) {
        list_add(l, i);
    }

    c_end = clock();
    printf("app time %lu\n", c_end - c_start);


    printf("List length %d\n", list_length(l));

    list_free(&l);


ENDLISTS:

/* 
STACK:
    struct stack *st = stack_new();

    for (int i = 0; i < 10; i++) {
        printf(" %d", i);
        stack_push(st, i);
    }
    printf("\n");

    for (int i = 0; i < 20; i++) {
        int tmp;
        if (stack_pop(st, &tmp)) {
            printf(" %d", tmp);
        }
    }
    printf("\n");
    stack_free(&st);
ENDSTACK:
 */

    return 0;
}