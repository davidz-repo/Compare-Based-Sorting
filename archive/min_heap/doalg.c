#include<stdio.h>
#define L 100000
int A[L];

int doalg(int n, int k, int *Best);
void heapSort(int n, int *A);
void build_min_heap(int n, int *A);
void heapify(int n, int *A, int i);
void swap(int *a, int *b);

int doalg(int n, int k, int *Best) {
    int i, j;
    for (i = 0; i < n; i++){
		A[i] = i+1;
    }
    heapSort(n, A);
    for (j = 0; j < k; j++){
 		Best[j] = A[j];
    }
    return 1;
}

void heapSort(int n, int *A){
	build_min_heap(n, A);
	for (int i=n-1; i>=0; i--) {
        swap(&A[0], &A[i]);// get the max value from heap(A[0]) and swap to the bottom
        // call heapify for the new heap (note: new heap means the previous heap removing the last element)
        heapify(i, A, 0); // note the heap size we pass here is not n but i
    }
}

void build_min_heap(int n, int *A) {
	/* represent the array A with total elements n into a heap */
	for(int i = (n - 1) / 2; i != -1; i--){
		heapify(n, A, i);
	}
}
void heapify(int n, int *A, int i) {
	/* maintain the property of the heap*/
	int left = 2 * i + 1; // key of the left child
	int right = 2 * (i + 1); // key of the right child
	int SMALLEST = i; // key of the parent node
	if (left < n && COMPARE(A[left],A[i])==2) {
		SMALLEST = left; // if larger, swap the key
	}
	// within range, compare the right child with the parent
	if (right < n && COMPARE(A[right],A[SMALLEST])==2) {
		SMALLEST = right; // if larger, swap the key
	}
	if (SMALLEST != i) {
		swap(&A[i], &A[SMALLEST]);// if the key changes, swap the values
		heapify(n, A, SMALLEST);// call the recursive heapify funtion
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
