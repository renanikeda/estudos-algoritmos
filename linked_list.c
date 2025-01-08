#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct List {
	Node *head;
} List;

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

void addNode(List *list, int value)  {
	Node *node = createNode(value);
	node->next = list->head;
	list->head = node;
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

void deleteNode(List *list, int value) {
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

void swapNodes(List *list, int value1, int value2) {
    if (list->head == NULL) {
        printf("The list is empty. Cannot swap.\n");
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (current->value == value1) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Node with value %d deleted.\n", value1);
            return;
        }
        previous = current;
        current = current->next;
    }

}

void printList(List *list) {
	if (list->head == NULL) return;
	Node *current = list->head;
	printf("HEAD -> ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void printNode(Node *node) {
	if (node == NULL) return;
	printf("Node: %d", node->value);
}

List* testInstanceList() {
	List *list = createList(NULL);
	addNode(list, 10);
	addNode(list, 20);
	addNode(list, 30);
	addNode(list, 40);
	return list;
}

void testAdd() {
	List *list = testInstanceList();
	printList(list);
};

void testDelete() {
	List *list = testInstanceList();
	printList(list);
	deleteNode(list, 20);
	printList(list);
};

void testSwap() {
	List *list = testInstanceList();
	printList(list);
}

int main() {
	testSwap();
}
