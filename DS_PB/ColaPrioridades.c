#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Max2 100

// Operaciones de tipo abstracto de dato monticulo

#define MAX 100

typedef int Telemento;
typedef struct {
    Telemento a[MAX+1];
    int n;
} Monticulo;


void CrearMonticulo(Monticulo *monticulo) {
    monticulo->n = 0;
}


void Subir(Monticulo *monticulo, int pos) {
    Telemento Clave;
    int padre, EsMonton = 0;
    Clave = monticulo->a[pos];
    padre = pos/2;
    while((padre >= 1) && !EsMonton)
        if(monticulo->a[padre] > Clave) {
            monticulo->a[pos] = monticulo->a[padre];
            pos = padre;
            padre = padre/2;
        } else
            EsMonton = 1;
    monticulo->a[pos] = Clave;
}


void Insertar(Monticulo *monticulo, Telemento Clave) {
    if(monticulo->n == MAX)
        printf("No es posible insertar claves, monticulo lleno");
    else {
        (monticulo->n)++;
        monticulo->a[monticulo->n] = Clave;
        Subir(monticulo, monticulo->n);
    }
}


Telemento BuscarMin(Monticulo monticulo) {
    if(monticulo.n == 0)
        printf("Monticulo vacio");
    return monticulo.a[1];
}

int EsVacio(Monticulo monticulo) {
    return monticulo.n == 0;
}


void Criba(int a[], int primero, int ultimo) {
    int EsMonticulo = 0, hijoMenor, aux;

    while((2*primero <= ultimo) && !EsMonticulo) {
        if(2*primero == ultimo)
            hijoMenor = 2*primero;
        else
            if(a[2*primero] < a[2*primero+1])
                hijoMenor = 2*primero;
        else
            hijoMenor = 2*primero+1;

        if(a[hijoMenor] < a[primero]) {
            aux = a[primero];
            a[primero] = a[hijoMenor];
            a[hijoMenor] = aux;
            primero = hijoMenor;
        } else
            EsMonticulo = 1;
    }
}


void EliminarMin(Monticulo *monticulo) {
    if(EsVacio(*monticulo)) {
        printf("No es posible eliminar clave, monticulo vacio");
    } else {
        monticulo->a[1] = monticulo->a[monticulo->n];
        monticulo->n = monticulo->n-1;
        Criba(monticulo->a, 1, monticulo->n);
    }
}


void Rellena(Telemento A[Max2], int *n) {
    int i;
    srand(time(NULL));
    *n = rand() % Max2;
    for(i=0; i<(*n); i++)
        A[i] = rand() % Max2;
}


void Escribe(Telemento A[], int n) {
    int i;
    for(i=0; i<n; i++)
        if((i+1) % 10 == 0)
            printf("%7d\n", A[i]);
        else
            printf("%7d", A[i]);
}


int main() {
    Telemento a[Max2];
    int n, i;
    Monticulo monticulo;
    Rellena(a, &n);
    Escribe(a, n);

    CrearMonticulo(&monticulo);

    for(i=0; i<n; i++) {
        Insertar(&monticulo, a[i]);
    }

    for(i=0;i<n; i++) {
        a[i] = BuscarMin(monticulo);
        EliminarMin(&monticulo);
    }
    printf("DATOS ORDENADOS\n");
    Escribe(a, n);

    return 0;
}