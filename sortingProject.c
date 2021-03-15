#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n\n\n"); 
}

void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    for(i = 0; i < n-1; i++) {
        swapped = 0;
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if(swapped == 0) 
            break;
    }
}

void insertionSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 1; i < n; i++)
    { 
        j = i - 1;
        while (j >= 0 && arr[j] > arr[j+1])
        { 
            swap(&arr[j], &arr[j + 1]);
            j = j - 1; 
        } 
    } 
}

void insertionSort2(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j];
            j = j - 1; 
        }
        arr[j + 1] = key;
    } 
} 

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  

    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  

        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}

int partition(int arr[], int left, int right) {

    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);
    return i;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {

        // Select pivot position and put all the elements smaller 
        // than pivot on left and greater than pivot on right
        int pi = partition(arr, left, right);

        // Sort the elements on the left of pivot
        quickSort(arr, left, pi - 1);

        // Sort the elements on the right of pivot
        quickSort(arr, pi + 1, right);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

#define MAX_SIZE 160000

int main() {
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int arr[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++) {
        arr[i] = (rand() % 1000);
    }


    int cArr[MAX_SIZE];
    int n = MAX_SIZE;

    // Creating a copy of initial arr to have consistent data
    
    printf("Array size: %d\n\n", MAX_SIZE);

    clock_t start, end;
    double time_used;

    for(int i = 0; i < n; i++){
            cArr[i] = arr[i];
    }
    start = clock();
        bubbleSort(cArr, n);
    end = clock();
    time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("Sorted array BubbleSort: \n Time used %f s\n\n\n", time_used); 
    // printArray(cArr1, n); 
    
    for(int i = 0; i < n; i++){
            cArr[i] = arr[i];
    }
    start = clock();
        insertionSort(cArr, n);
    end = clock();
    time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("Sorted array InsertionSort: \n Time used %f s\n\n\n", time_used); 
    // printArray(cArr2, n); 

    for(int i = 0; i < n; i++){
            cArr[i] = arr[i];
    }
    start = clock();
        selectionSort(cArr, n);
    end = clock();
    time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("Sorted array SelectionSort: \n Time used %f s\n\n\n", time_used); 
    // printArray(cArr3, n);

    for(int i = 0; i < n; i++){
            cArr[i] = arr[i];
    }
    start = clock();
        quickSort(cArr, 0, n - 1);
    end = clock();
    time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("Sorted array QuickSort: \n Time used %f s\n\n\n", time_used); 
    // printArray(cArr4, n); 

    for(int i = 0; i < n; i++){
            cArr[i] = arr[i];
    }
    start = clock();
        mergeSort(cArr, 0, n - 1);
    end = clock();
    time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("Sorted array MergeSort: \n Time used %f s\n\n\n", time_used); 
    // printArray(cArr4, n); 

    return 0;
}