#include<stdio.h>
#include<stdlib.h>

// EVALUACION DE UN POLINOMIO P(x) EN FORMA ITERATIVA

float evaluaPolinomio(float *coef, int tam, float x) {
    float total = 0;
    for(int i=tam; i>=0; i--) {
        float xn = 1.0;
        for(int j=0; j<i; j++) 
            xn *= x;

        total += coef[tam-i] * xn;
        printf("\nTotal: %.2f", total);
    }
    return total;
}

int main() {

    float *poli, x;
    int tam, j;
    printf("Ingrese el tamaño del polinomio: ");
    scanf("%d", &tam);
    poli = (float*) malloc(sizeof(float)*(tam));

    for(j=0; j<=tam; j++) {
        printf("Ingresa el coeficiente de la potencia %d: ", tam-j);
        scanf("%f", &poli[j]);
    }

    printf("Ingresa el valor de x a evaluar: ");
    scanf("%f", &x);
    printf("\nP(%.2f) = %.2f\n", x, evaluaPolinomio(poli, tam, x));

    getchar();
    getchar();

    return 0;
}


// EVALUACION DE UN POLINOMIO P(x) EN FORMA RECURSIVA I
/*
float potencia(float x, int y) {
    float t;
    if(y == 0)
        return 1.0;
    
    if(y % 2 == 1)
        return x * potencia(x, y-1);
    else {
        t = potencia(x, y/2);
        return t * t;
    } 
}

float evaluaPolinomio(float *coef, int tam, float x) {
    float total = 0;
    for(int i=tam; i>=0; i--) {
        total += coef[tam-1] * potencia(x, 1);
        printf("\nTotal = %.2f", total);
    }
    return total;
}

int main() {

    float *poli, x;
    int tam, j;
    printf("Ingresa el tamaño del polinomio: ");
    scanf("%d", &tam);
    poli = (float *) malloc(sizeof(float)*(tam+1));
    for(j=0; j<=tam; j++) {
        printf("Ingresa el coeficiente de la potencia %d: ", tam-j);
        scanf("%f", &poli[j]);
    }

    printf("Ingresa el valor de x a evaluar: ");
    scanf("%f", &x);
    printf("\nP(%.2f) = %.2f\n", x, evaluaPolinomio(poli, tam, x));

    getchar();
    getchar();

    return 0;
}
*/
// EVALUACION DE UN POLINOMIO P(x) EN FORMA RECURSIVA II
/*
float potencia(float x, int y) {
    float t;
    if(y == 0)
        return 1.0;
    
    if(y == 1)
        return x;
    
    if(y % 2 == 1)
        return x * potencia(x * x, y/1);
    else {
        return potencia(x * x, y/2);
    } 
}

float evaluaPolinomio(float *coef, int tam, float x) {
    float total = 0;
    for(int i=tam; i>=0; i--) {
        total += coef[tam-1] * potencia(x, 1);
        printf("\nTotal = %.2f", total);
    }
    return total;
}

int main() {

    float *poli, x;
    int tam, j;
    printf("Ingresa el tamaño del polinomio: ");
    scanf("%d", &tam);
    poli = (float *) malloc(sizeof(float)*(tam+1));
    for(j=0; j<=tam; j++) {
        printf("Ingresa el coeficiente de la potencia %d: ", tam-j);
        scanf("%f", &poli[j]);
    }

    printf("Ingresa el valor de x a evaluar: ");
    scanf("%f", &x);
    printf("\nP(%.2f) = %.2f\n", x, evaluaPolinomio(poli, tam, x));

    getchar();
    getchar();

    return 0;
}
*/
// EVALUACION DE UN POLINOMIO P(x) POR DIVISION SINTETICA
/*
float divide(float p[], int n, float x) {
    float a = p[0];
    for(int i=1; i<=n; i++)
        a = a*x+p[i];
    
    return(a);
}

int main() {

    float *poli, x;
    int tam, j;

    printf("Ingresa el tamaño del polinomio: ");
    scanf("%d", &tam);
    poli = (float *) malloc(sizeof(float)*(tam+1));

    for(j=0; j<=tam; j++) {
        printf("Ingresa el coeficiente de la potencia %d: ", tam-j);
        scanf("%f", &poli[j]);
    }

    printf("Ingresa el valor de x a evaluar: ");
    scanf("%f", &x);
    printf("\nP(%.2f) = %.2f\n", x, divide(poli, tam, x));

    getchar();
    getchar();

    return 0;
}
*/