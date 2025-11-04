#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int i;
    float a,b,err,m;
    //y=0.00001;
    i=0;                    // 10^-5 is not machine language you may write pow(10,-5)
    a=0.0;
    b=1.0;
    err=(b-a)/(2.0);

                                  // signbit(cos(m*pi))==0 gives exact root  bit means binary digit  [][][][]   ---> 1st box represent bit 0 --> non-negative and 1 ---> negative
                                  // do not use signbit

    while(err>=pow(10,-5))
    {
       // i++;
        m=(a+b)/2.0;
        if((cos(a*M_PI))*cos(m*M_PI)==0)
        {
            printf("The root is %f", m);
        }
        else if(((cos(a*M_PI))*(cos(b*M_PI)))>0)
            {
                a=m;
                err=b-a;
            }
        else
            {b=m;
             err=b-a;
             }

    }

}
