#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define infinite 2147483647
#define MAXN 1000000

long long int inv = 0;

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
            inv += n1 - i + 1;
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
    
    int A[MAXN + 5], i, n;
    
    while(scanf("%d", &n) && (n > 0)) {
    
        inv = 0;
        for(i=1; i <= n; i++)
            scanf("%d", &A[i]);
        
                    
        MergeSort(A, 1, n);
        printf("%lld \n", inv);
    }
    return 0;
}

















