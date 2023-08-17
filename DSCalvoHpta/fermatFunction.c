#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para calcular el número triangular de término n
int triangular(int n) {
    return n * (n + 1) / 2;
}

// Función para contar la cantidad de formas diferentes de obtener n con la suma de uno, dos o tres números triangulares
int contar_formas(int n) {
    int formas = 0;
    // Contar la cantidad de formas diferentes de obtener n con la suma de un número triangular
    for (int i = 1; triangular(i) <= n; i++) {
        if (triangular(i) == n) {
            formas++;
        }
    }
    // Contar la cantidad de formas diferentes de obtener n con la suma de dos números triangulares
    for (int i = 1; triangular(i) <= n; i++) {
        for (int j = i; triangular(i) + triangular(j) <= n; j++) {
            if (triangular(i) + triangular(j) == n) {
                formas++;
            }
        }
    }
    // Contar la cantidad de formas diferentes de obtener n con la suma de tres números triangulares
    for (int i = 1; triangular(i) <= n; i++) {
        for (int j = i; triangular(i) + triangular(j) <= n; j++) {
            for (int k = j; triangular(i) + triangular(j) + triangular(k) <= n; k++) {
                if (triangular(i) + triangular(j) + triangular(k) == n) {
                    formas++;
                }
            }
        }
    }
    return formas;
}

int main() {
    int casos_prueba, n;
    // Leer el número de casos de prueba
    scanf("%d", &casos_prueba);
    for (int i = 0; i < casos_prueba; i++) {
        // Leer el valor de n para el caso de prueba actual
        scanf("%d", &n);
        // Calcular la cantidad de formas diferentes de obtener n con la suma de uno, dos o tres números triangulares
        int resultado = contar_formas(n);
        // Mostrar el resultado
        printf("%d\n", resultado);
    }
    return 0;
}



