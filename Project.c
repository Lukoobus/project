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

    // Open CSV file
    FILE *fp = fopen("data.csv", "w");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    // Write CSV header
    fprintf(fp, "Iteration,Value\n");

    // Generate data
    for (int n = 0; n <= 100; n++)
    {
        double xn = x + 0.0001 * n;
        for (int i = 0; i <= 100; i++)
        {
            xn = r * xn * (1 - xn) + sigma * random_double();
            fprintf(fp, "%d,%lf\n", i, xn);  // CSV format
        }
    }

    fclose(fp);
    printf("Data saved to data.csv\n");

    return 0;
}
