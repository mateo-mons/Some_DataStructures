//#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define max 3 // Cantidad maxima de elementos de la pila

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

int vacia(struct Pila *pila) {

    if(pila->tope == 0)
        return(1);
    else
        return(0);
}

// lista llena?

int llena(struct Pila *pila) {

    if(pila->tope == max)
        return(1);
    else
        return(0);
}

// menu

void menu() {
    puts("1) Meter un elemento");
    puts("2) Sacar un elemento");
    puts("3) Tamanio de la Pila");
    puts("4) Salida");
    printf("Opcion: ");
}


int main() {

    struct Pila pila = {0};
    int num, opc;

    while(opc != 4) {
        menu();
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                if(!llena(&pila)) {
                    printf("\nQue dato desea ingresar: ");
                    scanf("%d", &num);
                    empilar(&pila, num);
                } else {
                    printf("\nPila llena");
                }
            break;

            case 2:
                if(!vacia(&pila)) {
                    printf("\n%d", desempilar(&pila));
                } else {
                    printf("\nPila vacia");
                }
            break;

            case 3:
                printf("\nHay %d datos\n", pila.tope);
            break;

            case 4:
                printf("\nHasta pronto!\n");
            break;

            default:
                printf("\nIntente de nuevo\n");
        }
    }

    return 0;
}
*/


/* Pila dinamica */

struct nodo {
    int dato;
    struct nodo *ant;
};

int vacia(struct nodo *tope) {

    return(!tope)? 1:0;
}

struct nodo *crearnodo(int dato) {
    struct nodo* p;
    p=(struct nodo*)malloc (sizeof (p));
    p->dato = dato;
    p->ant = NULL;
    return(p);
}

// introducir un nuevo dato en la pila
struct nodo* push(struct nodo * tope, int dato) {
    struct nodo *aux;
    aux = crearnodo(dato);
    aux->ant = tope;
    tope = aux;
    return(tope);
}

// muestra todos los elementos de la pila
void mostrar(struct nodo *tope) {
    struct nodo *aux;
    if(!tope)
        printf("Esta vacia");
    else {
        aux = tope;
        while(aux != NULL) {
            printf(" -> %d ", aux->dato);
            aux = aux->ant;
        }
    }
}

// sacar un dato de la pila
struct nodo* pop(struct nodo *tope, int* valor) {
    struct nodo *aux;
    int dato;
    aux = tope;
    *valor = tope->dato;
    tope = tope->ant;
    free(aux);
    return(tope);
}

// menu
void menu() {
    printf("\n1.Ingresar dato en la Pila");
    printf("\n2.Sacar Dato de la Pila");
    printf("\n3.Mostrar Pila");
    printf("\n4.Salir");
    printf("\nOpcion: ");
}

int main() {

    struct nodo *tope = NULL;
    int dato, opc;

    while(opc != 4) {
        menu();
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                printf("Ingresa dato: ");
                scanf("%d", &dato);

                if(tope == NULL)
                    tope = crearnodo(dato);
                else
                    tope = push(tope,dato);
            break;

            case 2:
                if(!vacia(tope)) {
                    tope = pop(tope, &dato);
                    printf("El dato en la cima es: %d", dato);
                } else
                    printf("\nPila Vacia");
            break;

            case 3:
                if (!vacia(tope)) {
                    printf("\nPila");
                    mostrar(tope);
                } else
                    printf("\nPila Vacia");
            break;

            case 4:
                printf("\nHasta pronto!\n");
            break;

            default:
                printf("\nIntente de nuevo!\n");
            break;
        }
    }
}



