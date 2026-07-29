#include <stdio.h>

// Function to perform an optimized bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped;

    // Outer loop runs n-1 times for the passes
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0; // Reset flag at the start of each pass

        // Inner loop handles adjacent comparisons
        // The last i elements are already in place, so we look at n-i-1 elements
        for (j = 0; j < n - i - 1; j++)
        {

            // To sort in descending order, change '>' to '<'
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1; // Mark that a swap occurred
            }
        }

        // Optimization: If no elements were swapped, the array is already sorted
        if (swapped == 0)
        {
            break;
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
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]); // Dynamically calculate size

    printf("Original array:\n");
    printArray(data, n);

    bubbleSort(data, n);

    printf("\nSorted array in ascending order:\n");
    printArray(data, n);

    return 0;
}
