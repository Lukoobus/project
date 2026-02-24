#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double random_double()
{
    return 2.0 * ((double)rand() / RAND_MAX) - 1.0;  // -1 to 1
}

int main(void)
{
    srand(time(NULL));
    double r = 3;
    double x = 0.4;
    double sigma = 0.01;
    for (int i=0; i<=100000; i++)
    {
       x =r* x*(1-x)+sigma*random_double();
       printf("%lf \n",x);
    }
}