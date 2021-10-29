#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_DEF_SIZE 16

struct stack {
    int *data;
    int size;
    int sp;
};

struct stack *stack_new(void);
void stack_free(struct stack **st);
void stack_push(struct stack *st, int value);
bool stack_pop(struct stack *st, int *out_value);


//push,pop


#endif
