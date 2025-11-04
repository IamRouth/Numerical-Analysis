#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int row, column, i,j,k;
    double factor;
    printf("Enter the number of rows of the matrix(A): ");
    scanf("%d", &row);
    printf("Enter the number of columns in the matrix(A): ");
    scanf("%d", &column);
    double a[row][column];           // We are taking the matrix A whose elements are given by a_{i,j}
    double l[row][row];              //Taking a lower Triangular square matrix L whose elements are given by l[i][j]
    double b[row];                   // Taking vector b differently

    printf("\n \n");

    for(i=0; i<row;i++)             // creating loop for taking the entries of the matrix
    {
        for(j=0;j<column; j++)
        {
            printf("Enter your value of {%d,%d} position: ", i+1,j+1);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("\n Your entered matrix(A) is: \n \n");
    for(i=0; i<row;i++)                           // loop for printing the matrix A
    {
        for(j=0;j<column; j++)
        {
            printf("%lf  ", a[i][j]);
        }
        printf("\n");
    }

    //At first setting the lower triangular matrix as Identity matrix except some entries then we will update the matrix
    for(i=0; i<row; i++)
    {
        for(j=0; j<row; j++)
        {
            if(j==i)
            {
                l[i][j]=1;
            }
            else if(j>i)
            {
                l[i][j]=0;
            }
        }
    }

    for(i=0; i<row-1; i++)
    {
        //For a matrix it may happens in after ith row a column all entries become 0. So to proceed further we have to check either a[i][i]!=0 or not
        if(a[i][i]!=0)
        {
            //Calculating factors and the loop for which the matrix will be in triangular form,
            for(j=i+1; j<row; j++)  // j denotes the row numbers after i
                {
                    factor=(a[j][i])/(a[i][i]);
                    for(k=0; k<column; k++)    // k denotes the column number;
                    {
                        a[j][k]=a[j][k]-factor*a[i][k];
                    }
                    //Now update the lower triangular matrix
                    l[j][i]=factor;
                }
        }
        else
        { printf("\nMatrix requires pivoting / diagonal entry 0\n");
            return(0);
        }

    }
    printf("\nThe U of A=LU is: \n \n");
    for(i=0; i<row;i++)                           // loop for printing the U of A=LU
    {
        for(j=0; j<column; j++)
        {
            printf("%lf  ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nThe L of A=LU is: \n \n");
    for(i=0; i<row;i++)                           // loop for printing L of A=LU
    {
        for(j=0;j<row; j++)
        {
            printf("%lf  ", l[i][j]);
        }
        printf("\n");
    }

    int t;
    printf("\nDo you want to solve system of equations by LUD method? If yes type 1 else type 0. -> ");
    scanf("%d", &t);
    if(t==1)
    {
        printf("\nEnter your b vector:\n");
        for(i=0; i<row; i++)
        {
            printf("Enter value of b_{%d}: ", i+1);
            scanf("%lf", &b[i]);
        }
    printf("\nYour b vector is: \n");
    for(i=0; i<row; i++)
    {
        printf("%lf\n", b[i]);
    }
    //Calculating the y i.e. y{1}, y{2}, .. , y{n}
    double y[row], sum;
    for(i=0; i<row; i++)
    {
        sum=0;
        for(j=0; j<i; j++)
        {
            sum=sum+y[j]*l[i][j];
        }
        y[i]=(b[i]-sum); //since l[i][i]=1, so we don't continue the divison by l[i][i]

    }
    printf("\nY is:  ");
    for(i=0; i<row; i++)
    {
        printf("y{%d}=%lf ", i+1, y[i]);
     //This next "if and else" condition is used to separate y1, y2,.. and yn.
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

    double x[row];
    for(i=row-1; i>=0; i--)
    {
        sum=0;
        for(j=row-1; j>i; j--)
        {
            sum=sum+x[j]*a[i][j];
        }
        x[i]=(y[i]-sum)/a[i][i];

    }
    printf("\nThe solution by LU decomposition is: ");
    for(i=0; i<row; i++)
    {
        printf("x{%d}=%lf", i+1,x[i]);
        //The below loop separate x{1}, x{2},..,x{n-1} and x{n}.
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

}

