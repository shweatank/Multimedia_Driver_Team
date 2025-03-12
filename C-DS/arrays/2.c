//finding second largest element
#include <stdio.h>
#include <limits.h>

void findSecondLargest(int arr[], int n) 
{
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > largest) 
	{
            secondLargest = largest;
            largest = arr[i];
        }
       	else if (arr[i] > secondLargest && arr[i] != largest) 
	{
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN)
        printf("No second largest element\n");
    else
        printf("Second largest element is %d\n", secondLargest);
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSecondLargest(arr, n);
    return 0;
}

