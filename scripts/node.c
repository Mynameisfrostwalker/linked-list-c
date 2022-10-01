/*
* Node module
*/
#include "header.h"

static NODE *head_ptr = NULL;

void main_interface(int ch) {
    switch (ch) {
        case 'a':
            list_node_add();
            break;
        case 'd':
            if(!(list_node_delete())) {
                list_node_print();
            }
            break;
        case 'p':
            list_node_print();
            break;
        default:
            break;
    }
}

NODE *list_node_create(void) {
    NODE *ptr;

    if((ptr = (NODE *)malloc(sizeof(NODE))) == NULL) {
        errorExit("malloc() failed");
    }

    ptr->next_ptr = NULL;
    ptr->id = 0;
    return ptr;
}

void list_node_add(void) {
    NODE *new_ptr, *ptr;

    new_ptr = list_node_create();
    printf("Enter name and ID");
    scanf("%s%ld", new_ptr->name, &(new_ptr->id));

    if(head_ptr == NULL) {
        head_ptr = new_ptr;
    } else {
        for (ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr);
        ptr->next_ptr = new_ptr;
    }
}

void list_node_prepend(void) {
    NODE *new_ptr, *ptr;

    new_ptr = list_node_create();
    printf("Enter name and ID");
    scanf("%s%ld", new_ptr->name, &(new_ptr->id));

    if(head_ptr == NULL) {
        head_ptr = new_ptr;
    } else {
        new_ptr->next_ptr = head_ptr;
        head_ptr = new_ptr;
    }
}

int list_size(void) {
    if(head_ptr == NULL) {
        return 0;
    }
    NODE *ptr;
    int counter = 0;
    for (ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {
        counter++;
    }
    return counter;
}

NODE *list_head(void) {
    return head_ptr;
}
