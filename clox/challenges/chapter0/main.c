#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
struct Node{
	Node* next;
	Node* previous;
	int value;
};

Node createNode(Node* next, Node* previous, int value){
	Node newNode = {next, previous, value};
	return newNode;
}

int getListLength(Node* head){
	Node* current = head;
	int length = 0;

	while(current != NULL){
		length++;
		current = current->next;
	}

	return length;
}


void printList(Node* head){
	Node* current = head;
	for(; current != NULL; current=current->next)
		printf("%i ",current->value);
	
}

void insert(Node* head, Node* toInsert, int index){
	Node* current = head;
	int count = 0;

	while(current->next != NULL && count != index-1){
		count++;
		current = current->next;
	}

	toInsert->next = current->next;
	current->next = toInsert;
	toInsert->previous = current;	
}

int main(){
	Node list = {NULL, NULL, 1};
	Node* head = &list;

	Node node[20] = {};
	for(int i = 0; i < 20; i++){
		node[i] = createNode(NULL, NULL, i);
		insert(head, &node[i], 1);
	}
	
	Node newnode = createNode(NULL, NULL, 101);
	insert(head, &newnode, 5);
	printList(head);
	
	return 0;
}
