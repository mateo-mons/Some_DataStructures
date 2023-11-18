#include<stdio.h>
#include<stdlib.h>


#define True 1
#define False 0


typedef struct Arbol {
    int info;
    struct Arbol *izq;
    struct Arbol *der;
    int Fe;
}arbol;

// Prototipado
void Borrar(arbol **a, int c, int *sw);
void Eliminar(arbol **a, int *sw);


void Inicializar(arbol **a) {
    *a = NULL;
}


int Vacio(arbol *a) {
    return a == NULL;
}


void Buscar(arbol *a, int c, int *encontrado) {

    if(Vacio(a))
        *encontrado = False;
    else
        if(a->info == c)
            *encontrado = True;
        else
            if(a->info > c)
                Buscar(a->izq, c, encontrado);
            else
                Buscar(a->der, c, encontrado);
}



arbol *Construir(arbol *a, int e, arbol *b) {

    arbol *nuevo;

    nuevo = (arbol*)malloc(sizeof(arbol));
    nuevo->info = e;
    nuevo->izq = a;
    nuevo->der = b;
    return nuevo;
}


/* El hijo izquierdo del nodo actual ocupara en el arbol el lugar
    del nodo actual. Hay que actualizar los factores de equilibrio
*/

void RotacionIISimple(arbol **a) {

    arbol *p;
    p = (*a)->izq;
    (*a)->izq = p->der;
    p->der = *a;
    p->Fe = 0;
    (*a)->Fe = 0;
    *a = p;
}

/* El hijo derecho del nodo actual ocupara en el arbol el lugar
    del nodo actual. Hay que actualizar los factores de equilibrio
*/

void RotacionDDSimple(arbol **a) {

    arbol *p;
    p = (*a)->der;
    (*a)->der = p->der;
    p->der = *a;
    p->Fe = 0;
    (*a)->Fe = 0;
    *a = p;
}

/* El hijo derecho del hijo izquierdo del nodo actual es el que se colocar�
    en la posicion del nodo actual. Hay que actualizar los factores de equilibrio
*/

void RotacionIDDoble(arbol **a) {

    arbol *p1;
    arbol *p2;
    p1 = (*a)->izq;
    p2 = p1->der;
    p1->der = p2->izq;
    p2->izq = p1;
    (*a)->izq = p2->der;
    p2->der = *a;

    if(p2->Fe == 1)
        p1->Fe = -1;
    else
        p1->Fe = 0;

    if(p2->Fe == -1)
        (*a)->Fe = 1;
    else
        (*a)->Fe = 0;

    p2->Fe = 0;
    *a = p2;
}

/* El hijo izquierdo del hijo derecho del nodo actual es el que se colocar�
    en la posicion del nodo actual. Hay que actualizar los factores de equilibrio
*/

void RotacionDIDoble(arbol **a) {

    arbol *p1;
    arbol *p2;
    p1 = (*a)->der;
    p2 = p1->izq;
    p1->izq = p2->der;
    p2->der = p1;
    (*a)->der = p2->izq;
    p2->izq = *a;

    if(p2->Fe == 1)
        p1->Fe = -1;
    else
        (*a)->Fe = 0;

    if(p2->Fe == -1)
        p1->Fe = 1;
    else
        p1->Fe = 0;

    p2->Fe = 0;
    *a = p2;
}

/* Los caso a considerar son:
    La rama derecha era mas alta que la izquierda, asi que un nuevo elemento en la rama
    izquierda consigue que los dos adquieran la misma altura. El subarbol ha dejado de
    crecer y sw se desactiva.
    Las ramas izquierda y derecha del nodo considerado tenian anteriormente la misma altura
    por lo que, al insertar un elemento en la rama izquierda, su altura se hara mayor
    que la de la derecha.
    La rama izquierda era mas alta que la derecha y un nuevo elemento en la rama izquierda
    rompe el equilibrio del arbol y hace que sea necesaria su reestructuracion
*/

void ActualizarIzq(arbol **a, int *sw) {

    switch((*a)->Fe) {
        case 1:
            (*a)->Fe = 0;
            *sw = False;
        break;

        case 0:
            (*a)->Fe = -1;
        break;

        case -1:
            if((*a)->izq->Fe == -1)
                RotacionIISimple(a);
            else
                RotacionIDDoble(a);
            *sw = False;
        break;
    }
}


void ActualizarDer(arbol **a, int *sw) {

    switch((*a)->Fe) {
        case -1:
            (*a)->Fe = 0;
            *sw = False;
        break;

        case 0:
            (*a)->Fe = 1;
        break;

        case 1:
            if((*a)->der->Fe == 1)
                RotacionDDSimple(a);
            else
                RotacionDIDoble(a);
            *sw = False;
        break;
    }
}


/* El procedimiento empleado es analogo al de insercion en un arbol binario,
    pero regresar por el camino de busqueda si sw esta activo se calcula el nuevo
    factor de equilibrio de los nodos
*/
void Insertar(arbol **a, int e, int *sw) {

    if(Vacio(*a)) {
        *a = Construir(NULL, e, NULL);
        (*a)->Fe = 0;
        *sw = True;
    } else
        if((*a)->info > e) {
            Insertar(&(*a)->izq, e, sw);
            if(*sw)
                ActualizarIzq(a, sw);
        } else
            if((*a)->info < e) {
                Insertar(&(*a)->der, e, sw);
                if(*sw)
                    ActualizarDer(a, sw);
            } else
                *sw = False;
}


