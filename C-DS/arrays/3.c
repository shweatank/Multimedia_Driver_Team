//Moving all zeroes to end
#include <stdio.h>
void moveZeroesToEnd(int arr[], int n) 
{
    int j = 0; // Pointer for non-zero elements

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, n);
    printArray(arr, n);
    return 0;
}

