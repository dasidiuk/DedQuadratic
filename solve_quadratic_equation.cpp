#include "solve_quadratic_equation.h"
#include <cstdio>
#include <math.h>

solution solve_quadratic_equation(coefficients coefficients)
{
    solution solution;
    const float EPSILON = 1e-9f;
    double D = coefficients.b * coefficients.b - 4 * coefficients.a * coefficients.c;
    if (D < 0)
        solution.flag = -1;
    else if (fabs(D) < EPSILON) {
        solution.flag = 1;
        solution.x1 = -coefficients.b / (2 * coefficients.a);
    } else {
        solution.flag = 2;
        solution.x1 = (-coefficients.b + sqrt(D)) / (2 * coefficients.a);
        solution.x2 = (-coefficients.b - sqrt(D)) / (2 * coefficients.a);
    }
    return solution;
}
