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

void printList(List *list) {
	Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
	List *list = createList(NULL);
	addNode(list, 10);
	addNode(list, 20);
	addNode(list, 30);
	addNode(list, 40);
	printList(list);
}
