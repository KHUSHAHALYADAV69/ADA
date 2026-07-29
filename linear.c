#include <stdio.h>
#include <time.h> // Required for clock_t, clock(), and CLOCKS_PER_SEC

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int data[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 70;

    // Variables to store clock ticks
    clock_t start_time, end_time;
    double cpu_time_used;

    // Record the start time
    start_time = clock();

    // Execute the search function
    int result = linearSearch(data, size, target);

    // Record the end time
    end_time = clock();

    // Calculate time taken in seconds
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Output results
    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    // Print the elapsed time with high precision
    printf("Time taken by linear search: %f seconds\n", cpu_time_used);

    return 0;
}
