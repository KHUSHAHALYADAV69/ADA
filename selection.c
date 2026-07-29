#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    // Move boundary of unsorted subarray one by one
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            // To sort in descending order, change '<' to '>'
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// Function to print the array elements
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {64, 25, 12, 22, 11};
    int n = sizeof(data) / sizeof(data[0]); // Calculate array size

    printf("Original array:\n");
    printArray(data, n);

    selectionSort(data, n);

    printf("\nSorted array in ascending order:\n");
    printArray(data, n);

    return 0;
}
