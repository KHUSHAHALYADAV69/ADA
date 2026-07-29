#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;

    // Loop from the second element (index 1) to the end of the array
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // The current element to be inserted
        j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than the key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Place the key into its correct sorted position
        arr[j + 1] = key;
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
    int data[] = {12, 11, 13, 5, 6};
    int n = sizeof(data) / sizeof(data[0]); // Dynamically calculate size

    printf("Original array:\n");
    printArray(data, n);

    insertionSort(data, n);

    printf("\nSorted array in ascending order:\n");
    printArray(data, n);

    return 0;
}
