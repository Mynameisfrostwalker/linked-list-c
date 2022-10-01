#include <stdio.h>
#include <stdlib.h>

#ifndef LNK_LIST_H
#define LNK_LIST_H
#define ERR_FLAG 1
#define MAX_LENGTH 16

struct link_list_struct {
    char name[MAX_LENGTH];
    unsigned long id;
    struct link_list_struct *next_ptr;
};

typedef struct link_list_struct NODE;

NODE *list_node_create(void);
NODE *list_head(void);
void list_node_add(void);
void list_node_prepend(void);
int list_size(void);
int list_node_delete(void);
void list_node_print(void);
void list_node_free(void);
void errorExit(char *);
void main_interface(int);

#endif
