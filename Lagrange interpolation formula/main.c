#include <stdio.h>
#include <stdlib.h>
     // The following programming approximate the vale of x[j] (user given) from a predefined data set by Lagrange interpolation formula.
     // p(x[j])= L[0](x[j])*y[0]+L[1](x[j])*y[1]+...+L[n](x[j])*y[n] ...here no of data points is (n+1)
     //where L[i](x[j])={(x[j]-x[0])(x[j]-x[1])...(x[j]-x[i-1])(x[j]-x[i+1])...(x[j]-x[n])}/{(x[i]-x[0])(x[i]-x[1])...(x[i]-x[i-1])(x[i]-x[i+1])...(x[i]-x[n])}

int main()
{
    int    n,i, j ;
    float  u, p, c, k;
    printf("Enter your value for x: ");                          // here given x=0.05; but I am taking here the value x from user
    scanf("%f", &c);                                             // here c is working as x or x[j] because the programming fails to recognize different different x
    float x[5]={0.0, 0.2, 0.4, 0.6, 0.8};                          // no of data points denote here so x[5]. one can write it as float x[4]; then x[]={data points}.
    float y[5]={1.00000, 1.22140, 1.49182, 1.82212, 2.22554};

    n=4;
    u=0;
    for(i=0; i<=n; i++)
    {
        p=1;
        for(j=0; j<=n; j++)
        {
           if(j!=i)
            {
                //printf("i = %d, j =%d\n",i,j);
                p=p*(c-x[j])/(x[i]-x[j]);                           //calculating L[i]=p
                //printf("for i= %d and j=%d p is %f \n", i,j,p);
                }
        }
        u=u+y[i]*p;                                                 // multiplication of L[i]*y[i] and calculating p(x[j]) or p(x)=u i.e. the final value
    }
    printf("p(x) is %f", u);
}
