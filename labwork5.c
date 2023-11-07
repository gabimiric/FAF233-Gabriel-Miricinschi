#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

void swap(double *x, double *y)
{
    double aux = *x;
    *x = *y;
    *y = aux;
}

void insertionSort(float* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        float aux = A[i];
        int j;
        for (j = i - 1; j >= 0 && A[j] > aux; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = aux;
    }
}

float floatrand(float n, float m)
{
    float random_float = ((float)rand()) / ((float)RAND_MAX);
    return n + (random_float * (m - n));
}

int intrand(int n, int m)
{
    return n + rand() % (m - n + 1);
}

float** allocate(int rows, int cols)
{
    float** A = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++)
    {
        A[i] = (float*)malloc(cols * sizeof(float));
        if (A[i] == NULL)
        {
            printf("Memory allocation failed. Exiting...\n");
            exit(1);
        }
    }
    return A;
}

void deallocate(int rows, float** A)
{
    for (int i = 0; i < rows; i++)
    {
        free(A[i]);
    }
    free(A);
}

void read(int rows, int cols, float** A)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }
}

void display(int rows, int cols, float** A)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

//Medium task: returns the index of the first occurrence of a specific value(to be read from console when the function is called).
int find(int *A, int k)
{
    int number;
    jump:
    printf("Input the number you want to find in the array: ");
    scanf("%d", &number);
    for (int i = 0; i < k; i++)
        if (A[i] == number)
            return i;
    printf("The number %d was not found in the array.\n", number);
    goto jump;
}

//Medium task: count how many times the target value(to be read from console when the function is called) appears in the array using pointers.
int counter(int *A, int k)
{
    int number, count = 0;
    printf("Input the number you want to count in the array: ");
    scanf("%d", &number);
    for (int i = 0; i < k; i++)
        if (A[i] == number)
            count++;
    return count;

}

//Easy task: implement a function that receives the 1D array of integers and returns the largest and smallest values in the array using pointers
void smallarge(int *A, int k)
{
    int max = A[0], min = A[0];
    for (int i = 0; i < k; i++)
    {
        if (A[i]>max) max = A[i];
        if (A[i]<min) min = A[i];
    }
    printf("The smallest number is %d.\nThe largest number is %d.\n", min, max);
}

int main()
{
    int n, m, end = 0, N_int, M_int, k;
    float N, M;
    float** A;
    int* B;
    char input, s[10];
    srand(time(NULL));

    printf("Input the size of the 1D array: ");
    scanf("%d", &k);
    B = (int*)malloc(k * sizeof(int));
    printf("Input the elements of the 1D array: ");
    for (int i=0; i<k; i++)
        scanf("%d", &B[i]);
    int found = find(B, k);
    printf("The instance of the number is at index %d.\n", found);
    int counted = counter(B, k);
    printf("The number appears %d times in the array.\n", counted);
    smallarge(B, k);

    printf("\n");

    do
    {
        printf("Input the size of the 2D array: ");
        scanf("%d %d", &n, &m);
        if (n != m)
            printf("Invalid input!\n");
    } while (n != m);

    do
    {
        printf("\n1. Dynamic memory allocation for two-dimensional tables\n2. Entering table elements from the keyboard\n3. Filling the array with random values\n4. Sorting the first and last line of the table in ascending order using the insertion sort method\n5. Displaying table elements on the screen\n6. Releasing the memory allocated to the table\n0. Exit program\nChoose one: ");
        scanf(" %c", &input);

        switch (input)
        {
            case '1':
                A = allocate(n, m);
                printf("Memory allocated.\n");
                break;
            case '2':
                read(n, m, A);
                break;
            case '3':
                do
                {
                    printf("Do you want int or float?\n");
                    scanf("%s", s);
                    if (strcmp(s, "float") == 0)
                    {
                        printf("Input the range of floats(N<M): ");
                        scanf("%f %f", &N, &M);
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++)
                                A[i][j] = floatrand(N, M);
                        printf("Array filled with random floats.\n");
                        break;
                    }
                    else if (strcmp(s, "int") == 0)
                    {
                        printf("Input the range of ints(N<M): ");
                        scanf("%d %d", &N_int, &M_int);
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++)
                                A[i][j] = (float)intrand(N_int, M_int);
                        printf("Array filled with random ints.\n");
                        break;
                    }
                        printf("Invalid input! Try again.\n");
                }while((strcmp(s, "float") != 0) && (strcmp(s, "int") != 0));
                break;
            case '4':
                insertionSort(A[0], m);
                insertionSort(A[n - 1], m);
                break;

            case '5':
                display(n, m, A);
                break;
            case '6':
                if (A != NULL)
                {
                deallocate(n, A);
                A = NULL;
                printf("Memory deallocated.\n");
                }
                else
                printf("No memory to deallocate.\n");
                break;
            case '0':
                printf("Exiting program...");
                end = 1;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (!end);

    return 0;
}
