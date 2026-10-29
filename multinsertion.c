#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int currentElement = array[i];
        int j;

        for (j = i - 1; j >= 0 && array[j] > currentElement; j--)
        {
            array[j + 1] = array[j];
        }

        array[j + 1] = currentElement;
    }
}

int main()
{
    int size;
    int runs = 1000;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int array[size];
    int temp[size];

    srand(time(NULL));

    clock_t start = clock();

    for (int r = 0; r < runs; r++)
    {

        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 1000;
        }

        memcpy(temp, array, size * sizeof(int));

        insertion_sort(temp, size);
    }

    clock_t end = clock();

    double total_time =
        (double)(end - start) / CLOCKS_PER_SEC;

    double average_time = total_time / runs;

    printf("\nNumber of elements : %d", size);
    printf("\nNumber of runs     : %d", runs);
    printf("\nTotal time         : %lf seconds", total_time);
    printf("\nAverage time       : %lf seconds\n", average_time);

    return 0;
}