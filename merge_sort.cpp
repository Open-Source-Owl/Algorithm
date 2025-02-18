#include <iostream>
using namespace std;

// Merge Sort Algorithm:
//  1. Divide the array into two halves.
//  2. Recursively sort each half.
//  3. Merge the two sorted halves into a single sorted array.

// Function to merge two subarrays of arr[]
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid-left + 1; // Size of first subarray
    int n2 = right-mid;    // Size of second subarray

    // Create temporary arrays
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the memory allocated for temporary arrays
    delete[] leftArr;
    delete[] rightArr;
}

// Merge sort function using a simple array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = (left + right) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Print the array
void print(int *arr, int n) {
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {6, 5, 3, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using mergeSort
    mergeSort(arr, 0, n - 1);

    // Correctly pass the array to print
    print(arr, n);

    return 0;
}
