#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

double n, A[MAX_SIZE], B[MAX_SIZE];

void swap(double *x, double *y)
{
    double aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSort(double A[])
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
}

void insertionSort(double A[])
{
    for (int i = 0; i < n; i++)
    {
        double aux = A[i];
        int j;
        for (j = i - 1; j >= 0 && A[j] > aux; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = aux;
    }
}

int partition(double A[], int start, int end)
{
    double pivot = A[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    i++;
    swap(&A[i], &A[end]);
    return i;
}

void quicksort(double A[], int start, int end)
{
    if (end <= start)
        return;

    int pivot = partition(A, start, end);
    quicksort(A, start, pivot - 1);
    quicksort(A, pivot + 1, end);
}

void selectSort(double A[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        swap(&A[i], &A[min]);
    }
}

int maxp(double A[])
{
    int j = 0;
    for (int i = 0; i < n; i++)
        if (A[j] < A[i])
            j = i;
    return j;
}

int minp(double A[])
{
    int j = 0;
    for (int i = 0; i < n; i++)
        if (A[j] >= A[i])
            j = i;
    return j;
}

int right(int i)
{
    int k = 0;
    for (int j = i; j < n; j++)
        if (A[j] < 0)
            k++;
    return k;
}

int left(int i)
{
    int k = 0;
    for (int j = i; j > 0; j--)
        if (A[j] > 0)
            k++;
    return k;
}

int main()
{
    clock_t t;

    // Input: Array size (up to MAX_SIZE)
    do
    {
        printf("Enter the size of the array (1-%d): ", MAX_SIZE);
        scanf("%lf", &n);
    } while (n < 1 || n > MAX_SIZE);

    // Input: Array elements
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &A[i]);
        B[i] = A[i]; // Copy of A for use in all algorithms
    }

    printf("\n");

    printf("The amount of negative numbers to the right of the max value: %d\n", right(maxp(A)));
    printf("The amount of positive numbers to the left of the min value: %d\n\n", left(minp(A)));

    t = clock();
    // Sort the array using bubblesort
    bubbleSort(A);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("bubbleSort took %f seconds to execute \n", time_taken);
    // Output: Sorted array
    printf("BubbleSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.2lf ", A[i]);

    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

    printf("\n\n");

    t = clock();
    // Sort the array using insertion sort
    insertionSort(A);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("insertSort took %f seconds to execute \n", time_taken);

    // Output: Sorted array
    printf("InsertSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.2lf ", A[i]);

    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

    printf("\n\n");

    t = clock();
    // Sort the array using quicksort
    quicksort(A, 0, n - 1);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("quicksort took %f seconds to execute \n", time_taken);

    // Output: Sorted array
    printf("QuickSorted array : ");
    for (int i = 0; i < n; i++)
        printf("%.2lf ", A[i]);

    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

    printf("\n\n");

    t = clock();
    // Sort the array using selection sort
    selectSort(A);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("selectSort took %f seconds to execute \n", time_taken);

    // Output: Sorted array
    printf("SelectSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", A[i]);
    }
    return 0;
}
