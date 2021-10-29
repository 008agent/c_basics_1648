#include "list.h"

#include <malloc.h>


struct list *list_new(int value)
{
    struct list *l_new = (struct list *)malloc(sizeof(struct list));
    if(!l_new) {
        return NULL;
    }

    l_new->data = value;
    l_new->next = NULL;
}


void list_add(struct list *list, int value)
{
    while (list->next) {
        list = list->next;
    }

    list->next = list_new(value);
}


void list_print(struct list *list)
{
    while (list) {
        printf("list elem %d ptr %p\n", list->data, list);
        list = list->next;
    }
}


void list_free(struct list **list)
{
    struct list *current = *list;
    struct list *next = current->next;

    while (next) {
        next = current->next;
        free(current);
        current = NULL;
        current = next;
    }

    *list = NULL;
}


struct list *list_find(struct list *list, int value)
{
    while (list) {
        if (list->data == value) {
            return list;
        }
        list = list->next;
    }

    return NULL;
}


struct list *list_get_i(struct list *list, int i)
{
    for (int ctr = 0; ctr < i; ctr ++) {
        if (list->next == NULL) {
            return NULL;
        }
        list = list->next;
    }

    return list;
}


int list_length(struct list *list)
{
    int ctr = 0;
    while (list) {
        ctr++;
        list = list->next;
    }

    return ctr;
}