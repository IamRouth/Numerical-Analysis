#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function definition
double funct(double p, double q)
{
    double  r;
    r=exp(p-q);
    return r;
}

int main()
{
    double a, b,h,t,y;
    int N,i;
    // Here, the initial values are
    a=0;
    b=1;
    h=0.1;
    N=(b-a)/h;

    t=a;
    y=1; //y(0)=1
    printf("By Euler method we get \nt ----------> y(t) are \n");
    // Now calculating by Euler method
    for(i=1; i<=N+1; i++)
    {
        printf("%lf ---> %lf \n", t, y);
        y=y+h*funct(t,y);
        t=a+i*h;

    }
}
