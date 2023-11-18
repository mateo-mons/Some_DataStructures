#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

#define max 10 // define la m�xima cantidad de la cola

/* Cola estatica */
/*
struct Cola {
    int datos[max];  // los datos se almacenan en un vector de datos enteros
    int inicio, final;
};


//  Funci�n para crear una cola
void crearCola(struct Cola * q) {
    q->inicio = -1;
    q->final =0 ;
}


// Retorna 1 si la cola esta llena
int cllena(struct Cola *q) {
    if (q->final == max)
        return (1);
    return(0);
}

// Retorna 1 si la cola esta vacia
int cvacia(struct Cola *q) {
    if (q->final==0)
        return (1);
    return(0);
}


//Funci�n para retornar el primer elemento de la cola
int remover(struct Cola *q) {
    int x,i;

    x = q->datos[0];//guarda en la variable x el valor del 1er elemento de la cola
    for(i=0;i<q->final-1;i++)
        q->datos[i] = q->datos[i+1];// va arrimando de posici�n los elementos de la cola

    q->final--;//disminuye el final ya que esta un elemento menos
    return(x);// retorna el valor
}


//Funci�n para insertar un elemento en la cola
void insertarC(struct Cola *q, int dato) {
    q->datos[q->final]=dato;
    q->final++;
}
*/







/* Cola dinamica */

struct nodo {
    int dato;
    struct nodo *next;
};

// Estructura de la cola
struct Cola {
    struct nodo* front;
    struct nodo* tail;
};

// Funcion para crear un nodo nuevo en la cola
struct nodo* crearNodo(int dato) {
    struct nodo *p;
    p = (struct nodo*) malloc(sizeof(struct nodo));
    p->dato = dato;
    p->next = NULL;
    return(p);
}

struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->front = cola->tail = NULL;
    return cola;
}

// Función para verificar si la cola está vacía
int ColaVacia(struct Cola* cola) {
    return (cola->front == NULL);
}


// Funcion para insertar un dato en un nodo nuevo en la cola
struct nodo* insertar(struct nodo *inicio, int dato) {
    struct nodo *p, *nuevo, *q;
    nuevo =  crearNodo(dato);
    p = inicio;
    while(p != NULL) {
        q = p;
        p = p->next;
    }

    q->next = nuevo;
    return(inicio);
}


// Mostrar los elementos de la cola
void mostrarCola(struct nodo *inicio) {

    struct nodo *aux;
    aux = inicio;
    while(aux) {
        printf(" -> %d", aux->dato);
        aux = aux->next;
    }
}


// Funcion para borrar un elemento de la cola
struct nodo* borrar(struct nodo *inicio) {
    struct nodo *p;
    p = inicio;
    printf("Dato extraido: %d\n",p->dato);
    inicio = p->next;
    free(p);
    return inicio;
}





