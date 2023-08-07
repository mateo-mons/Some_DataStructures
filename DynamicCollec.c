#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXI 1000000000
#define MAXII 1000000
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
	
	int n, q, i, k, a, b, operation, encontrado = 0, mayor = 0;
	int A1[MAXI + 1], A2[MAXII + 1];

    scanf("%d %d", &n, &q);
    for(i = 1; i <= n; i++) 
        scanf("%d", &A1[i]);

	while(scanf("%d", &operation) != EOF) {
		if(operation == 1) { 	/* Insert */
			scanf("%d", &k);
            for(int i = 1; i < n; i++) {
                if (A1[i] == k) {
                    encontrado = 1;
                    break;
                }
            }

            for (int i = 0; i <= n; i++) {
                if(k <= A1[i]) {
                    mayor = 1;
                    break;
                }
                if(mayor) {
                    A1[i] = k;
                    for(i=1; i <= n; i++)
                        printf("%d ", A1[i]);
                }
            }



	/*		
		} else {
			if(operation == 2) { 	/* Extract 
				if( <= 0)
					printf("The min priority queue is empty. \n");
				else {
					
					printf("%d\n", );
				}		
			} else {
				printf("Bad use!\n 1.Insert\n 2.Extract\n");
			}
		*/}
	}
	
	return 0;
}