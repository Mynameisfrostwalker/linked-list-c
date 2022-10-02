#include "header.h"

int main(void) {
    int ch;

    printf("\nEnter a for adding, d for deleting\n");
    printf("r to prepend, s for size\n");
    printf("h for head, t for tail\n");
    printf("z to get node at index, o to pop\n");
    printf("c to check if list contains a node, f to find a node\n");
    printf("w to write the linked list to a file, , i to insert a node\n");
    printf("p for printing, and q to exit\n");

    while((ch=getchar()) != 'q') {
        main_interface(ch);
    }

    list_node_free();
    printf("\nBye\n");

    return 0;
}
