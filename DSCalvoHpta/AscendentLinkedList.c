#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

struct node {
	int key;
	struct node *next;
};

void printList(struct node *head) {
	
	struct node *actualNode;
	actualNode = head;
	while (actualNode != NULL) {
		printf ("%d -> ", actualNode->key );
		actualNode = actualNode->next;
	}
	printf("NULL \n");
}

struct node *insertIntoAscendentList(struct node * head, int element) {
	
	struct node *newNode, *actualNode, *previousNode;
	
	newNode = (struct node *) malloc(sizeof(struct node));
	newNode ->key = element;
	
	if(head == NULL) {
		newNode->next = head;
		head = newNode;
	} else {
		if(element <= head->key) {
			newNode->next = head;
			head = newNode;
		} else {
			previousNode = head;
			actualNode = head->next;
			
			while((actualNode != NULL) && (actualNode->key < element)) {
				previousNode = actualNode;
				actualNode = actualNode->next;
			}
			
			previousNode->next = newNode;
			newNode->next = actualNode;
		}
	}
	
	return head;
}


struct node *deleteElementIntoAscendentList(struct node *head, int element) {
	
	struct node *actualNode, *previousNode;
	

	if(head == NULL) {
		printf("Empty ascendent list\n");
	} else {
		if(element < head->key) {
			printf("The element %d is not in the ascendent list\n", element);
		} else {
			if(element == head->key) {			
				actualNode = head;
				head = head->next;
				free(actualNode);
			} else {
				previousNode = head;
				actualNode = head->next;
				while((actualNode != NULL) && (actualNode->key < element)) {
					previousNode = actualNode;
					actualNode = actualNode->next;
				}
				
				if(actualNode == NULL)
					printf("The element %d is not in the ascendent list\n", element);
				else {
					if(actualNode->key == element) {
						previousNode->next = actualNode->next;
						free(actualNode);
					} else {
						printf("The element %d is not in the ascendent list\n", element);
					}
				}
			}
		}
	}	
	return head;
}


int main() {
	struct node *head;
	int operation, element;
	
	while(scanf("%d %d", &operation, &element) != EOF) {
		if(operation == 1) {	/* INSERTAR */
			head = insertIntoAscendentList(head, element);
			printList(head);
		} else {
			if(operation == 2) {	/* DELETE */
				head = deleteElementIntoAscendentList(head, element);
				printList(head);
			} else {
				;
			}
		}
	}
	
	return 0;
}
