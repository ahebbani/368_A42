#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int window;
    struct _node *next;
} node;

void openWindow(node **head, int window);
void switchWindow(node **head, int window);
void closeWindow(node **head, int window);