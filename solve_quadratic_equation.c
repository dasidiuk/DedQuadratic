#include "headers.h"
#include <math.h>

void solve_quadratic_equation(double* parameters, double* solution)
{
    double D = discriminant(parameters);
    if (D < 0)
        solution[0] = -1.0;
    else if (!D) {
        solution[0] = 1.0;
        solution[1] = -parameters[1] / (2 * parameters[0]);
    } else {
        solution[0] = 2.0;
        solution[1] = (-parameters[1] + sqrt(D)) / (2 * parameters[0]);
        solution[2] = (-parameters[1] - sqrt(D)) / (2 * parameters[0]);
    }
}
