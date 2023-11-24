#include<stdlib.h>
#include<stdio.h>
#include "LibPilasColas.h"


int main() {
    struct Pila* pila = CrearPila();
    struct Cola* cola = CrearCola();
    char d;
    
    printf("Número a investigar: ");
    
    while((d = getchar()) != '\n') {
        if(d >= '0' && d <= '9') {
            push(pila, d);
            Insertar(cola, d);
        }
    }
    
    int capicua = 1; // Suponemos que el número es capicúa
    
    while(!PilaVacia(pila) && !ColaVacia(cola)) {
        if(pop(pila) != Borrar(cola)) {
            capicua = 0; // No es capicúa
            break;
        }
    }
    
    if(capicua) {
        printf("El número introducido es capicúa.\n");
    } else {
        printf("El número introducido no es capicúa.\n");
    }
    
    free(pila);
    free(cola);


    return 0;
}