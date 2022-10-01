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

