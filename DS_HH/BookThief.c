#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    int s, p, triangular, forgottenPage, totalPages;

    while(scanf("%d", &s) && (s > 0)){

        p = (-1 + sqrt(1 + 8 * s)) / 2;
        triangular - (p * (p + 1)) / 2;

        if(s == triangular){

            forgottenPage = p + 1;
            totalPages = p + 1;
        }
        else{
            totalPages = p + 1;
            forgottenPage = ((totalPages * (totalPages + 1)) / 2) - s;
        }

        printf("%d %d\n", forgottenPage, totalPages);

        
    }

    return 0;
}