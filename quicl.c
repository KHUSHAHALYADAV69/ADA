#include <stdio.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]); // added space for readability
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (i <= high && A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; // IMPORTANT: return pivot index
}

void quicksort(int A[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9; // FIXED size

    printarray(A, n);
    quicksort(A, 0, n - 1);
    printarray(A, n); // FIXED function name

    return 0;
}