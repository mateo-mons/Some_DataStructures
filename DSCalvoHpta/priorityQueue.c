#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define positiveInfinite 2147483647
#define negativeInfinite -2147483647
#define MAXT 10000

int Parent(int i) {
	return i / 2;
}

int Left(int i) {
	return 2 * i;
}

int Right(int i) {
	return 2 * i + 1;
}

void MinHeapify(int Q[], int i, int *heapSize) {
	
	int l, r, least, temp;
	
	l = Left(i);
	r = Right(i);
	
	if((l <= *heapSize) && (Q[l] < Q[i]))
		least = l;
	else
		least = i;
		
	if((r <= *heapSize) && (Q[r] < Q[least]))
		least = r;
		
	if(least != i) {
		temp = Q[i];
		Q[i] = Q[least];
		Q[least] = temp;
		MinHeapify(Q, least, &(*heapSize));
	}	
}

int MinPQ_Minimum(int Q[]) {
	return Q[1];
}

int MinPQ_Extract(int Q[], int *heapSize) {
	
	int min = negativeInfinite;
	
	if(*heapSize < 1)
		printf("Heap Underflow. \n");
	else {
		min = Q[1];
		Q[1] = Q[*heapSize];
		*heapSize = *heapSize - 1;
		MinHeapify(Q, 1, &(*heapSize));
	}
	return min;
}

void MinPQ_DecreaseKey(int Q[], int i, int key) {
	int temp;
	
	if(key > Q[i])
		printf("New key in higher than current key");
	else {
		Q[i] = key;
		while((i > 1) && (Q[Parent(i)] > Q[i])) {
			temp = Q[i];
			Q[i] = Q[Parent(i)];
			Q[Parent(i)] = temp;
			i = Parent(i);
		}
	}
}

void MinPQ_Insert(int Q[], int key, int *heapSize) {
	*heapSize = *heapSize + 1;
	Q[*heapSize] = positiveInfinite;
	MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main() {
	
	int operation, element, heapSize = 0, Q[MAXT + 1];
	
	while(scanf("%d", &operation) != EOF) {
		if(operation == 1) { 	/* Insert */
			scanf("%d", &element);
			MinPQ_Insert(Q, element, &heapSize);
		} else {
			if(operation == 2) { 	/* Extract */
				if(heapSize <= 0)
					printf("The min priority queue is empty. \n");
				else {
					element = MinPQ_Extract(Q, &heapSize);
					printf("%d\n", element);
				}		
			} else {
				printf("Bad use!\n 1.Insert\n 2.Extract\n");
			}
		}	
	}
	
	return 0;
}






























