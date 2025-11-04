#include <stdio.h>
#include <stdlib.h>

float func(float y)
{
    float r;
    r=y*y*y*y+2*y*y-y-3;
    return r;
}
float dfunc(float h)
{
    float w;
    w=4*h*h*h+4*h-1;
    return w;

}
main()
{
   float x0, x1, err,p,prev=-1;
   int n,m;
   x0=1; // here we change the initial value because of x=0 give us the solution x=-0.8666 .. so we change the initial value
   err=300;
   n=1; m=1000;
   while(err>=pow(10,-3) && n<=m)
   {
        x1=x0 - ((func(x0))/(dfunc(x0)));
        n++;
        if(func(x1)==0)
        {
            printf("root is %f", x1);
        }
        else
        {
            x0=x1;
        }
         err = fabs(x1-prev);
         prev = x1;

   }
   printf("Actual root is %f .",x1);
}
