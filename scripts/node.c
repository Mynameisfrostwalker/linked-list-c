/*
* Node module
*/
#include "header.h"

static NODE *head_ptr = NULL;

int private_list_size(void);

void main_interface(int ch) {
    switch (ch) {
        case 'a':
            list_node_append();
            break;
        case 'd':
            list_node_delete();
            break;
        case 'p':
            list_node_print();
            break;
        case 'r':
            list_node_prepend();
            break;
        case 's':
            list_size();
            break;
        case 'h':
            list_head();
            break;  
        case 't':
            list_tail();
            break;
        case 'z':
            list_at();
            break;
        case 'o':
            list_pop();
            break;
        case 'c':
            list_contains();
            break;
        case 'f':
            list_find();
            break;
        case 'i':
            list_insert_at();
            break;
        case 'w':
            list_node_write();
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

void list_node_append(void) {
    NODE *new_ptr, *ptr;

    new_ptr = list_node_create();
    printf("Enter name and ID\n");
    scanf("%s%lu", new_ptr->name, &(new_ptr->id));

    if(head_ptr == NULL) {
        head_ptr = new_ptr;
    } else {
        for (ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr);
        ptr->next_ptr = new_ptr;
    }
}

void list_node_prepend(void) {
    NODE *new_ptr;

    new_ptr = list_node_create();
    printf("Enter name and ID\n");
    scanf("%s%ld", new_ptr->name, &(new_ptr->id));

    if(head_ptr == NULL) {
        head_ptr = new_ptr;
    } else {
        new_ptr->next_ptr = head_ptr;
        head_ptr = new_ptr;
    }
}

int private_list_size(void) {
    if(head_ptr == NULL) {
        return 0;
    } else {
    NODE *ptr;
        int counter = 1;
        for (ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {
            counter++;
        }

        return counter;
    }
}


void list_size(void) {
    if(head_ptr == NULL) {
        printf("List size is 0\n");
    } else {
    NODE *ptr;
        int counter = 1;
        for (ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {
            counter++;
        }
        printf("List size is: %d\n", counter);
    }
}

void list_head(void) {
    if (head_ptr == NULL) {
        printf("No node in list\n");
    } else {
        printf("Name at Head Node: %s\n", head_ptr->name);
        printf("ID at Head Node: %lu\n", head_ptr->id);
    }
}

void list_tail(void) {
    if (head_ptr == NULL) {
        printf("No node in list\n");
    } else {
        NODE *ptr;
        for (ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr);
        printf("Name at tail Node: %s\n", ptr->name);
        printf("ID at tail Node: %lu\n", ptr->id);
    }
}

void list_at(void) {
    int index;
    printf("Enter index of Node\n");
    scanf("%d", &index);

    if (head_ptr == NULL) {
        printf("No node in list\n");
        return;
    }
    if(private_list_size() < index) {
        printf("Index is too large, only %d nodes in list\n", private_list_size());
        return;
    }
    NODE *ptr = head_ptr;
    int counter = 1;
    while (counter < index) {
        ptr = ptr->next_ptr;
        counter++;
    }
    printf("Name at node %d: %s\n", index, ptr->name);
    printf("ID at node %d: %lu\n", index, ptr->id);
}

void list_pop(void) {
    NODE *lastNode_ptr;
    if (head_ptr == NULL) {
        printf("Sorry, nothing to delete\n");
    } else if (head_ptr->next_ptr == NULL) {
        lastNode_ptr = head_ptr;
        head_ptr = NULL;
        free(lastNode_ptr);
    } else {
        NODE *ptr = head_ptr;
        int counter = 1;
        while(counter < private_list_size() - 1) {
            ptr = ptr->next_ptr;
            counter++;
        }
        lastNode_ptr = ptr->next_ptr;
        ptr->next_ptr = NULL;
        free(lastNode_ptr);
    }

    if(head_ptr == NULL) {
        printf("All nodes have been deleted\n");
    }
}

void list_contains(void) {
    if (head_ptr == NULL) {
        printf("No node in list\n");
        return;
    }

    char name[MAX_LENGTH];
    unsigned long id;
    int exists = 0;

    printf("Enter name and ID you are searching for\n");
    scanf("%s%lu", name, &id);
    NODE *ptr = head_ptr;
    int counter = 1;
    while(counter <= private_list_size()) {
        if(ptr->id == id && strcmp(ptr->name, name) == 0) {
            printf("Node with name %s and ID %lu exists\n", name, id);
            exists = 1;
            counter = private_list_size();
        }
        ptr = ptr->next_ptr;
        counter++;
    }

    if(exists == 0) {
        printf("No node with name %s and ID %lu exists\n", name, id);
    }
}

void list_find(void) {
    if (head_ptr == NULL) {
        printf("No node in list\n");
        return;
    }

    char name[MAX_LENGTH];
    unsigned long id;
    int exists = 0;

    printf("Enter name and ID you are searching for\n");
    scanf("%s%lu", name, &id);
    NODE *ptr = head_ptr;
    int counter = 1;
    while(counter <= private_list_size()) {
        if(ptr->id == id && strcmp(ptr->name, name) == 0) {
            printf("Node with name %s and ID %lu has an index of: %d\n", name, id, counter);
            exists = 1;
            counter = private_list_size();
        }
        ptr = ptr->next_ptr;
        counter++;
    }

    if(exists == 0) {
        printf("No node with name %s and ID %lu exists\n", name, id);
    }
}

void list_insert_at(void) {
    int index;
    printf("Enter index of node\n");
    scanf("%d", &index);

    if(index > private_list_size()) {
        list_node_append();
    }else if(index <= 1) {
        list_node_prepend();
    }else {
        NODE *new_ptr, *ptr;

        new_ptr = list_node_create();
        printf("Enter name and ID\n");
        scanf("%s%ld", new_ptr->name, &(new_ptr->id));

        int counter = 2;
        ptr = head_ptr;
        while (counter < index) {
            ptr = ptr->next_ptr;
            counter++;
        }

        new_ptr->next_ptr = ptr->next_ptr;
        ptr->next_ptr = new_ptr;
    }
}

void list_node_delete(void) {
    NODE *lastNode_ptr;
    int index;
    if (head_ptr == NULL) {
        printf("Sorry, nothing to delete\n");
    } else {
        printf("Enter index of node to delete\n");
        scanf("%d", &index);
        if(index > private_list_size()) {
            list_pop();
        } else if (index == 1) {
            NODE *ptr_tmp;
            ptr_tmp = head_ptr;
            head_ptr = head_ptr->next_ptr;
            free(ptr_tmp);
        } else if (index > 1) {
            NODE *ptr = head_ptr;
            int counter = 1;
            while(counter < index - 1) {
                ptr = ptr->next_ptr;
                counter++;
            }
            lastNode_ptr = ptr->next_ptr;
            ptr->next_ptr = lastNode_ptr->next_ptr;
            free(lastNode_ptr);
        } else {
            printf("Cannot find node at index %d\n", index);
        }
    }

    if(head_ptr == NULL) {
        printf("All nodes have been deleted\n");
    }
}

void list_node_print(void) {
    NODE *ptr;

    if(head_ptr == NULL) {
        printf("Sorry, nothing to print\n");
    } else {
        printf("The contents of the linked list:\n");
        for(ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {
            printf("%s:%lu -> ", ptr->name, ptr->id);
        }

        printf("%s:%lu ->|\n", ptr->name, ptr->id);
    }
}

void list_node_write(void) {
    FILE *fptr;
    NODE *ptr;
    char filename[] = "linked-list.txt";

    if((fptr = fopen(filename, "w+")) == NULL){
        errorExit("Couldn't open file for writing");
    } else {

        if(head_ptr == NULL) {
            fprintf(fptr, "Sorry, nothing to print\n");
        } else {
            fprintf(fptr, "The contents of the linked list:\n");

            fprintf(fptr, "            Name   |   ID\n");
            fprintf(fptr, "------------------------------\n");
            for(ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {
                fprintf(fptr, "%-16s   |   %10lu\n", ptr->name, ptr->id);
                fprintf(fptr, "------------------------------\n");
            }

            fprintf(fptr, "%-16s   |   %10lu\n", ptr->name, ptr->id);
            fprintf(fptr, "------------------------------\n");
        }
    }
    printf("Contents of linked list has been written to %s\n", filename);
    fclose(fptr);
}

void list_node_free(void) {
    NODE *ptr, *ptr_saved;

    for(ptr = head_ptr; ptr != NULL;) {
        ptr_saved = ptr->next_ptr;
        free(ptr);
        ptr = ptr_saved;
    }
}

void errorExit(char *str) {
    printf("%s\n", str);
    exit(ERR_FLAG);
}
