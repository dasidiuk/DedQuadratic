#include "solve_equation.h"
#include "compare_floats.h"
#include <cmath>
#include <cstdio>

solution solve_equation(coefficients coefficients)
{
    // ========================================================================
    // Solves equations of the form Ax^2 + Bx + C = 0, where A, B and C are
    // elements of the "coefficients" structure. Functions returns the solution
    // structure with the following fields:
    //     solution_type: -1 - the equation has no solutions;
    //                     0 - infinitely many solutions;
    //                     1 - only one solution;
    //                     2 - there are two possible solutions.
    //     x1 - first possible solution.
    //     x2 - second possible solution.
    // ========================================================================

    solution solution;
    if (is_zero(coefficients.a))
        solution = solve_linear_equation(coefficients);
    else
        solution = solve_quadratic_equation(coefficients);
    return solution;
}

solution solve_linear_equation(coefficients coefficients)
{
    solution solution;
    if (!is_zero(coefficients.b)) {
        solution.solution_type = one_root;
        solution.x1 = -coefficients.c / coefficients.b;
    } else {
        solution.solution_type = is_zero(coefficients.c) ? any_value : no_roots;
    }
    return solution;
}

solution solve_quadratic_equation(coefficients coefficients)
{
    solution solution;
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