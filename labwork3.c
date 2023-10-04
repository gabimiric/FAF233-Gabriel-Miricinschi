#include <stdio.h>
#include <math.h>

#define MAX 20

int N,M;
float A[MAX][MAX], B[MAX*MAX];

void swap(float *x, float *y)
{
    float aux = *x;
    *x = *y;
    *y = aux;
}

//Calculates the produce of each column
void prodcolumns(float A[MAX][MAX])
{
    for (int j=0; j<M; j++)
    {
        float P=1;
        for (int i=0; i<N; i++)
            if (A[i][j]!=0)
            {
                P*=A[i][j];
            }
        printf("The produce of all non-zero elements from column %d is: %.2f \n", j+1, P);
    }
    printf("\n");
}

//Calculates the sum on the perimeter of the array
void sumperimeter(float A[MAX][MAX])
{
    float S=0;
    for (int j=0; j<M; j++)
        S+=A[0][j];
    for (int j=0; j<M; j++)
        S+=A[N-1][j];
    for (int i=1; i<N-1; i++)
        S+=A[i][0];
    for (int i=1; i<N-1; i++)
        S+=A[i][M-1];
    printf("The sum of the elements around the perimeter of the matrix is: %.2f\n", S);
}

int partition(float A[], int start, int end)
{
    float pivot = A[end];
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

void quicksort(float A[], int start, int end)
{
    if (end <= start)
        return;

    int pivot = partition(A, start, end);
    quicksort(A, start, pivot - 1);
    quicksort(A, pivot + 1, end);
}

//Converts the bi dimensional array into a one dimensional array
void Convert(float B[MAX*MAX], float A[MAX][MAX])
{
    int k=0;
    for (int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            B[k]=A[i][j];
            k++;
        }
}

void spiral(float A[MAX][MAX], float B[MAX * MAX], int row, int col)
{
    int o=row, p=col, k=0;
    int i, j;
    while (p>0 && o>0)
    {
        //right
        for (j=M-p; j<p && k<N*M; j++)
        {
            A[N-o][j]=B[k];
            k++;
        }
        //down
        for (i=N-o+1; i<o && k<N*M; i++)
        {
            A[i][p-1]=B[k];
            k++;
        }
        o--;
        p--;
        //left
        for (j=p-1; j>=M-p-1 && k<N*M; j--)
        {
            A[i-1][j]=B[k];
            k++;
        }
        //up
        for (i=o-1; i>=N-o && k<N*M; i--)
        {
            A[i][j+1]=B[k];
            k++;
        }
    }
}
int main()
{
    printf("Insert number of rows and columns (up to %d):", MAX);
    scanf("%d %d", &N, &M);

    if (N<=0 || N>MAX || M<=0 || M>MAX)
    {
        printf("Invalid input. Rows and columns must be between 1 and %d.\n", MAX);
        return 0;
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
            scanf("%f", &A[i][j]);
    }
    //Base task
    prodcolumns(A);
    sumperimeter(A);

    //Show the sorted conversion of A into a one dimensional array
    Convert(B,A);
    quicksort(B, 0, N*M - 1);
    printf("\n");
    for (int i=0; i<N*M; i++)
    {
        printf("%.2f ", B[i]);
    }
    printf("\n\n");

    //Arrange the sorted elements in the desired spiral
    spiral(A,B,N,M);
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
            printf("%.2f ", A[i][j]);
        printf("\n");
    }
}
