#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long DangiesFunction(unsigned long long n) {
    
    unsigned long long result = 0;

    result = (n * (n - 1) * (n + 1)) / 3; 
    
    return result;
}

int main() {
    int num_inputs;
    unsigned long long n;
    scanf("%d", &num_inputs);

    for (int i = 0; i < num_inputs; i++) {
        scanf("%llu", &n);
        unsigned long long result = DangiesFunction(n);
        printf("%llu\n",result);
    }

    return 0;
}

