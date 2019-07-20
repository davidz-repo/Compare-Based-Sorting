#include<stdio.h>
#include<math.h>

int heapSort(int * array, int size);
int buildMaxHeap(int * array, int n);
int heapify(int arr[], int size, int i);
int swap(int *a, int *b);

int main() {
	int size, i;
    int array[] = {0, 4, 8, 7, 3, 6, 10, 2, 1, 9};
    size = sizeof(array) / sizeof(int);
	heapSort(array, size);
	printf("Sorted: \n");
	for (i=0; i<size; i++)
    	printf(" %d ", array[i]);
	printf("\n");
    return 0;
}

int heapSort(int * array, int size){
    buildMaxHeap(array, size);
    while (size > 1){
        swap(&array[0], &array[size-1]);
        size--;
        heapify(array, size, 0);
    }
}

int buildMaxHeap(int * array, int size){
    /* use the original array to build max heap*/
    int i;
    for(i=(int)size/2; i>=0; i--){
        heapify(array, size, i);
    }
}

int heapify(int arr[], int size, int i){
    int parent = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left] > arr[parent]){
        parent = left;
	}
    if (right < size && arr[right] > arr[parent]){
        parent = right;
	}
    if (parent != i){
        swap(&arr[i], &arr[parent]);
        // recursion
        heapify(arr, size, parent);
    }
}

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
