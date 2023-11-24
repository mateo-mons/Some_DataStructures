#include<stdio.h>
#include<stdlib.h>

void intercambio(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

/*
int main() {
    int x, y;

    printf("Valor de x: ");
    scanf("%d", &x);

    printf("Valor de y: ");
    scanf("%d", &y);

    printf("Antes del intercambio: x = %d, y = %d\n", x, y);

    intercambio(&x, &y);

    printf("Despues del intercambio: x = %d, y = %d\n", x, y);

    return 0;
}
*/



int main(){ 
    int x [10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}, i;
    for (i = 0; i <= 9; ++i) { 
        printf("\nx [%d] = %d\t* (x + %d) = %d\t&x [%d] = %p\tx + %d = %p",i,x[i],i,* (x + i), i, &x[i],i,x + i); 
    } 
    printf("\n");

    return 0; 
} 

