#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXT 1000000
#define infinite 2147483647

void MyMerge(int A[], int p, int q, int r) {  
    
    int i, j, k;
    int n1 = q - p + 1, n2 = r - q;
    int L[n1 + 2], R[n2 + 2];
    
    for(i=1; i <= n1; i++)
        L[i] = A[p + i - 1];
        
    for(j=1; j <= n2; j++)
        R[j] = A[q + j];
        
    L[n1 + 1] = infinite;
    R[n2 + 1] = infinite;
    i = 1;
    j = 1;
    
    for(k = p; k <= r; k++) {
        
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int p, int r) {
    
    int q;
    
    if(p < r) {
        q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        MyMerge(A, p, q, r);        
    }
}



int main() {

    int A[MAXT + 1], B[MAXT + 1], n, i, element;

    scanf("%d", &n);           
    for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    MergeSort(A, 1, n);

    for(i = 0; i <= n - 1; i++) {
        B[A[i - 1]] = 1;
        if(B[i] == 0) {
            element = A[i-1] - 1;
        }
    }
    
    printf("%d\n", element);
    printf("IMPOSSIBLE \n");
        
        

    return 0;
}