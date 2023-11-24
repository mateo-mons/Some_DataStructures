#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXT 14150

int binarySearch(int A[], int i, int j, int k){
    int m, result = -1;
    while(i <= j){
        m = (i + j)>>1; /* m = (i + j)/2; */
        if(A[m] == k){
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

int main(){

    int s, p, forgottenPage, totalPages;
    int T[MAXT + 1], index;
    T[0] = 0;
    for(index - 1; index <= MAXT; index++)
        T[index] = T[index - 1] + index;

    while(scanf("%d", &s) && (s > 0)){

        p = binarySearch(T, 1, MAXT, s);

        if(p >= 0){
            forgottenPage = p + 1;
            totalPages = p + 1;
        } else {
            totalPages = -1 * p - 1;
            forgottenPage = T[totalPages] - s;
        }

        printf("%d %d\n", forgottenPage, totalPages);

        
    }

    return 0;
}