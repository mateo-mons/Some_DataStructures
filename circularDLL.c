#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


struct node {
    int key;
    struct node *prev;
    struct node *next;
};

/* Funcion para insertar elementos en la lista */
struct node *insertElementInCircularDoublyLinkedList(struct node *tail, int element) {
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->key = element;

    if(tail == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        newNode->next->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}


/* Funciona para eliminar cualquier elemento de la lista */
struct node *deleteElementOfCircularDoublyLinkedList(struct node *tail, int element) {
    struct node *actualNode;
    int flag = FALSE;
    if(tail == NULL)
        printf("The circular doubly linked list is empty.\n");
    else {
        actualNode = tail->next;
        while((actualNode != tail) && (flag == FALSE)) {
            if(actualNode->key == element) {
                flag = TRUE;
                break;
            }
            else
                actualNode = actualNode->next;
        }
        if(flag == FALSE) {
            if(tail->key == element) {
                flag = TRUE;
                actualNode = tail;
            }
        }
        if(tail == tail->next) {
            if(flag == TRUE) {
                free(tail);
                tail = NULL;
            }
            else
                printf("The %d is not in the circular doubly linked list.\n", element);
        } else {
            if(flag == FALSE)
                printf("The %d is not in the circular doubly linked list.\n", element);
            else {
                actualNode->next->prev = actualNode->prev;
                actualNode->prev->next = actualNode->next;
                if(actualNode == tail)
                tail = tail->prev;
                free(actualNode);
            }
        }
    }
    return tail;
}


/* Funcion para eliminar el primer elemento de la lista */
struct node *deleteFirstNodeInCircularDoublyLinkedList(struct node *tail) {
    struct node *firstNode;

    if(tail == NULL)
        printf("The circular doubly linked list is empty.\n");
    else {
        if(tail == tail->next) {
            free(tail);
            tail = NULL;
        } else {
            firstNode = tail->next;
            tail->next = firstNode->next;
            tail->next->prev = tail;
            free(firstNode);
        }
    }
    return tail;
}

/* Impresion desde el primer hasta el ultimo elemento */
void printFromFirstToLastCircularDoublyLinkedList(struct node * tail) {
    struct node *actualNode;
    if(tail == NULL) 
        printf("NULL \n");
    else {
        actualNode = tail->next;
        while(actualNode != tail) {
            printf("%d -> ", actualNode -> key);
            actualNode = actualNode->next;
        }
        printf("%d ...\n", tail->key);
    }
}

/* Impresion desde el ultimo hasta el primer elemento */
void printFromLastToFirstCircularDoublyLinkedList(struct node *tail) {
    struct node *actualNode, *firstNode;

    if(tail == NULL)
        printf("NULL\n");
    else {
        actualNode = tail;
        firstNode = tail->next;

        while(actualNode != firstNode) {
            printf("%d -> ", actualNode->key);
            actualNode = actualNode->prev;
        }
        printf("%d ...\n", firstNode->key);
    }
}

/* Funcion principal eliminando el primer elemento de la lista */
/*
int main() {
    struct node *tail;
    int operation, element;

    tail = NULL;

    while(scanf("%d", &operation) != EOF) {
        if(operation == 1) {    // Insert
            scanf("%d", &element);
            tail = insertElementInCircularDoublyLinkedList(tail, element);
            printFromFirstToLastCircularDoublyLinkedList(tail);
            printFromLastToFirstCircularDoublyLinkedList(tail);
        } else {
            if(operation == 2) {   // Delete 
                tail = deleteFirstNodeInCircularDoublyLinkedList(tail);
                printFromFirstToLastCircularDoublyLinkedList(tail);
                printFromLastToFirstCircularDoublyLinkedList(tail);
            }
            else
                printf("Bad use. \n 1. Insert\n 2. Delete\n");
        }
    }

    return 0;
}
*/


/* Funcion principal eliminando cualquier elemento de la lista */
int main() {
    struct node *tail;
    int operation, element;

    tail = NULL;

    while(scanf("%d %d", &operation, &element) != EOF) {
        if(operation == 1) {    // Insert
            tail = insertElementInCircularDoublyLinkedList(tail, element);
            printFromFirstToLastCircularDoublyLinkedList(tail);
            printFromLastToFirstCircularDoublyLinkedList(tail);
        } else {
            if(operation == 2) {    // Delete 
                tail = deleteElementOfCircularDoublyLinkedList(tail, element);
                printFromFirstToLastCircularDoublyLinkedList(tail);
                printFromLastToFirstCircularDoublyLinkedList(tail);
            }
            else
                printf("Bad use. \n 1. Insert\n 2. Delete\n");
        }
    }

    return 0;
}