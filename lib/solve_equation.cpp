#include "solve_equation.h"
#include "compare_floats.h"
//       ^~~~~~~~~~~~~~~~~~ NOTE: Shall I use it as a library?
//                                If so, is such usage correct?

#include <cmath>
#include <cstdio>

solution solve_equation(coefficients coefficients)
{
    // ========================================================================
    // Solves equations of the form Ax^2 + Bx + C = 0, where A, B and C are
    // elements of the "coefficients" structure. Functions returns the solution
    // structure with the following fields:
    //     solution_type: -1 - the equation has no solutions;
    //                        0 - infinitely many solutions;
    //                        1 - only one solution;
    //                        2 - there are two possible solutions.
    //     x1 - first possible solution.
    //     x2 - second possible solution.
    // ========================================================================

    solution solution;
    if (is_equal(coefficients.a, 0)) {
        if (!is_equal(coefficients.b, 0)) {
            solution.solution_type = one_root;
            solution.x1 = -coefficients.c / coefficients.b;
        } else {
            solution.solution_type = is_equal(coefficients.c, 0) ? any_value : no_roots;
        }
    } else {
        double D = coefficients.b * coefficients.b - 4 * coefficients.a * coefficients.c;
        if (is_equal(D, 0)) {
            solution.solution_type = one_root;
            solution.x1 = -coefficients.b / (2 * coefficients.a);
        } else if (is_less(D, 0)) {
            solution.solution_type = no_roots;
        } else {
            solution.solution_type = two_roots;
            solution.x1 = (-coefficients.b + sqrt(D)) / (2 * coefficients.a);
            solution.x2 = (-coefficients.b - sqrt(D)) / (2 * coefficients.a);
        }
    }
    return solution;
}
