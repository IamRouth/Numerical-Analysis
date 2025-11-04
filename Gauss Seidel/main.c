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
    double a[row][column];                                    // We are taking a matrix A whose elements are given by a_{i,j}
    printf("\n \n");

    for(i=0; i<row;i++)                                 // creating loop for taking the entries of the matrix
    {
        for(j=0;j<column; j++)
        {
            printf("Enter the value of {%d,%d} position: ", i+1,j+1);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("\nAugmented matrix is: \n \n");                          // loop for printing the matrix

    for(i=0; i<row;i++)
    {
        for(j=0;j<column; j++)
        {
            printf("%lf  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double x[row][2];
    for(i=0; i<row; i++)
    {
        printf("Enter the initial value of x^(0)_{%d}: ", i+1);
        scanf("%lf", &x[i][0]);
    }


    double tolerance=pow(10,-5), error, Jacobi_sum, srt, Seidel_sum;
    int max_iteration;
    max_iteration=100;

    k=1;
    error=200;

    //Finding the solution if exists
    while(k<=max_iteration && error>=tolerance)
    {
        for(i=0; i<row; i++)
        {
            Jacobi_sum=0;
            Seidel_sum=0;
           for(j=0; j<row; j++)
           {
               for(j=0; j<i; j++)
               {
                   Seidel_sum=Seidel_sum+a[i][j]*x[j][1];
               }
               for(j=i+1; j<row; j++)
                {
                    Jacobi_sum=Jacobi_sum+ a[i][j]*x[j][0];
                }
            }
           x[i][1]=(a[i][column-1] - (Seidel_sum + Jacobi_sum))/a[i][i];
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
        printf("\nSo the solution by Gauss Seidel method, is: ");
        for(i=0; i<row; i++)
        {
            printf("x{%d}=%lf ", i+1, x[i][1]);
             //This next "if and else" condition is used to separate x1, x2 and xn.
            if(i==row-1)
            {
                printf(".\n");
            }
            else if(i==row-2)
            {
                printf(" and ");
            }
            else
            {
                printf(", ");
            }
        }
    }
    else
    {
        printf("\nMaximum number of iteration exceeds.\n");
    }

}
