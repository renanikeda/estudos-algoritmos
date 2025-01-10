#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Struct Definitions
typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

// Function Prototypes
List *createList(Node *head);
Node *createNode(int value);
List *generateList(int values[], int len);
void addNode(List *list, int value);
Node *getTail(List *list);
void pushNode(List *list, int value);
void deleteList(List *list);
void deleteNodeByValue(List *list, int value);
void deleteNode(List *list, Node *node);
Node *findNode(List *list, int value);
void swapNodesByValue(List *list, int value1, int value2);
void swapNodes(List *list, Node *node1, Node *node2);
List *cloneList(List *list);
int popList(List *list);
List *invertList(List *list);
void invertListInplace(List *list);
void insertSorted(List *list, int value);
List *sortList(List *list);
void sortListInplace(List *list);
void printList(List *list);
void printNode(Node *node);

// Test Function Prototypes
List *testInstanceList();
void testAdd();
void testDeleteNode();
void testSwap();
void testClone();
void testPop();
void testInvert();
void testInsert();

#endif // LINKED_LIST_H
