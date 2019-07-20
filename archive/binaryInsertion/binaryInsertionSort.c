#include <stdio.h>

int loc_binarySearch(int* Best, int key, int low, int high);
void insertionSort(int* Best, int n);

// Driver program to test above function
int main()
{
	int unsorted[] = {13,15,17,19,21,23,25,27,29,31};

	int top5[5], sorted5[5];
	for (int i=0; i<5; i++){
		Best[i] = -1;
	}

	printf("%d",loc_binarySearch(a, 26, 0, 10));
	/*
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
	*/

	return 0;
}

int loc_binarySearch(int* Best, int key, int low, int high){
	int mid, pos;
	while (low <= high){
		mid = (high + low) / 2;
		pos = Best[mid];
		if (Best[mid] > key){
			high = mid;
		}
		if (Best[mid] < key){
			low = mid + 1;
		}
	}
	return mid + 1;
}

// Function to sort an array a[] of size 'n'
void insert(int a[], int n){

}
