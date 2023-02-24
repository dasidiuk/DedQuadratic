#include "solve_equation.h"

// TODO: this .cpp file is insufficient, read print_solution.cpp

solution solve_linear_equation(coefficients coefficients)
{
    solution solution;
    if (coefficients.b) { // TODO: still checking for zero without epsilon?
        solution.flag = 1;
        solution.x1 = -coefficients.c / coefficients.b;
    } else {
        const float EPSILON = 1e-9f;
        solution.flag = coefficients.c < EPSILON ? 0 : -1;
    }
    return solution;
}
