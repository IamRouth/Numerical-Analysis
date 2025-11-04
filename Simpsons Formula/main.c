#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funct(double p)
{
    double  r;
    r=(exp(3*p))*sin(2*p);
    return r;
}
int call_again(int q)
{
    while(q%2!=0 || q<=0 )
    {
        printf("\nPlease enter an even positive integer: ");
        scanf("%d", &q);
    }
    if(q>0 || q%2==0)
    {
       return q;
    }
}

int main()
{
    double a, b, h; // a denotes left end point and b denote the right end point

    int n,i;
    printf("Please enter the no of subintervals (must be an even positive integer): ");
    scanf("%d", &n);
    n=call_again(n);
    //values of a and b
    a=0;
    b=(M_PI)/4;
    h=(b-a)/n; //Here n=2

    double xi[3],x, int_s;

    xi[0]=funct(a)+funct(b);
    xi[1]=0; //summation of f(x{2*i-1})
    xi[2]=0; //summation of f(x(2*i))
    for(i=1; i<=n-1; i++)
    {
        x=a+i*h;
        if(i%2==0)
        {
            xi[2]=xi[2]+funct(x);
        }
        else
        {
            xi[1]=xi[1]+funct(x);
        }
    }
    int_s=(h*(xi[0]+2*xi[2]+4*xi[1]))/3;
    printf("\nHence the value of the integration is %lf .\n", int_s);

}