void Menor(arbol *a, int *e) {
    if(a->izq == NULL)
        *e = a->info;
    else
        Menor(a->izq, e);
}

/* Rotacion especifica del borrado, que se diferencia de la RotacionIISimple
    en los factores de equilibrio adjudicados a los nodos implicados
*/
void RotacionII2(arbol **a) {

    arbol *p;
    p = (*a)->izq;
    (*a)->izq = p->der;
    p->der = *a;
    p->Fe = 1;
    (*a)->Fe = -1;
    *a = p;
}


/* Rotacion especifica del borrado, que se diferencia de la RotacionDDSimple
    en los factores de equilibrio adjudicados a los nodos implicados
*/
void RotacionDD2(arbol **a) {

    arbol *p;
    p = (*a)->der;
    (*a)->der = p->izq;
    p->izq = *a;
    p->Fe = -1;
    (*a)->Fe = 1;
    *a = p;
}


/* El factor de equilibrio del nodo actual aumenta en una unidad pues el borrado
    se ha efectuado por la izquierda. Si el anterior factor de equilibrio del
    nodo actual era 1 es necesario reestructurar y considerar tres tipos de
    rotaciones
*/

void ActualizarBI(arbol **a, int *sw) {

    switch((*a)->Fe) {
        case -1:
            (*a)->Fe = 0;
        break;

        case 0:
            (*a)->Fe = 1;
            *sw = False;
        break;

        case 1:
            switch((*a)->der->Fe) {
                case 1:
                    RotacionDDSimple(a);
                break;

                case -1:
                    RotacionDIDoble(a);
                break;

                case 0:
                    RotacionDD2(a);
                    *sw = False;
                break;
            }
    }
}

/* El factor de equilibrio del nodo actual disminuye en una unidad pues
    el borrado se ha efectuado por la derecha. Si el anterior factor de equilibrio
    era -1 es necesario reestructurar y considerar los tres tipos de rotaciones
    posibles
*/
void ActualizarBD(arbol **a, int *sw) {

    switch((*a)->Fe) {
        case 1:
            (*a)->Fe = 0;
        break;

        case 0:
            (*a)->Fe = -1;
            *sw = False;
        break;

        case -1:
            switch((*a)->izq->Fe) {
                case -1:
                    RotacionIISimple(a);
                break;

                case 1:
                    RotacionIDDoble(a);
                break;

                case 0:
                    RotacionII2(a);
                    *sw = False;
                break;
            }
    }
}


void Eliminar(arbol **a, int *sw) {

    arbol *aux;
    int e;

    if((*a)->izq == NULL) {
        aux = *a;
        *a = (*a)->der;
        free(aux);
        *sw = True;
    } else
        if((*a)->der == NULL) {
            aux = *a;
            *a = (*a)->izq;
            free(aux);
            *sw = True;
        } else {
            Menor((*a)->der, &e);
            (*a)->info = e;
            Borrar(&(*a)->der, e, sw);
            if(*sw)
                ActualizarBD(a, sw);
        }
}

/* El procedimiento empleado es analogo al de borrado en un arbol binario,
    pero regresar por el camino de busqueda si sw esta activo se calcula
    el nuevo factor de equilibrio de los nodos
*/

void Borrar(arbol **a, int c, int *sw) {
    if(*a != NULL)
        if((*a)->info == c)
            Eliminar(a, sw);
        else
            if((*a)->info > c) {
               Borrar(&(*a)->izq, c, sw);
               if(*sw)
                    ActualizarBI(&(*a), sw);
               } else {
                   Borrar(&(*a)->der, c, sw);
                   if(*sw)
                        ActualizarBD(&(*a), sw);
               }
}


void Dibujar(arbol *a, int nivel) {
    int i;
    if(a != NULL) {
        Dibujar(a->der, nivel+1);
        for(i=1; i<=nivel; i++)
            printf("    ");
        printf("%d\n", a->info);
        Dibujar(a->izq, nivel+1);
    }
}


void RecorrerAs(arbol *a) {
    if(! Vacio(a)) {
        RecorrerAs(a->izq);
        printf(" %d ", a->info);
        RecorrerAs(a->der);
    }
}


void RecorrerDes(arbol *a) {
    if(! Vacio(a)) {
        RecorrerDes(a->der);
        printf(" %d ", a->info);
        RecorrerDes(a->izq);
    }
}


/* Programa principal */

int main() {

    int num;
    char pausa;
    arbol *a;
    int sw;

    Inicializar(&a);
    printf("Ingrese un elemento(0->Fin): ");
    scanf("%d*c ", &num);

    while(num != 0) {
        Insertar(&a, num, &sw);
        Dibujar(a, 0);
        puts("");
        printf("Ingrese un elemento(0->Fin): ");
        scanf("%d*c", &num);
    }
    printf("Ingrese un elemento para borrar(0->Fin): ");
    scanf("%d*c", &num);

    while(num != 0) {
        Borrar(&a, num, &sw);
        Dibujar(a, 0);
        puts("");
        printf("Ingrese un elemento para borrar(0->Fin): ");
        scanf("%d*c", &num);
    }

    pausa = getchar();

    return 0;
}










