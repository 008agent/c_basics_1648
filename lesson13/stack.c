#include "stack.h"
#include <malloc.h>

struct stack *stack_new(void)
{
    struct stack *st_new = (struct stack *)malloc(sizeof(struct stack));
    if(!st_new) {
        return NULL;
    }

    st_new->data = (int *)malloc(sizeof(int) * STACK_DEF_SIZE);
    if (!st_new->data) {
        free(st_new);
        return NULL;
    }

    st_new->size = STACK_DEF_SIZE;
    st_new->sp = 0;

    return st_new;
}


void stack_free(struct stack **st)
{
    struct stack *st_tmp = *st;
    
    if (st_tmp->data) {
        free(st_tmp->data);
    }

    free(*st);
    *st = NULL;
}


void stack_push(struct stack *st, int value)
{
    if (!st) {
        printf("Stack ptr NULL\n");
        return;
    }

    if (st->sp+1 == st->size) {
        st->size *= 2;
        st->data = (int *)realloc(st->data, sizeof(int) * st->size);
        printf("Stack realloc to %d\n", st->size);
    }

    st->data[st->sp++] = value;
}


bool stack_pop(struct stack *st, int *out_value)
{
    if (st->sp == 0) {
        return false;
    }

    *out_value = st->data[--st->sp];
    return true;
}