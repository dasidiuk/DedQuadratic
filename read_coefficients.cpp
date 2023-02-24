#include "read_coefficients.h"
#include <stdio.h>

void read_coefficients(coefficients* coefs)
{
    scanf("%lf %lf %lf", &coefs->a, &coefs->b, &coefs->c);
}
