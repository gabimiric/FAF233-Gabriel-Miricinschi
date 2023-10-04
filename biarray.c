#include <stdio.h>
#include <math.h>

#define MAX 20

int n,m;
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
    for (int j=0; j<m; j++)
    {
        float P=1;
        for (int i=0; i<n; i++)
            P*=A[i][j];
        printf("The produce of all elements from column %d is: %.2f \n", j+1, P);
    }
    printf("\n");
}

//Calculates the sum on the perimeter of the array
void sumperimeter(float A[MAX][MAX])
{
    float S=0;
    for (int j=0; j<m; j++)
        S+=A[0][j];
    for (int j=0; j<m; j++)
        S+=A[n-1][j];
    for (int i=1; i<n-1; i++)
        S+=A[i][0];
    for (int i=1; i<n-1; i++)
        S+=A[i][m-1];
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
    for (int i=0; i<n; i++)
        for(int j=0; j<m; j++)
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
        for (j=m-p; j<p && k<n*m; j++)
        {
            A[n-o][j]=B[k];
            k++;
        }
        //down
        for (i=n-o+1; i<o && k<n*m; i++)
        {
            A[i][p-1]=B[k];
            k++;
        }
        o--;
        p--;
        //left
        for (j=p-1; j>=m-p-1 && k<n*m; j--)
        {
            A[i-1][j]=B[k];
            k++;
        }
        //up
        for (i=o-1; i>=n-o && k<n*m; i--)
        {
            A[i][j+1]=B[k];
            k++;
        }
    }
}
int main()
{
    printf("Insert number of rows and columns (up to %d):", MAX);
    scanf("%d %d", &n, &m);

    if (n<=0 || n>MAX || m<=0 || m>MAX)
    {
        printf("Invalid input. Rows and columns must be between 1 and %d.\n", MAX);
        return 0;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            scanf("%f", &A[i][j]);
    }
    //Base task
    prodcolumns(A);
    sumperimeter(A);

    //Show the sorted conversion of A into a one dimensional array
    Convert(B,A);
    quicksort(B, 0, n*m - 1);
    printf("\n");
    for (int i=0; i<n*m; i++)
    {
        printf("%.2f ", B[i]);
    }
    printf("\n\n");

    //Arrange the sorted elements in the desired spiral
    spiral(A,B,n,m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%.2f ", A[i][j]);
        printf("\n");
    }
}
