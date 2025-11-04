#include <stdio.h>
#include <stdlib.h>
#include <math.h>
                  // The following programming taking only the value of x and gives f(x) using Newton's forward interpolation method from a given data set
                  // f(x) = p(x)= y_0 + (u/1!){del}y_0 + (u(u-1)/2!){del^2}y_0+.....+(u(u-1)..(u-i+1)/n!){del^n}y_0
int main()
{
    int n,i, j ;
    float   h, u,x_0, p, c, k, l, fact, t;

    printf("Enter your value for x: ");                          // here given x=0.05; but I am taking here the value x from user
    scanf("%f", &c);                                             // here c is working as x because the programming fails to recognize different different x


    float x[5]={0.8, 0.6, 0.4, 0.2, 0.0}; // x[5]={0.0, 0.2, 0.4, 0.6, 0.8};                          // no of data points denote here so x[5]. one can write it as float x[4]; then x[]={data points}.
    float dy[5][5]={2.22554, 1.82212, 1.49182, 1.22140, 1.00000}; //dy[5][5]={1.00000, 1.22140, 1.49182, 1.82212, 2.22554 }; // these values are stored in the 1st row of 5*5 matrix which is dy[0][i]

    n=4;


    for(j=1; j<=n; j++)
    {
        for(i=0; i<=n-j; i++)
        {
            dy[j][i]=dy[j-1][i+1]- dy[j-1][i];                       // calculating del
                                                                    //  printf("dy[%d][%d] is %f \n", j, i,dy[j][i]);
        }
    };

    h=x[1]-x[0];                                                   // here the difference h are same h=x[2]-x[1]

    u=(c-x[0])/h;                                              // u=(x-x_0)/h
                                                               // printf("u is %f \n \n",u);

                                                                // p(x)= y_0+ k;
   k=dy[0][0];
   l=1;
   fact=1;
   for(j=1; j<=n; j++)             //calculating the numerator and denominator from last term and time consuming will be less
   {
          fact=fact*j;                                 //calculating i!
                                                      //  printf("fact of %d is %f \n", j,fact);

       l=l*(u-j+1);                                  // l stores the value of u*(u-1)*..*(u-i+1)

                                                    // printf("value of l is %f for %d \n", l, j);
       k=k+(l*dy[j][0])/fact;

   }

   printf("p(x) is %f ", k);

}
