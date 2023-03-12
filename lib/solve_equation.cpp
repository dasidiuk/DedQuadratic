/**
 * @file
 * @brief Library implementing functions for solving quadratic and linear equations.
 */

#include "solve_equation.h"
#include "compare_floats.h"
#include <cmath>
#include <cstdio>

linear_solution solve_linear_equation(coefficients coefficients)
{
    linear_solution solution;
    if (!is_zero(coefficients.b)) {
        solution.solution_type = one_root;
        solution.x = -coefficients.c / coefficients.b;
    } else {
        solution.solution_type = is_zero(coefficients.c) ? any_value : no_roots;
    }
    return solution;
}

quadratic_solution solve_quadratic_equation(coefficients coefficients)
{
    quadratic_solution solution;
    double D = coefficients.b * coefficients.b - 4 * coefficients.a * coefficients.c;
    if (is_zero(D)) {
        solution.solution_type = one_root;
        solution.x1 = -coefficients.b / (2 * coefficients.a);
    } else if (compare_floats(D, 0) == -1) {
        solution.solution_type = no_roots;
    } else {
        solution.solution_type = two_roots;
        solution.x1 = (-coefficients.b + sqrt(D)) / (2 * coefficients.a);
        solution.x2 = (-coefficients.b - sqrt(D)) / (2 * coefficients.a);
    }
    return solution;
}
