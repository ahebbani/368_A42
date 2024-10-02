#include "a4.h"

void openWindow (node **head, int window) {
    // Create new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->window = window;

    // Insert node into end of list
    if (head == NULL) new_node->next = NULL;
    else new_node->next = *head;
    *head = new_node;
}

void switchWindow (node **head, int window) {
    // Already at head
    if ((*head)->window == window) return; 

    // Go to the window that needs to be moved up
    node *curr = *head;
    while (curr->next != NULL && curr->next->window != window) curr = curr->next;

    // Move window to the head of the list
    node *temp = curr->next;
    curr->next = curr->next->next;
    temp->next = *head;
    *head = temp;
}

void closeWindow (node **head, int window) {
    // If head is closed
    node *curr = *head;
    if (curr != NULL && curr->window == window) {
        *head = curr->next;
        free(curr);
        return;
    }

    // Go to node to be closed
    node *prev ;
    while (curr->next != NULL && curr->window != window) { 
        prev = curr;
        curr = curr->next;
    }

    // Delete the node
    prev->next = curr->next;
    free(curr);
}