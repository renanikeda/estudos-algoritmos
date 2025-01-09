#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


List *createList(Node *head) {
	List *list = (List *)malloc(sizeof(List));
	list->head = head;
	return list;
}

Node *createNode(int value) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

List* generateList(int values[], int len) {
	List *list = createList(NULL);
    for(int i = len -1; i >= 0; i--) addNode(list, values[i]);
}

void addNode(List *list, int value)  {
	Node *node = createNode(value);
	node->next = list->head;
	list->head = node;
}

Node* getTail(List *list) {
    Node *prev = list->head;
    Node *curr = list->head;
    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    return prev;
}

void pushNode(List *list, int value) {  
    Node *node = createNode(value);
    Node *tail = getTail(list);
    if (tail == NULL) {
        list->head = node;
    } else {
        tail->next = node;
    }
}

void deleteList(List *list) {
	Node *current = list->head;
	while (current != NULL) {
		Node *temp = current;
		printf("Deleting Node %d\n", temp->value);
        current = current->next;
		free(temp);
    }
	list->head = NULL;
}

void deleteNodeByValue(List *list, int value) {
    if (list->head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Node with value %d not found.\n", value);
}

void deleteNode(List *list, Node *node) {
    if (list->head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (current == node) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            printf("Node with value %d deleted.\n", current->value);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Node with value %d not found.\n", node->value);
}

Node* findNode(List *list, int value) {
	Node *current = list->head;
	while (current != NULL) {
        if (current->value == value) return current;
        current = current->next;
    }
}


void swapNodesByValue(List *list, int value1, int value2) {
    if (list->head == NULL) {
        printf("The list is empty. Cannot swap.\n");
        return;
    }
    Node *node1 = findNode(list, value1);
    Node *node2 = findNode(list, value2);

    swapNodes(list, node1, node2);

}

void swapNodes(List *list, Node *node1, Node *node2) {
    if (node1 == NULL || node2 == NULL) {
        printf("One or both nodes not found; cannot swap.\n");
        return;
    }
    Node *current = list->head;
    Node *previous = NULL;
    
    while (current != NULL) {
        printNode(current);
        if (current == node1) {
            if (previous != NULL) { 
                previous->next = node2;
            } else {
                list->head = node2;
            }
        } else if (current == node2) {
            if (previous != NULL) { 
                previous->next = node1;
            } else {
                list->head = node1;
            }
        }
        previous = current;
        current = current->next;
    }

    Node *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

}

List* cloneList(List *list) {
    List *new_list = createList(NULL);
    Node *head = list->head;
    while(head != NULL) {
        pushNode(new_list, head->value);
        head = head->next;
    }
    return new_list;
}

void printList(List *list) {
	if (list->head == NULL) {
        printf("Empty list\n");
        return;
    }
	Node *current = list->head;
	printf("HEAD -> ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
    return;
}

void printNode(Node *node) {
	if (node == NULL) return;
	printf("Node: %d\n", node->value);
}

List* testInstanceList() {
    int values[] = {0, 1, 2, 3, 4, 5};
    int len = sizeof(values) / sizeof(values[0]);
	List *list = generateList(values, len);
	return list;
}

void testAdd() {
	List *list = testInstanceList();
	printList(list);
};

void testDeleteNode() {
	List *list = testInstanceList();
	printList(list);
	Node *nodeToDelete = list->head->next;
	printNode(nodeToDelete);
	deleteNode(list, nodeToDelete);
	printList(list);
	deleteNodeByValue(list, 20);
	printList(list);
};

void testSwap() {
    List *list = testInstanceList();
    printList(list);
	swapNodesByValue(list, 30, 20);
    printList(list);
}

void testClone() {
    List *list = testInstanceList();
    printList(list);
    List *new_list = cloneList(list);
    printList(new_list);
}

int main() {
	testClone();
}
