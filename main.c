#include "a4.h"
#include <string.h>

int main (int argc, char **argv) {

    // Create list
    node *head = NULL;

    // Variables
    char command[10];
    int window;

    do {
        // Read input
        scanf("%s %d", command, &window);

        // Do
        if (strcmp(command, "open") == 0) openWindow(&head, window);
        else if (strcmp(command, "switch") == 0) switchWindow(&head, window);
        else if (strcmp(command, "close") == 0) closeWindow(&head, window);

        // Debugging
        else printf("Invalid command.");
        node *curr = head;
        printf("[");
        while (curr != NULL){
            printf("%d", curr->window);
            curr = curr->next;
            if (curr != NULL) printf(", ");
        }
        printf("]\n");

        // Print output
        if (head != NULL) printf("%d\n", head->window);

    } while (head != NULL);

    // Done
    return 0;
}