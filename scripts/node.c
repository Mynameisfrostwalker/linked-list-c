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
