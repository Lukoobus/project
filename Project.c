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

    double r = 3.9;
    double x = 0.5;
    double sigma = 0.01;

    // Open pipe to gnuplot
    FILE *gp = popen("gnuplot -persistent", "w");
    if (!gp) {
        fprintf(stderr, "Error opening pipe to gnuplot\n");
        return 1;
    }

    // Set up Gnuplot
    fprintf(gp, "set title 'Noisy Logistic Map'\n");
    fprintf(gp, "set xlabel 'Iteration'\n");
    fprintf(gp, "set ylabel 'x'\n");
    fprintf(gp, "plot '-' with lines\n");
    for (int n = 0; n<=100; n++)
    {
        double xn = x + 0.0001*n;
        for (int i = 0; i <= 100; i++)
        {
            xn = r * xn * (1 - xn) + sigma * random_double();
            fprintf(gp, "%d %lf\n", i, xn);
        }
    }
    fprintf(gp, "e\n"); // tell gnuplot data ends
    fflush(gp);
    pclose(gp);

    return 0;
}