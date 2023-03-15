/**
 * @file
 * @brief Solve linear and quadratic equations
 */

#include "solve_equation.h"
#include "compare_floats.h"
#include <cmath>
#include <math.h>
#include <stdio.h>

void validate_quadratic_coefficients(quadratic_coefficients coefficients)
{
    if (isinf(coefficients.a + coefficients.b + coefficients.c)) {
        exit(1);
    }
    if (isnan(coefficients.a + coefficients.b + coefficients.c)) {
        if (isnan(coefficients.a))
            coefficients.a = 0;
        if (isnan(coefficients.b))
            coefficients.b = 0;
        if (isnan(coefficients.c))
            coefficients.c = 0;
    }
}

void validate_linear_coefficients(linear_coefficients coefficients)
{
    if (isinf(coefficients.a + coefficients.b)) {
        exit(1);
    }
    if (isnan(coefficients.a + coefficients.b)) {
        if (isnan(coefficients.a))
            coefficients.a = 0;
        if (isnan(coefficients.b))
            coefficients.b = 0;
    }
}

quadratic_solution solve_equation(quadratic_coefficients coefficients)
{
    validate_quadratic_coefficients(coefficients);
    quadratic_solution solution = { no_roots, { 0, 0 } };
    if (is_zero(coefficients.a)) {
        linear_solution linear_solution = solve_linear_equation({ .a = coefficients.b, .b = coefficients.c });
        solution = { .solution_type = linear_solution.solution_type, .roots = { linear_solution.x, 0 } };
    } else {
        solution = solve_quadratic_equation(coefficients);
    }
    return solution;
}

linear_solution solve_linear_equation(linear_coefficients coefficients)
{
    validate_linear_coefficients(coefficients);
    linear_solution solution = { no_roots, 0 };
    if (!is_zero(coefficients.a)) {
        solution.solution_type = one_root;
        solution.x = -coefficients.b / coefficients.a;
    } else {
        solution.solution_type = is_zero(coefficients.b) ? any_value : no_roots;
    }
    return solution;
}

quadratic_solution solve_quadratic_equation(quadratic_coefficients coefficients)
{
    validate_quadratic_coefficients(coefficients);
    quadratic_solution solution = { no_roots, { 0, 0 } };
    double D = coefficients.b * coefficients.b - 4 * coefficients.a * coefficients.c;
    if (is_zero(D)) {
        solution.solution_type = one_root;
        solution.roots[first] = -coefficients.b / (2 * coefficients.a);
    } else if (compare_floats(D, 0) == -1) {
        solution.solution_type = no_roots;
    } else {
        solution.solution_type = two_roots;
        solution.roots[first] = (-coefficients.b + sqrt(D)) / (2 * coefficients.a);
        solution.roots[second] = (-coefficients.b - sqrt(D)) / (2 * coefficients.a);
    }
    return solution;
}
