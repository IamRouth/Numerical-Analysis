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
    double a, b,h,x,y;
    double k,l,m,n;
    int N,i;
    // Here, the initial values are
    a=0;
    b=1;
    h=0.1;
    N=(b-a)/h;
    //printf("N = %d\n",N );
    k=0, l=0, m=0, n=0;

    x=a;
    y=1; //y(0)=1
    printf("By Runge Kutta Method we get\nt ----------> y(t) are \n");
    for(i=1; i<=N+1; i++)
    {
        printf("%lf ---> %lf \n", x, y);
        k=h*funct(x,y);
        l=h*funct(x+(h/2.0), y+(k/2.0));
        m=h*funct(x+(h/2.0), y+(l/2.0));
        n=h*funct(x+h, y+m);
        y=y+(k+2*l+2*m+n)/6.0;
        x=x+h;

    }
}
