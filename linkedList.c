#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct node {
    int key;
    struct node *next;
};

struct node *makeLinkedList(int n) {
    struct node *head, *newNode;
    head = NULL;
    while (n >= 1) {
        newNode = (struct node *) malloc(sizeof(struct node));
        newNode->key = n;
        newNode->next = head;
        head = newNode;
        n--;
    }
    return head;
}


void printLinkedList(struct node *head) {
    struct node * actualNode;
    actualNode = head;
    while(actualNode != NULL) {
        printf("%d -> ", actualNode->key);
        actualNode = actualNode->next;
    }
    printf("NULL \n");
}

struct node *deleteLinkedList(struct node *head) {
    struct node *actualNode;
    while (head != NULL) {
        actualNode = head;
        head = head->next;
        free(actualNode);
    }
    return head;
}

int main() {
    struct node *head;
    int n;
    while(scanf("%d", &n) != EOF) {
        head = makeLinkedList(n);
        printLinkedList(head);
        head = deleteLinkedList(head);
        printLinkedList(head);
    }
    return 0;
}