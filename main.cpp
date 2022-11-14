#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace  std;

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
        swap(arr[min_idx], arr[i]);
    }
}

//bubble sort function
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

//insertion sort function
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

/* Function to merge the two haves arr[l..m] and
   arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}



/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



// A function to heapify the array
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


int main() {


    //initialize variables
    int arr1[10000], arr2[10000], arr3[10000], arr4[10000], arr5[10000], arr6[10000];
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    int og1[10000], og2[10000], og3[10000], og4[10000], og5[10000], og6[10000];
    int n = 10000;
    //initialize random seed
    srand (time(NULL));

    //generate random numbers for each array
    for(int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
        arr5[i] = arr1[i];
        arr6[i] = arr1[i];
    }
    copy(arr1, arr1+10000, og1);
    copy(arr2, arr2+10000, og2);
    copy(arr3, arr3+10000, og3);
    copy(arr4, arr4+10000, og4);
    copy(arr5, arr5+10000, og5);
    copy(arr6, arr6+10000, og6);
    //initialize output file streams and open files
    ofstream outFile1;
    outFile1.open("../data/selection.txt");

    ofstream outFile2;
    outFile2.open("../data/bubble.txt");

    ofstream outFile3;
    outFile3.open("../data/insertion.txt");

    ofstream outFile4;
    outFile4.open("../data/merge.txt");

    ofstream outFile5;
    outFile5.open("../data/quick.txt");

    ofstream outFile6;
    outFile6.open("../data/heap.txt");

    for(int i = 0; i<10000; i+=100)
    {
        auto start = chrono::high_resolution_clock::now();
        copy(og1, og1+10000, arr1);
        selectionSort(arr1, i);
        auto end = chrono::high_resolution_clock::now();
        auto duration  = chrono::duration_cast<std::chrono::microseconds>(end - start);
        outFile1 << duration.count()<<'\n';

         start = chrono::high_resolution_clock::now();
        copy(og2, og2+10000, arr2);
        bubbleSort(arr2, i);
         end = chrono::high_resolution_clock::now();
        duration  = chrono::duration_cast<std::chrono::microseconds>(end - start);
        outFile2 << duration.count()<<'\n';

        start = chrono::high_resolution_clock::now();
        copy(og3, og3+10000, arr3);
        insertionSort(arr3, i);
        end = chrono::high_resolution_clock::now();
        duration  = chrono::duration_cast<std::chrono::microseconds>(end - start);
        outFile3 << duration.count()<<'\n';

        start = chrono::high_resolution_clock::now();
        copy(og4, og4+10000, arr4);
        mergeSort(arr4,0, i-1);
        end = chrono::high_resolution_clock::now();
        duration  = chrono::duration_cast<std::chrono::microseconds>(end - start);
        outFile4 << duration.count()<<'\n';

        start = chrono::high_resolution_clock::now();
        copy(og5, og5+10000, arr5);
        quickSort(arr5,0, i-1);
        end = chrono::high_resolution_clock::now();
        duration  = chrono::duration_cast<std::chrono::microseconds>(end - start);
        outFile5 << duration.count()<<'\n';

        start = chrono::high_resolution_clock::now();
        copy(og6, og6+10000, arr6);
        heapSort(arr6, i);
        end = chrono::high_resolution_clock::now();
        duration  = chrono::duration_cast<std::chrono::microseconds>(end - start);
        outFile6 << duration.count()<<'\n';
    }
    outFile1.close();
    outFile2.close();
    outFile3.close();
    outFile4.close();
    outFile5.close();
    outFile6.close();
    string command = "python ../plots.py";
    system(command.c_str());
    return 0;
}
