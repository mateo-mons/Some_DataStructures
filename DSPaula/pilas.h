#include <stdlib.h>
#include <stdio.h>

/* Pila estatica */
/*
struct Pila {
    int tope;
    int dato[max];
};

// Insercion de un elemento a la pila

void empilar(struct Pila *pila, int x) {

    pila->dato[pila->tope++] = x;
}

// Sacar un elemento

int desempilar(struct Pila *pila) {

    return(pila->dato[--pila->tope]);
}

// lista vacia?

int pvacia(struct Pila *pila) {

    if(pila->tope == 0)
        return(1);
    else
        return(0);
}

// lista llena?

int pllena(struct Pila *pila) {

    if(pila->tope == max)
        return(1);
    else
        return(0);
}
/*



/* Pila dinamica */
/*
struct nodo {
    int dato;
    struct nodo *next;
};
*/

// Estructura de la pila
struct Pila {
    struct nodo *top;
};

struct Pila *crearPila() {
    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->top = NULL;
    return pila;
}

// Función para verificar si la pila está vacía
int PilaVacia(struct Pila* pila) {
    return (pila->top == NULL);
}

struct nodo *crearnodo(int dato) {
    struct nodo* p = (struct nodo*)malloc(sizeof(struct nodo));
    p->dato = dato;
    p->next = NULL;
    return(p);
}

// introducir un nuevo dato en la pila
struct nodo *push(struct nodo *tope, int dato) {
    struct nodo *aux;
    aux = crearnodo(dato);
    aux->next = tope;
    tope = aux;
    return(tope);
}

// muestra todos los elementos de la pila
void mostrarPila(struct nodo *tope) {
    struct nodo *aux;
    if(!tope)
        printf("Esta vacia");
    else {
        aux = tope;
        while(aux != NULL) {
            printf(" -> %d ", aux->dato);
            aux = aux->next;
        }
    }
}

// sacar un dato de la pila
struct nodo* pop(struct nodo *tope, char* valor) {
    struct nodo *aux;
    char dato;
    aux = tope;
    *valor = tope->dato;
    tope = tope->next;
    free(aux);
    return(tope);
}

