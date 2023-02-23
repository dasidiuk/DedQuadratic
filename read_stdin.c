#include <stdio.h>
#include <stdlib.h>

double* read_stdin()
{
    double* parameters = (double*)calloc(3, sizeof(double));
    scanf("%lf %lf %lf", &parameters[0], &parameters[1], &parameters[2]);
    return parameters;
}
