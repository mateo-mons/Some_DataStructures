#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

int triangular(int n) {
    return n * (n + 1) / 2;
}


int contar_formas(int n) {
    unsigned long long formas = 0;    
  
    for (int i = 1; triangular(i) <= n; i++) {
        if (triangular(i) == n) {
            formas++;
        }
    }

    for (int i = 1; triangular(i) <= n; i++) {
        for (int j = i; triangular(i) + triangular(j) <= n; j++) {
            if (triangular(i) + triangular(j) == n) {
                formas++;
            }
        }
    }
    
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
    int t, n;       

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        
        scanf("%d\n", &n);
        
        int resultado = contar_formas(n);
        
        printf("%d\n", resultado);
    }
    return 0;
}
*/

#define MAXT 446
#define MAXN 100000
#define MAXL 7861110
#define infinite 2147483647

//Total numbers: 7861110
int A[MAXL + 1];

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

int binarySearch(int A[], int i, int j, int k) {
    int m, result = -1;
    while(i <= j) {
        m = (i + j)>>1; /* m = (i + j)/2; */
        if(A[m] == k) {
            result = m;
            break;
        } else {
            if(k > A[m])
                i = m + 1;
            else
                j = m - 1;
        }
    }
    if(result == -1)
        result = (-1) * i - 1;

    return result;
}

int binarySearchFirstOcurrence (int A[], int i, int j, int k) {
    int result , result2 ;
    result = binarySearch (A, i, j, k);
   
    if( result >= 0) {
        result2 = binarySearch (A, i, result - 1, k) ;
        while ( result2 >= 0) {
            result = result2 ;
            result2 = binarySearch (A, i, result - 1, k) ;
        }
    }
   
    return result ;
}

int binarySearchLastOcurrence (int A[], int i, int j, int k) {
    int result , result2 ;
    result = binarySearch (A, i, j, k);
   
    if( result >= 0) {
        result2 = binarySearch (A, result + 1, j, k) ;
        while ( result2 >= 0) {
            result = result2 ;
            result2 = binarySearch (A, result + 1, j, k) ;
        }
    }
   
    return result ;
}

int main() {
    int t, n, idCase, TN[MAXT + 1];
    int i, j, k, number, idNumber = 0;
    int total_numbers;
    int idFirst, idLast;
    TN[0] = 0;
   
    for(i = 1; i <= MAXT; i++) {
        TN[i] = TN[i - 1] + i;
    }
   
    for(i = 0; i <= MAXT; i++) {
        for(j = i; j <= MAXT; j++) {
            for(k = j; k <= MAXT; k++) {
                number = TN[i] + TN[j] + TN[k];
                if(number <= MAXN) {
                    idNumber++;
                    A[idNumber] = number;
                }
            }
        }
    }
   
    total_numbers = idNumber;
    MergeSort(A, 1, total_numbers);
   
   
    scanf("%d", &t);
    for(idCase = 1; idCase <= t; idCase++) {
        scanf("%d", &n);
        idFirst = binarySearchFirstOcurrence(A, 1, total_numbers, n);
        idLast = binarySearchLastOcurrence(A, idFirst, total_numbers, n);
        printf("%d\n", idLast - idFirst + 1);
       
    }
   
    return 0;
}