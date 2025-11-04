#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int row, column, i,j,k;
    printf("Enter the number of rows of your augmented matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns in your augmented matrix: ");
    scanf("%d", &column);
    float a[row][column];           // We are taking a matrix A whose elements are given by a_{i,j}
    printf("\n \n");

    for(i=0; i<row;i++)             // creating loop for taking the entries of the matrix
    {
        for(j=0;j<column; j++)
        {
            printf("Enter the value of {%d,%d} position: ", i+1,j+1);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nAugmented matrix is: \n \n");
    for(i=0; i<row;i++)                           // loop for printing the matrix
    {
        for(j=0;j<column; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    float x[row][2];
    for(i=0; i<row; i++)
    {
        printf("Enter the initial value of x^(0)_{%d}: ", i+1);
        scanf("%f", &x[i][0]);
        //printf("%f", x[i][0]);
    }


    float tolerance=pow(10,-5), error, sum, srt;
    int max_iteration;
    max_iteration=100;

    k=1;
    error=200;
    while(k<=max_iteration && error>=tolerance)
    {
        for(i=0; i<row; i++)
        {
            sum=0;
           for(j=0; j<row; j++)
           {
               if(j!=i)
                {
                    sum=sum+ a[i][j]*x[j][0];
                }
            }
           x[i][1]=(a[i][column-1] - sum)/a[i][i];
        }

        //Calculating error
        srt=0;
        for(i=0; i<row; i++)
        {
            srt=srt+pow((fabs(x[i][1]-x[i][0])), 2);
        }
        error=pow(srt,0.5);

        for(i=0; i<row; i++)
        {
            x[i][0]=x[i][1];
        }
        k++;
    }
    if(k<=max_iteration)
    {
        printf("\nSo the solution by Gauss Jacobi method, is: ");
        for(i=0; i<row; i++)
        {
            printf("x{%d}=%f ", i+1, x[i][1]);
        }
        printf("\n");
    }
    else
    {
        printf("\nMaximum number of iteration exceeds.\n");
    }

}
