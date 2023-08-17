/*
	// VERSION 1.0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXT 500000

int main() {
	
	int A[MAXT + 1], n, q, i, j, s, idQuery;
	long long int result;
	
	scanf("%d %d", &n, &q);
	
	for(i = 1; i <= n; i++)
		scanf("%d", &A[i]);
		
	for(idQuery = 1; idQuery <= q; idQuery++) {
		scanf("%d", &s);
		result = 0;
		for(i = 1; i < n; i++) {
			for(j = i + 1; j <= n; j++) {
				if((A[i] + A[j]) <= s)
				result++;
			}
		}
		printf("%lld \n", result);
	}
	
	
	
	return 0;
}
*/

/*

	// VERSION 2.0
	
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXT 500000
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
	
	int A[MAXT + 1], n, q, i, j, s, idQuery;
	long long int result;
	
	scanf("%d %d", &n, &q);
	
	for(i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	
	MergeSort(A, 1, n);
		
	for(idQuery = 1; idQuery <= q; idQuery++) {
		scanf("%d", &s);
		result = 0;
		printf("\n");
		for(i = 1; i < n; i++) {
			for(j = i + 1; j <= n; j++) {
				if((A[i] + A[j]) <= s)
					result++;
				else
					break;
			}
		}
		printf("%lld \n", result);
	}
		
	return 0;
}

*/

	// VERSION 3.0
	
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXT 500000
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

int main() {
	
	int A[MAXT + 1], n, q, i, s, idQuery, element, index;
	long long int result;
	
	scanf("%d %d", &n, &q);
	
	for(i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	
	MergeSort(A, 1, n);
	
	for(idQuery = 1; idQuery <= q; idQuery++) {
		scanf("%d", &s);
		result = 0;

		for(i = 1; i < n; i++) {
			element = s - A[i];
			if(element > A[i]) {
				index = binarySearch(A, i + 1, n, element);
				if(index < 0){
					index += 2;
					index *= -1;
				}
				result += index - i;
			} else {
				break;
			}
			
		}
		printf("%lld \n", result);
	}
		
	return 0;
}


//	PART OF SOLUTION OF IMPOSSIBLE CHALLENGE

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 1000000

int main() {
    
    int A[MAXT + 1], n, i;
    while(scanf("%d", &n) != EOF) {
        for(i = 1; i <= n - 1; i++)
            scanf("%d", &A[i]);
        printf("%d \n", A[n - 1]);
    }

        
    return 0;
}
*/

























