#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int HowManyTriangularNumbers(int a, int b) {
    int count = 0;
    int n = 1;
    
    while (n * (n + 1) / 2 <= b) {
        if (n * (n + 1) / 2 >= a) {
            count++;
        }
        n++;
    }
    
    return count;
}

int main() {
    int start, end;
    while ((scanf("%d ", &start) && (start > 0)) && 
            (scanf("%d ", &end) && (end > 0))) {
        int count = HowManyTriangularNumbers(start, end);
        printf("%d\n", count);
    }
    
    //scanf("%d \n", &start);
    //scanf("%d", &end);
    //int count = how_many_triangular_numbers(start, end);
    //printf("Hay %d numeros triangulares en el rango [%d, %d] \n", count, start, end);
    return 0;
}