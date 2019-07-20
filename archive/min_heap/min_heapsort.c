#include<stdio.h>
#include "COMPARE.c"
#define L 10

void heapSort(int n, int *A);
void build_min_heap(int n, int *A);
void heapify(int n, int *A, int i);
void swap(int *a, int *b);

int main() {

	int n, i;
    int Array[] = {700, 400, 900, 500, 600, 800, 1000, 200, 300, 100};
	int Brray[L];
    n = L;
	printf("The UNSORTED:\n");
	for(i=0;i<n;i++){
    	printf(" %d ", Array[i]);
	}
	printf("\nThe size of the array is %d\n", n);
	heapSort(n, Array);
	printf("The SORTED:\n");
	for(i=0;i<n;i++){
    	printf(" %d ", Array[i]);
	}
	printf("\n");
    return 0;
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
	int smallest = i; // key of the parent node
	if (left < n && A[left] < A[i]) {
		smallest = left; // if larger, swap the key
	}
	// within range, compare the right child with the parent
	if (right < n && A[right] < A[smallest]) {
		smallest = right; // if larger, swap the key
	}
	if (smallest != i) {
		swap(&A[i], &A[smallest]);// if the key changes, swap the values
		heapify(n, A, smallest);// call the recursive heapify funtion
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
