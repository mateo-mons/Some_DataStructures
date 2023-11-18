#include <stdio.h>
#include <stdlib.h>


/*   Definición de la estructura de un nodo  */
struct Nodo {
    int data;
    struct Nodo *next;
};

// Función para crear un nuevo nodo
struct Nodo *NuevoNodo(int data) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->data = data;
    nodo->next = NULL;
    return nodo;
}

/*  PILAS DINAMICAS   */

// Definición de la estructura de una pila
struct Pila {
    struct Nodo *top;
};

// Función para inicializar una pila vacía
struct Pila *CrearPila() {
    struct Pila *pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->top = NULL;
    return pila;
}

// Función para verificar si la pila está vacía
int PilaVacia(struct Pila *pila) {
    return(pila->top == NULL);
}

// Función para empujar un elemento a la pila
void push(struct Pila *pila, int data) {
    struct Nodo *nodo = NuevoNodo(data);
    nodo->next = pila->top;
    pila->top = nodo;
}

// Función para sacar un elemento de la pila
int pop(struct Pila* pila) {
    if(PilaVacia(pila)) {
        printf("La pila está vacía.\n");
    }
    struct Nodo* temporal = pila->top;
    int data = temporal->data;
    pila->top = temporal->next;
    free(temporal);
    return data;
}


/*  COLAS DINAMICAS    */

// Definición de la estructura de una cola
struct Cola {
    struct Nodo *front;
    struct Nodo *tail;
};

// Función para inicializar una cola vacía
struct Cola* CrearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->front = cola->tail = NULL;
    return cola;
}

// Función para verificar si la cola está vacía
int ColaVacia(struct Cola *cola) {
    return (cola->front == NULL);
}

// Función para encolar un elemento
void Insertar(struct Cola* cola, int data) {
    struct Nodo *nodo = NuevoNodo(data);
    if (ColaVacia(cola)) {
        cola->front = cola->tail = nodo;
    }
    cola->tail->next = nodo;
    cola->tail = nodo;
}

// Función para desencolar un elemento
int Borrar(struct Cola* cola) {
    if (ColaVacia(cola)) {
        printf("La cola está vacía.\n");
    }
    struct Nodo* temporal = cola->front;
    int data = temporal->data;
    cola->front = temporal->next;
    if (cola->front == NULL) {
        cola->tail = NULL; // Si la cola se vacía, el rear también debe ser NULL
    }
    free(temporal);
    return data;
}