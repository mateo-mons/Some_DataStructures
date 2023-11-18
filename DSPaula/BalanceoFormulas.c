#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

// Función para verificar si los símbolos de apertura y cierre coinciden
int Simbolos(char abre, char cierra) {
    if ((abre == '(' && cierra == ')') ||
        (abre == '[' && cierra == ']') ||
        (abre == '{' && cierra == '}')) {
        return 1;
    } else {
        return 0;
    }
}

// Función para verificar si una fórmula está balanceada
int Balanceo(char formula[]) {
    struct nodo* pila = NULL; // Inicializamos la pila como vacía
    
    for (int i = 0; formula[i] != '\0'; i++) {
        if (formula[i] == '(' || formula[i] == '[' || formula[i] == '{') {
            // Si encontramos un símbolo de apertura, lo almacenamos en la pila
            struct nodo* nuevo = crearnodo(formula[i]);
            nuevo->ant = pila;
            pila = nuevo;
        } else if (formula[i] == ')' || formula[i] == ']' || formula[i] == '}') {
            // Si encontramos un símbolo de cierre
            if (pila == NULL || !Simbolos(pila->dato, formula[i])) {
                // Si la pila está vacía o los símbolos no coinciden, la fórmula no está balanceada
                return 0;
            } else {
                // Si los símbolos coinciden, eliminamos el símbolo de apertura de la pila
                struct nodo* temp = pila;
                pila = pila->ant;
                free(temp);
            }
        }
    }
    
    // Si la pila está vacía al final, la fórmula está balanceada
    return(pila == NULL);
}

void menu() {
    printf("--- Balanceo de formulas ---\n");
    printf("1.Ingresar formula\n");
    printf("2.Salir\n");
    printf("Opcion: ");
}

int main() {
    
    char formula[50];
    int option;

    while(option != 2) {
        menu();
        scanf("%d", &option);

        switch (option) {

            case 1:
                printf("Ingrese una fórmula con paréntesis, corchetes y llaves: ");
                scanf("%s", formula);
                
                if(Balanceo(formula)) {
                    printf("La fórmula está correctamente balanceada!\n\n");
                } else {
                    printf("La fórmula no está correctamente balanceada\n\n");
                }
                break;
            
            case 2:
                printf("Hasta pronto!\n");
                break;
            
            default:
                printf("Intente de nuevo\n");
                break;
        }
    }
    


    return 0;
}