#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

#define max 3  // define la máxima cantidad de la cola

/* Implementacion de cola estatica */
/*
struct Cola {
    int datos[max];  // los datos se almacenan en un vector de datos enteros
    int inicio,final;
};


//  Función para crear una cola
void crearCola(struct Cola * q) {
    q->inicio = -1;
    q->final =0 ;
}


// Retorna 1 si la cola esta llena
int llena(struct Cola *q) {
    if (q->final == max)
        return (1);
    return(0);
}

// Retorna 1 si la cola esta vacia
int vacia(struct Cola *q) {
    if (q->final==0)
        return (1);
    return(0);
}


//Función para retornar el primer elemento de la cola
int remover(struct Cola *q) {
    int x,i;

    x = q->datos[0];//guarda en la variable x el valor del 1er elemento de la cola
    for(i=0;i<q->final-1;i++)
        q->datos[i] = q->datos[i+1];// va arrimando de posición los elementos de la cola

    q->final--;//disminuye el final ya que esta un elemento menos
    return(x);// retorna el valor
}


//Función para insertar un elemento en la cola
void insertar(struct Cola *q, int dato) {
    q->datos[q->final]=dato;
    q->final++;
}

// Funcion de menu de opciones
void menu() {
    printf("--- MENU DE OPERACIONES ---\n");
    printf("1.Agregar un elemento\n");
    printf("2.Sacar un elemento\n");
    printf("3.Salida\n");
    printf("Opcion: ");
}


// Programa Principal donde se llaman a las funciones básicas
int main() {

    struct Cola C;
    char op;
    int num;
    crearCola(&C);

    while (op != '3') {
        menu();
        scanf("%s", &op);

        switch(op){
            case '1': 
                if(!llena(&C)) {
                    printf("Que dato desea ingresar: ");
                    scanf("%d", &num);
                    insertar(&C, num);
                    printf("Dato Insertado: %d\n\n", C.datos[C.final-1]);
                } else {
                    printf("Cola LLena\n\n");
                }
            break;

            case '2': 
                if(!vacia(&C))
                    printf("Dato %d extraido\n\n", remover(&C));
                else
                    printf("No hay datos\n\n");
            break;

            case '3': 
                printf("Hasta pronto!\n");
            break;

            default:
                printf("Intente de nuevo\n");
        }
    }

    return 0;
}
*/


/* Implementacion de cola dinamica */

struct nodo {
    int dato;
    struct nodo *sig;
};

// Funcion para crear un nodo nuevo en la cola
struct nodo* crearNodo(int dato) {
    struct nodo *p;
    p = (struct nodo*) malloc(sizeof(struct nodo));
    p->dato = dato;
    p->sig = NULL;
    return(p);
}


// Funcion para insertar un dato en un nodo nuevo en la cola
struct nodo* insertar(struct nodo *inicio, int dato) {
    struct nodo *p, *nuevo, *q;
    nuevo =  crearNodo(dato);
    p = inicio;
    while(p != NULL) {
        q = p;
        p = p->sig;
    }

    q->sig = nuevo;
    return(inicio);
}


// Mostrar los elementos de la cola
void mostrar(struct nodo *inicio) {

    struct nodo *aux;
    aux = inicio;
    while(aux) {
        printf(" -> %d", aux->dato);
        aux = aux->sig;
    }
}


// Funcion para borrar un elemento de la cola
struct nodo* borrar(struct nodo *inicio) {
    struct nodo *p;
    p = inicio;
    printf("Dato extraido: %d\n",p->dato);
    inicio = p->sig;
    free(p);
    return inicio;
}

// Funcion de menu de operaciones
void menu() {
    printf("--- MENU PRINCIPAL ---\n");
    printf("1.Insertar en la cola\n");
    printf("2.Mostrar cola\n");
    printf("3.Eliminar cola\n");
    printf("4.Salir\n");
    printf("Opcion: ");
}



// Programa Principal donde se llaman a las funciones basicas
int main() { 
    struct nodo *inicio = NULL;
    struct nodo *p = NULL;
    char op;
    int x;
    while(op != '4') {
        menu();
        scanf("%s", &op);

        switch(op) {
            case '1': 
                printf("Ingrese el elemento: ");
                scanf("%d", &x);
                if(!inicio)
                    inicio = crearNodo(x);
                else
                    inicio = insertar(inicio, x);
                    p = inicio;
            break;

            case '2':
                if(inicio) {
                    printf("Cola");
                    mostrar(inicio);
                    printf("\n");
                } else
                    printf("La cola esta vacia\a\n");
            break;

            case '3':
                if(!inicio) 
                    printf("Error. La cola esta vacia.\a\n");
                else
                    inicio = borrar(inicio);
            break;

            case '4':
                printf("Hasta pronto!\n");
            break;

            default:
                printf("Intente de nuevo\n");
        }
    }
}
