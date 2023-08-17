#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
/*
int main() {
    int n, i, j, boxes;

    printf("Ingrese el tamaño del tablero: ");
    scanf("%d", &n);

    boxes = 1;  // El primer diagonal contiene solo una caja

    // Recorrer cada diagonal del tablero
    for (i = 2; i <= n; i++) {
        boxes += i;  // El número de cajas en la diagonal actual

        // Recorrer cada caja de la diagonal actual
        for (j = 1; j <= i; j++) {
            printf("(%d, %d) ", i - j + 1, j);  // Mostrar la posición de la caja
        }
        printf("\n");  // Nueva línea para separar cada diagonal
    }

    printf("Total de cajas en el tablero: %d\n", boxes);

    return 0;
}
*/

/*
/*
#include <stdio.h>

int main() {
    int n;
    printf("Ingrese el número de diagonales de la tabla: ");
    scanf("%d", &n);
    
    int cajas = 0;
    for (int i = 1; i <= n; i++) {
        cajas += i;
        for (int j = 1; j <= i; j++) {
            printf("Explorando caja en la diagonal %d, posición %d\n", i, j);
        }
    }
    printf("La hormiga Dora ha explorado un total de %d cajas.\n", cajas);
    
    return 0;
}
*/

/*
/*
#include <stdio.h>

int main() {
    int n, i, j, diagonal;
    printf("Ingrese el tamaño del tablero: ");
    scanf("%d", &n);

    // Inicializar posición de la hormiga
    i = 1;
    j = 1;

    // Recorrer diagonales
    for (diagonal = 1; diagonal <= n; diagonal++) {
        printf("(%d,%d) -> ", i, j);
        if (diagonal % 2 == 1) {
            // Diagonal descendente
            for (j++; j <= diagonal; j++) {
                printf("(%d,%d) -> ", i, j);
                i++;
            }
        } else {
            // Diagonal ascendente
            for (i++; i <= diagonal; i++) {
                printf("(%d,%d) -> ", i, j);
                j++;
            }
        }
    }

    return 0;
}
*/

/*
/*
#include <stdio.h>

int main() {
    int n, i, j, diagonal;
    int x, y; // Coordenadas iniciales de la hormiga
    printf("Ingrese el tamaño del tablero: ");
    scanf("%d", &n);
    printf("Ingrese la coordenada x inicial de la hormiga: ");
    scanf("%d", &x);
    printf("Ingrese la coordenada y inicial de la hormiga: ");
    scanf("%d", &y);
    printf("Ingrese la longitud de la diagonal: ");
    scanf("%d", &diagonal);

    // Inicializar posición de la hormiga
    i = x;
    j = y;

    // Recorrer diagonal
    printf("(%d,%d) -> ", i, j);
    if (diagonal % 2 == 1) {
        // Diagonal descendente
        for (j++; j <= y+diagonal-1; j++) {
            printf("(%d,%d) -> ", i, j);
            i++;
        }
    } else {
        // Diagonal ascendente
        for (i++; i <= x+diagonal-1; i++) {
            printf("(%d,%d) -> ", i, j);
            j++;
        }
    }
    printf("\n");

    return 0;
}
*/

/*
/*
#include <stdio.h>

int main() {
    int n, x, y, pasos = 1, i = 1, j = 1;
    printf("Ingrese el tamaño del tablero: ");
    scanf("%d", &n);
    printf("Ingrese la coordenada x de la caja objetivo: ");
    scanf("%d", &x);
    printf("Ingrese la coordenada y de la caja objetivo: ");
    scanf("%d", &y);

    // Recorrer tablero triangular en forma de diagonales
    while (i <= n && j <= n) {
        if (i == x && j == y) {
            // La hormiga llegó a la caja objetivo
            printf("La hormiga llegó a la caja (%d,%d) en %d pasos.\n", x, y, pasos);
            break;
        }
        if (i == j) {
            // Diagonal descendente
            j++;
            pasos++;
            while (j <= n && i >= 1) {
                if (i == x && j == y) {
                    // La hormiga llegó a la caja objetivo
                    printf("La hormiga llegó a la caja (%d,%d) en %d pasos.\n", x, y, pasos);
                    return 0;
                }
                j++;
                i--;
                pasos++;
            }
            i++;
        } else {
            // Diagonal ascendente
            i++;
            pasos++;
            while (i <= n && j >= 1) {
                if (i == x && j == y) {
                    // La hormiga llegó a la caja objetivo
                    printf("La hormiga llegó a la caja (%d,%d) en %d pasos.\n", x, y, pasos);
                    return 0;
                }
                i++;
                j--;
                pasos++;
            }
            j++;
        }
    }

    return 0;
}
*/

/*
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    printf("Ingrese las coordenadas de la caja: ");
    scanf("%d %d", &x, &y);

    int count = 1;
    int i = 1, j = 1;

    while (i != x || j != y) {
        if (i < x && j < y) {
            int steps = y - j;
            if (i + steps <= x) {
                i += steps;
                j += steps;
                count += steps;
            } else {
                steps = x - i;
                i += steps;
                j += steps;
                count += steps;
                count += y - j;
                j = y;
            }
        } else if (i > x && j > y) {
            int steps = j - y;
            if (i - steps >= x) {
                i -= steps;
                j -= steps;
                count += steps;
            } else {
                steps = i - x;
                i -= steps;
                j -= steps;
                count += steps;
                count += j - y;
                j = y;
            }
        } else if (i < x) {
            i++;
            count++;
        } else if (j < y) {
            j++;
            count++;
        } else {
            i--;
            j--;
            count++;
        }
    }

    printf("El número de pasos necesarios para llegar a la caja (%d,%d) es: %d\n", x, y, count);
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long DoraExplorer(unsigned long a, unsigned long b, unsigned long n) {

    n = ((a + b - 1) * (a + b) / 2 + 1);

    if((a+b)%2==0)
        n-=a;
    else
        n-=b;
    printf("%lu \n", n);
    
}

int main() {

    unsigned long x=0, y=0, n=0;

    while(scanf("%lu", &x) && scanf("%lu", &y) && x > 0 && y > 0) {
        DoraExplorer(x, y, n);
    }

    return 0;
}


/*
/*
int main() {
    
    unsigned long x=0, y=0, n=0;

    while(scanf("%lu", &x) && scanf("%lu", &y) && x > 0 && y > 0) {

        n=((x+y-1)*(x+y)/2+1);
        
        if((x+y)%2==0)
            n-=x;
        else
            n-=y;
            printf("%lu \n", n);
    }

    return 0;
}
*/


