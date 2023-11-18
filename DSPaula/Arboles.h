#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<time.h>


/* Estructura de un nodo del arbol */
typedef struct Nodo arbol;

struct Nodo {
    int dato;
    arbol *izquierdo;
    arbol *derecho;
};

/* Mensaje de error */
void Error() {
    printf("\nError, memoria insuficiente\n");
}

/* Crear un nuevo nodo del tipo de la estructura */
arbol *Nuevo() {
    arbol *q = (arbol *) malloc(sizeof(arbol));
    if(!q)
        Error();
    return(q);
}

/* Cambiar un dato p por un dato s */
arbol *Cambia(arbol *p, arbol *s) {
    arbol *temp;

    if(s->derecho != NULL) {
        s->derecho = Cambia(p, s->derecho);
    } else {
        temp = s;
        p->dato = s->dato;
        s = s -> izquierdo;
        free(temp);
    }
    return(s);
}

/* Buscar y eliminar un dato del arbol */
arbol *Suprimir(arbol *p, int dato) {
  arbol *temp;
  if(p == NULL)
    printf("\nArbol vacio\n");
  else if(dato < p->dato)
    p->izquierdo = Suprimir(p->izquierdo, dato);
  else if(dato > p->dato)
    p->derecho = Suprimir(p->derecho, dato);
  else {
    temp = p;
    if(temp->derecho == NULL) {
      p = temp->izquierdo;
      free(temp);
    }
    else if(temp->izquierdo == NULL) {
      p = temp->derecho;
      free(temp);
    }
    else
      temp->izquierdo = Cambia(temp, temp->izquierdo);
  }
  return(p);
}

/* Buscar un dato de forma recursiva en el arbol */
int BuscarRec(arbol *p, int dato) {
  if(p == NULL)
    return(0);
  if(dato == p->dato)
    return(1);
  if(dato < p->dato)
    return(BuscarRec(p->izquierdo, dato));
  else
    return(BuscarRec(p->derecho, dato));
}

/* Buscar un dato de forma iterativa en el arbol */
struct Nodo *BuscarIter(arbol *p, int dato) {
    int encontrado = 0;
    while(!encontrado && p != NULL) {
        if(dato == p->dato)
            encontrado = 1;
        else if(dato < p->dato)
            p = p->izquierdo;
        else if(dato > p->dato)
            p = p->derecho;
    }
    return (p);
}

/* Buscar el dato minimo en un arbol */
int BuscarMin(arbol *p) {
  if(p == NULL)
    return(0);
  else if(p->izquierdo == NULL)
    return(p->dato);
  else
    return(BuscarMin(p->izquierdo));
}

/* Buscar el dato maximo en un arbol */
int BuscarMax(arbol *p) {
  if(p == NULL)
    return(0);
  else if(p->derecho == NULL)
    return(p->dato);
  else
    return(BuscarMax(p->derecho));
}

/* Recorrer y mostrar los nodos del arbol */
void Ver(int nivel, arbol *p) {
  int i;
  if(p != NULL) {
    Ver(nivel + 1, p->derecho);
    printf("\n");
    for(i=0; i<nivel; i++) 
      printf(" ");
    printf("%d", p->dato);
    Ver(nivel + 1, p->izquierdo);
  }
}


/* Recorrer el arbol en Pre-Orden */
void PreOrden(arbol *p) {
  if(p != NULL) {
    printf(" -> %d", p->dato);
    PreOrden(p->izquierdo);
    PreOrden(p->derecho);
  }
}

/* Recorrer el arbol en En-Orden */
void EnOrden(arbol *p) {
  if(p != NULL) {
    EnOrden(p->izquierdo);
    printf(" -> %d", p->dato);
    EnOrden(p->derecho);
  }
}

/* Recorrer el arbol en Post-Orden */
void PostOrden(arbol *p) {
  if(p != NULL) {
    PostOrden(p->izquierdo);
    PostOrden(p->derecho);
    printf(" -> %d", p->dato);
  }
}

/* Insertar nodos en el arbol */
arbol *Insertar(int dato, arbol *p) {
  if(p == NULL) {
    p = Nuevo();
    p->dato = dato;
    p->izquierdo = NULL;
    p->derecho = NULL;
    return(p);
  }
  if(dato < p->dato)
    p->izquierdo = Insertar(dato, p->izquierdo);
  else
    p->derecho = Insertar(dato, p->derecho);

  return(p);
}

/* Altura del arbol */
int Altura(arbol *p) {
  if(!p)  
    return 0;
  else {
    int profundidadI = Altura(p->izquierdo);
    int profundidadD = Altura(p->derecho);
    if(profundidadI > profundidadD)
      return profundidadI + 1;
    else
      return profundidadD + 1;
  }
}

/* Contar el numero de nodos de un arbol */
int NumNodos(arbol *p) {
    if(p == NULL)
        return(0);
    return(NumNodos(p->izquierdo) + 1 + NumNodos(p->derecho));
}

/* Contar hojas */
void ContarHojas(arbol *p, int *nh) {
    if(p != NULL) {
        ContarHojas(p->izquierdo, nh);
        ContarHojas(p->derecho, nh); /*Procesar raiz:Determinar si es hoja*/
        if(p->izquierdo == NULL && p->derecho == NULL)
            (*nh)++;
    }
    free(p);
}

/* Eliminar arbol */
void EliminarArbol(arbol *p) {
    if(p != NULL) {
        EliminarArbol(p->izquierdo);
        EliminarArbol(p->derecho);
        printf("Nodo borrado: %d\n", p->dato);
        free(p);
    }
}