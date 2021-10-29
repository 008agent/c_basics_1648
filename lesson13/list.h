#ifndef LIST_H
#define LIST_H

struct list {
    struct list *next;
    int data;
};

struct list *list_new(int value);

void list_add(struct list *list, int value);
void list_print(struct list *list);
void list_free(struct list **list);

struct list *list_find(struct list *list, int value);
struct list *list_get_i(struct list *list, int i);
int list_length(struct list *list);


#endif
