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
    double a, b,h,t,w;
    int N,i;
    // Here, the initial values are
    a=0;
    b=1;
    h=0.1;
    N=(b-a)/h;

    t=a;
    w=1; //y(0)=1
    printf("t ----------> y(t) are \n");
    // Now calculating by Euler method
    for(i=1; i<=N+1; i++)
    {
        printf("%lf ---> %lf \n", t, w);
        w=w+h*funct(t,w);
        t=a+i*h;

    }
}
