#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
};


void printLinkedList(struct node *head) {
    struct node * actualNode;
    actualNode = head;
    while(actualNode != NULL) {
        printf("%d -> ", actualNode->data);
        actualNode = actualNode->next;
    }
    printf("NULL \n");
}


/*  INSERCION AL COMIENZO DE LA LISTA   */
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("No se pudo asignar memoria para el nuevo nodo.\n");
    }

    // Configurar los datos del nuevo nodo
    newNode->data = data;
    newNode->next = *head; // El nuevo nodo apunta al antiguo nodo del comienzo

    // El nuevo nodo se convierte en el nuevo inicio de la lista
    *head = newNode;
}

/*  INSERCION AL FINAL DE LA LISTA     */
void insertAtEnd(struct node** head, int data) {
    // Crear un nuevo nodo
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("No se pudo asignar memoria para el nuevo nodo.\n");
    }

    // Configurar los datos del nuevo nodo
    newNode->data = data;
    newNode->next = NULL;  // El nuevo nodo será el último, por lo que su 'next' apunta a NULL

    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista
    if(*head == NULL) {
        *head = newNode;
    } else {
        // Encontrar el último nodo en la lista
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Conectar el último nodo al nuevo nodo
        current->next = newNode;
    }
}


/*  INSERTAR ENTRE DOS ELEMENTOS DE LA LISTA    */
void insertBetween(struct node** head, int prevData, int newData) {
    // Crear un nuevo nodo
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("No se pudo asignar memoria para el nuevo nodo.\n");
    }
    newNode->data = newData;

    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista
    if(*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Buscar el nodo con prevData
    struct node* current = *head;
    while(current != NULL && current->data != prevData) {
        current = current->next;
    }

    if(current == NULL) {
        // Si no se encontró prevData, el nuevo nodo se agrega al final de la lista
        newNode->next = NULL;
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    } else {
        // El nuevo nodo se agrega entre current y su siguiente nodo
        newNode->next = current->next;
        current->next = newNode;
    }
}

/*  BUSQUEDA DE UN ELEMENTO   */
struct node* searchElement(struct node* head, int target) {
    struct node* current = head;

    while(current != NULL) {
        if(current->data == target) {
            return current; // Se encontró el elemento, se devuelve el nodo actual
        }
        current = current->next;
    }

    return NULL; // El elemento no se encontró en la lista
}

/*  ELIMINACION DE LA LISTA   */
struct node *deleteLinkedList(struct node *head) {
    struct node *actualNode;
    while(head != NULL) {
        actualNode = head;
        head = head->next;
        free(actualNode);
    }
    return head;
}


/* GUARDAR LA LISTA EN UN ARCHIVO  */
void saveListToFile(struct node* head, const char *filename) {
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    struct node* current = head;
    while(current != NULL) {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }

    fclose(file);
    printf("Lista guardada en el archivo '%s'.\n\n", filename);
}