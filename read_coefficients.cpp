#include "read_coefficients.h"
#include <stdio.h>

// TODO: this .cpp file is insufficient, read print_solution.cpp

void read_coefficients(coefficients* coefs)
{
    scanf("%lf %lf %lf", &coefs->a, &coefs->b, &coefs->c);
}
