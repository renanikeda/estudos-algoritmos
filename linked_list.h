// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Node structure
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// List structure
typedef struct List {
    Node *head;
} List;

// Function prototypes
List *createList(Node *head);
Node *createNode(int value);
List *generateList(int values[], int len);
void addNode(List *list, int value);
void deleteList(List *list);
void deleteNodeByValue(List *list, int value);
void deleteNode(List *list, Node *node);
Node *findNode(List *list, int value);
void swapNodesByValue(List *list, int value1, int value2);
void swapNodes(List *list, Node *node1, Node *node2);
void printList(List *list);
void printNode(Node *node);

// Test functions
List *testInstanceList();
void testAdd();
void testDeleteNode();
void testSwap();

#endif // LINKED_LIST_H
