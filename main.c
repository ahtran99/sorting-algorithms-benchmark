/*
 * Alexander Tran
 * March 25, 2022
 * Compare the performance of four sorting algorithms, including selection, bubble, quick and heap
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* The following header file defines clock_t datatype, clock() function, as well as the constant CLOCKS_PER_SEC */
#include <time.h>

void cloneArray(int arrB[], int arrA[], int size);
void printArray(int arr[], int size);
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void siftDown(int arr[], int size, int root);
void heapSort(int arr[], int size);
void siftUp(int heap[], int n);

int main() {
    int SIZE = 10000;

    //int arrA[SIZE], arrB[SIZE];
    int* arrA = (int *) malloc(SIZE * sizeof(int));
    int* arrB = (int *) malloc(SIZE * sizeof(int));

    FILE *fp, *G1, *G2, *G3, *G4;
    fp = fopen("test_dat.txt", "r");
    G1 = fopen("G1.txt", "w");
    G2 = fopen("G2.txt", "w");
    G3 = fopen("G3.txt", "w");
    G4 = fopen("G4.txt", "w");
    if (fp == NULL) {
        printf("Error opening test_dat.txt");
        exit(1);
    }

    //create array size according to user input and read values into array int array[someValue];
    int i, j, k, l, m;
    for (i = 0; i < SIZE; i++)
    {
        fscanf(fp, "%d", &arrA[i]);
    }

    puts("\nGet an array: ");
    cloneArray(arrB, arrA, SIZE);
    printArray(arrA, SIZE);

    clock_t start = clock();
    selectionSort(arrB, SIZE);
    double timeElapsed = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Time = %f ms\n", timeElapsed);
    printArray(arrB, SIZE);
    fprintf(G1, "Selection Sort\n");
    for (j = 0; j < SIZE; j++){
        fprintf(G1, "%d\n", arrB[j]);
    }

    cloneArray(arrB, arrA, SIZE);
    start = clock();
    bubbleSort(arrB, SIZE);
    timeElapsed = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Time = %f ms\n", timeElapsed);
    printArray(arrB, SIZE);
    fprintf(G2, "Bubble Sort\n");
    for (k = 0; k < SIZE; k++){
        fprintf(G2, "%d\n", arrB[k]);
    }

    puts("\nQuick Sort");
    cloneArray(arrB, arrA, SIZE);
    start = clock();
    quickSort(arrB, 0, SIZE - 1);
    timeElapsed = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Time = %f ms\n", timeElapsed);
    printArray(arrB, SIZE);
    fprintf(G3, "Quick Sort\n");
    for (l = 0; l < SIZE; l++){
        fprintf(G3, "%d\n", arrB[l]);
    }

    cloneArray(arrB, arrA, SIZE);
    start = clock();
    siftUp(arrB, SIZE);
    heapSort(arrB, SIZE);
    timeElapsed = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Time = %f ms\n", timeElapsed);
    printArray(arrB, SIZE);
    fprintf(G4, "Heap Sort\n");
    for (m = 0; m < SIZE; m++){
        fprintf(G4, "%d\n", arrB[m]);
    }
    printf("\n");

    free(arrA);
    free(arrB);

    fclose(fp);
    fclose(G1);
    fclose(G2);
    fclose(G3);
    fclose(G4);
}

void cloneArray(int arrB[], int arrA[], int size) {
    for (int i = 0; i < size; i++)
        arrB[i] = arrA[i];
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    puts("\nSelection Sort");
    int comp = 0, swp = 0;
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                comp++;
            }
        }
        swap(&arr[min_idx], &arr[i]);
        swp++;
    }
    printf("No. comparisons = %d; No. swaps = %d\n", comp, swp);
}

void bubbleSort(int arr[], int n) {
    puts("\nBubble Sort");
    int comp = 0, swp = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
                swp++;
            }
            comp++;
        }
        if (swapped == false) break;
    }
    printf("No. comparisons = %d; No. swaps = %d\n", comp, swp);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // takes last element as pivot
    int i = low; // Index of the first greater element
    for (int j = low; j < high - 1; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]); //put pivot to its place
    return i; //return the new partitioning index
}

/* The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index */
void quickSort(int arr[], int low, int high) {
    //puts("\nQuick Sort");
    if (low < high) {
        // pi is partitioning index
        // arr[p] is now at right place
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// To heapify a subtree rooted with node root which is
// an index in arr[]. size is the size of heap
void siftDown(int arr[], int size, int root) {
    int temp = arr[root];
    int child = 2*root + 1;
    while (child < size) {
        if (child < size-1 && arr[child] < arr[child+1])
            child++; //choose root of right subtree
        if (temp >= arr[child]) break; //root is good now
        arr[root] = arr[child]; //copy max child to root
        root = child; //move down to continue
        child = 2*root + 1; //left child
    }
    arr[root] = temp; //put “bad” root to proper place
}

void heapSort(int arr[], int size) {
    puts("\nHeap Sort");
    // Build heap (rearrange array, i.e. heapify)
    for (int i = size/2 - 1; i >= 0; i--)
        siftDown(arr, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        siftDown(arr, i, 0); //heapify the root
    }
}

void siftUp(int heap[], int n) { //siftUp item n
    int siftItem = heap[n];
    int child = n;
    int parent = (child - 1) / 2;
    while (child > 0) {
        if (siftItem <= heap[parent]) break;
        heap[child] = heap[parent];
        child = parent;
        parent = (child - 1) / 2;
    }
    heap[child] = siftItem;
}