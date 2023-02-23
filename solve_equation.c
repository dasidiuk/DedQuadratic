#include "headers.h"

void solve_equation(double* parameters, double* solution)
{
    /* Solves equations of the form Ax^2 + Bx + C = 0, where A, B and C are
       elements of the "parameters" array respectively. The solution to the
       equation is written to the "solution" array. If its zero element is:
           -1.0 - the equation has no solutions;
            0.0 - the equation has infinitely many solutions;
            1.0 - the equation has one solution equal to the first element of the array;
            2.0 - the first and second elements of the array are solutions to the equation. */
    if (!parameters[0]) {
        solve_linear_equation(&parameters[1], solution);
    } else {
        solve_quadratic_equation(parameters, solution);
    }
}
