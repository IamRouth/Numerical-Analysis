#include <stdio.h>
#include <stdlib.h>

int sign(float x)
{
    int flag=0;
    if(x>0)
    {
        flag=flag+1;
    }
    else if(x<0)
    {
        flag=flag-1;
    }
    else flag=flag;
    return flag;
}
float func(float y)
{
    float r;
    r=y*y*y*y+2*y*y-y-3;
    return r;
}
main()
{
   float x0, x1,x2, err,p,prev=-1;
   int n,m;
   x0=0;
   x1=2;
   err=x1-x0;
   n=1; m=1000;
   while(err>=pow(10,-3) && n<=m)
   {
        x2=x1-func(x1)*((x1-x0)/(func(x1)-func(x0)));
        n++;
        if(sign(func(x0))*(sign(func(x2)))<0)
          {
              //x0=x0;
              x1=x2;
              //err=x1-x0;
             // printf("%f\n",x2);
          }
         else if(sign(func(x2))*sign(func(x1))<0)

         {
             x0=x2;
             //x1=x1;
             //err=x1-x2;
             //printf("%f\n",x2);
         }
         err = fabs(x2-prev);
         prev = x2;

   }
   printf("Actual root is %f.",x2);
}
