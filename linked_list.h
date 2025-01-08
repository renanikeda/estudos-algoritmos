#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Structure definitions
typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

// Function declarations
List *createList(Node *head);
Node *createNode(int value);
void addNode(List *list, int value);
void deleteList(List *list);
void deleteNodeByValue(List *list, int value);
void deleteNode(List *list, Node *node);
Node* findNode(List *list, int value);
void swapNodesByValue(List *list, int value1, int value2);
void swapNodes(List *list, Node *node1, Node *node2);
void printList(List *list);
void printNode(Node *node);
List* testInstanceList(void);
void testAdd(void);
void testDeleteNode(void);
void testSwap(void);

#endif // LIST_H