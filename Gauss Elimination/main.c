#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int row, column, i,j,k, max_p;
    float factor,tempo;
    printf("Enter the number of rows of the augmented matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns in the augmented matrix: ");
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

    printf("\nThe augmented matrix is: \n \n");
    for(i=0; i<row;i++)                           // loop for printing the matrix
    {
        for(j=0;j<column; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }

    // calculating the row with highest value in a[i][i] position

    for(i=0; i<row-1; i++)
    {
        max_p=i;       //max_p deonting the number of row with highest a[i][i] position value
        for(j=1; j<row; j++)
        {
            if(fabs(a[j][i])>fabs(a[max_p][i]))
            {
                max_p=j;
            }

        }
        //printf("%d", max_p+1);

        //Now the swapping with the ith row by the the row with maximum value a[k][i] k \in {i,...,row}
        for(j=0; j<column; j++)
        {
            tempo=a[i][j];
            a[i][j]=a[max_p][j];
            a[max_p][j]=tempo;
        }


        //For a matrix it may happens in after ith row a column all entries become 0. So to proceed further we have to check either a[i][i]==0 or not
        //Calculating factors and the loop for which the matrix will be in triangular form
        if(a[i][i]!=0)
        {
        for(j=i+1; j<row; j++)  // j denotes the row numbers after i
        {
            factor=(a[j][i])/(a[i][i]);
            for(k=0; k<column; k++)    // k denotes the column number
            {
                a[j][k]=a[j][k]-factor*a[i][k];
            }
        }
        }
    }

    printf("\nThe triangular form of the augmented matrix is: \n \n");
    for(i=0; i<row;i++)                                            // loop for printing the triangular matrix
    {
        for(j=0;j<column; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }


    //Calculating the X i.e. x{n}, x{n-1}, .. , x{1}
    float x[row], sum;
    for(i=row-1; i>=0; i--)
    {
        sum=0;
        for(j=row-1; j>i; j--)
        {
            sum=sum+x[j]*a[i][j];
        }
        x[i]=(a[i][column-1]-sum)/a[i][i];

    }

    //Printing X
    printf("\nThe solution by Gauss Elimination method, is: ");
    for(i=0; i<row; i++)
    {
        printf("x{%d}=%f ", i+1,x[i]);

    }


}
