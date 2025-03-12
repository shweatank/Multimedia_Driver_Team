//Find the K-th smallest element in an unsorted array.
#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
	{
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i]; arr[i] = arr[high]; arr[high] = temp;
    return i;
}

int quickSelect(int arr[], int low, int high, int k) 
{
    if (low <= high) 
    {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        return (pi > k) ? quickSelect(arr, low, pi - 1, k) 
                        : quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 4, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    printf("K-th smallest element: %d\n", quickSelect(arr, 0, n - 1, k - 1));
    return 0;
}

