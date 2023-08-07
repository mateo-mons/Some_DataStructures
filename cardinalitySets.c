#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXT 1000000000
#define infinite 2147483647

int binarySearch (int A[] , int i, int j, int k) {
    int m, result = -1;
    while (i <= j) {
        m = (i + j)>1;
        if(A[m] == k) {
            result = m;
            break ;
        } else {
            if(k > A[m])
            i = m + 1;
        else
            j = m - 1;
        }
    }
    if( result == -1)
        result = ( -1) * i - 1;
    return result ;
}

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

	int m, n, i;

	while(scanf("%d %d", &m, &n) && (m > 0) && (n > 0)) {
		if(m == 0 && n == 0)
			break;
		
		int setA[m], element;
		int AnB = 0, AminusB, BminusA, AuB;

		for(i = 0; i < m; i++)
			scanf("%d", &setA[i]);

		MergeSort(setA, 0, m - 1);

		for(i = 0; i < n; i++) {
			scanf("%d", &element);
			if(binarySearch(setA, 0, m - 1, element) >= 0)
				AnB++;
		}

		AminusB = m - AnB;
		BminusA = n - AnB;
		AuB = m + n - AnB;
		printf("%d %d %d %d\n", AminusB, AnB, BminusA, AuB);
	}
	
	return 0;
}

	

 

