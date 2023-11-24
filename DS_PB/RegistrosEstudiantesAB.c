#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo {
    int NumMat;
    char Nombre[30];
    struct nodo *izquierdo, *derecho;
};

typedef struct nodo Nodo;
