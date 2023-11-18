#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion para intercambiar dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion para imprimir un arreglo
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Funcion para ordenar un arreglo usando el algoritmo Heapsort
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for(int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Funcion para particionar un arreglo en Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 1000;
    int arr_asc[n], arr_desc[n], arr_rand[n];

    // Generar arreglos de elementos ascendentes, descendentes y aleatorios
    for (int i = 0; i < n; i++) {
        arr_asc[i] = i;
        arr_desc[i] = n - i;
        arr_rand[i] = rand() % 1000; // Genera n�meros aleatorios entre 0 y 999
    }

    clock_t start, end;
    double cpu_time_used;

    // Medir el tiempo de ordenacion para elementos ascendentes
    start = clock();
    heapSort(arr_asc, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de Heapsort para elementos ascendentes: %f segundos\n", cpu_time_used);

    start = clock();
    quickSort(arr_asc, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de Quicksort para elementos ascendentes: %f segundos\n", cpu_time_used);
    printf("\n");


    // Medir el tiempo de ordenacion para elementos descendentes
    start = clock();
    heapSort(arr_desc, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de Heapsort para elementos descendentes: %f segundos\n", cpu_time_used);

    start = clock();
    quickSort(arr_desc, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de Quicksort para elementos descendentes: %f segundos\n", cpu_time_used);
    printf("\n");


    // Medir el tiempo de ordenacion para elementos aleatorios
    start = clock();
    heapSort(arr_rand, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de Heapsort para elementos aleatorios: %f segundos\n", cpu_time_used);

    start = clock();
    quickSort(arr_rand, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de Quicksort para elementos aleatorios: %f segundos\n", cpu_time_used);

    return 0;
}
