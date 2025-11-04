#include <stdio.h>
#include <stdlib.h>
#include <math.h>
                  // The following programming taking only the value of x and gives f(x) using Newton's backward interpolation method from a given data set
                  // f(x) = p(x)= y_n + (v/1!){del}y_n + (v(v-1)/2!){del^2}y_n+.....+(v(v-1)..(v-i+1)/n!){del^n}y_n
int main()
{
    int n,i, j ;
    float   h, v, c, k, l, fact;

    printf("Enter your value for x: ");                          // here given x=0.75; but I am taking here the value x from user
    scanf("%f", &c);                                             // here c is working as x because the programming fails to recognize different different x


    float x[5]={0.0, 0.2, 0.4, 0.6, 0.8};                          // no of data points denote here so x[5]. one can write it as float x[4]; then x[]={data points}.
    float dy[5][5]={1.00000, 1.22140, 1.49182, 1.82212, 2.22554};  // these values are stored in the 1st row of 5*5 matrix which is dy[0][i]

    n=4;

     for(j=1; j<=n; j++)
    {
        for(i=n; i>=j; i--)
        {
            dy[j][i]=dy[j-1][i]- dy[j-1][i-1];                       // calculating del
            printf("dy[%d][%d] is %f\n", j,i, dy[j][i]);
        }
    };

    h=x[1]-x[0];

    v=(c-x[n])/h;



   k=dy[0][n];
   l=1;
   fact=1;
   for(j=1; j<=n; j++)
   {
          fact=fact*j;

       l=l*(v+j-1);


       k=k+(l*dy[j][n])/fact;

   }

   printf("p(x) is %f ", k);

}
