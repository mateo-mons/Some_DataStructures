#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tamaño del tablero
#define FILAS 8
#define COLUMNAS 8

// Definición de las figuras de tromino
int figuras[4][2][3] = {
    {{1, 1, 1}, {0, 0, 0}},  // Figura 1 (I-Tromino)
    {{1, 1, 1}, {1, 0, 0}},  // Figura 2 (L-Tromino)
    {{1, 1, 1}, {0, 1, 0}},  // Figura 3 (T-Tromino)
    {{1, 1, 0}, {0, 1, 1}}   // Figura 4 (Z-Tromino)
};

// Matrices para representar el tablero y la solución
int tablero[FILAS][COLUMNAS] = {{0}};
int solucion[FILAS][COLUMNAS] = {{0}};

// Variable para contar los movimientos realizados
int movimientos = 0;

// Función para imprimir el tablero
void imprimirTablero(int matriz[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            if(matriz[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Función para imprimir los movimientos realizados
void imprimirMovimientos(int matriz[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            if(matriz[i][j] == 1) {
                printf("(%d, %d) ", i, j);
            }
        }
    }
    printf("\n");
}

// Función para validar si una figura de tromino se puede colocar en una posición
int validarColocacion(int fila, int columna, int figura[2][3], int matriz[FILAS][COLUMNAS]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(figura[i][j] == 1) {
                if(fila + i < FILAS && columna + j < COLUMNAS && matriz[fila + i][columna + j] == 1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Función recursiva para resolver el rompecabezas de trominos
int resolverTromino(int fila, int columna) {
    if(fila == FILAS) {
        return 1; // Se llenó todo el tablero
    }

    int siguiente_fila, siguiente_columna;

    // Determinar la siguiente posición
    if(columna == COLUMNAS - 1) {
        siguiente_fila = fila + 1;
        siguiente_columna = 0;
    } else {
        siguiente_fila = fila;
        siguiente_columna = columna + 1;
    }

    if(tablero[fila][columna] == 1) {
        return resolverTromino(siguiente_fila, siguiente_columna); // Caso ya ocupado
    }

    for(int fig = 0; fig < 4; fig++) {
        if(validarColocacion(fila, columna, figuras[fig], tablero)) {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                    if(figuras[fig][i][j] == 1) {
                        tablero[fila + i][columna + j] = 1;
                    }
                }
            }

            movimientos++; // Incrementa el contador de movimientos

            if(resolverTromino(siguiente_fila, siguiente_columna)) {
                return 1; // La solución se encontró
            }

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                    if (figuras[fig][i][j] == 1) {
                        tablero[fila + i][columna + j] = 0; // Retroceder (backtrack)
                    }
                }
            }
        }
    }

    return 0; // No se encontró solución
}

int main() {
    // Aleatoriedad para obtener soluciones diferentes en cada ejecución
    srand(time(NULL));

    printf("Tablero inicial:\n");
    imprimirTablero(tablero);

    if(resolverTromino(0, 0)) {
        printf("\n");
        printf("Solución encontrada en %d movimientos:\n", movimientos);
        imprimirTablero(tablero);
        printf("\n");
        printf("Movimientos realizados: ");
        printf("\n");
        imprimirMovimientos(tablero);
    } else {
        printf("No se encontró una solución.\n");
    }

    return 0;
}

