#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de un nodo para la pila
struct Node {
    char data;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Función para insertar un nodo al comienzo de la pila
void push(struct Node** top, char data) {
    struct Node* newData = newNode(data);
    newData->next = *top;
    *top = newData;
}

// Función para extraer un nodo del comienzo de la pila
char pop(struct Node** top) {
    if (*top == NULL) {
        return '\0'; // Pila vacía
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

// Función para comprobar si una palabra o frase es un palíndromo
int esPalindromo(const char* palabra) {
    struct Node* pila = NULL;
    int longitud = strlen(palabra);

    // Insertar cada carácter de la palabra en la pila
    for (int i = 0; i < longitud; i++) {
        push(&pila, palabra[i]);
    }

    // Comparar cada carácter de la palabra con el carácter en la cima de la pila
    for (int i = 0; i < longitud; i++) {
        char caracterPila = pop(&pila);
        if (caracterPila != palabra[i]) {
            return 0; // No es un palíndromo
        }
    }

    return 1; // Es un palíndromo
}

int main() {
    char palabra[100];

    printf("Por favor, ingrese una palabra o frase: ");
    fgets(palabra, sizeof(palabra), stdin);

    // Eliminar el salto de línea al final de la palabra
    palabra[strlen(palabra) - 1] = '\0';

    if (esPalindromo(palabra)) {
        printf("Es un palíndromo.\n");
    } else {
        printf("No es un palíndromo.\n");
    }

    return 0;
}
