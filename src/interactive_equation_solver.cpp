/**
 * @file
 * @brief Implements the console interface for the \ref solve_equation.h library.
 */

#include "../lib/solve_equation.h"
#include <cassert>
#include <cmath>
#include <cstdio>

int main()
{
    coefficients coefficients;

    printf("To solve an equation of the form Ax^2 + Bx + C = 0, enter the coefficients A, B and C, separated by a space:\n");

    //! Validate the input data
    if (scanf("%lf %lf %lf", &coefficients.a, &coefficients.b, &coefficients.c) != 3 || std::isnan(coefficients.a) || std::isnan(coefficients.b) || std::isnan(coefficients.c) || std::isinf(coefficients.a) || std::isinf(coefficients.b) || std::isinf(coefficients.c)) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nThe equation \033[1m%.9gx^2 %s %.9gx %s %.9g = 0\033[0m ", coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c));

    //! Solve the equation with taken coefficients
    solution solution = solve_equation(coefficients);

    //! Prints the answer depending on the solution's type
    switch (solution.solution_type) {
    case (no_roots):
        printf("has no solutions on the set of real numbers.\n");
        break;

    case (any_value):
        printf("can take any value.\n");
        break;

    case (one_root):
        printf("has one possible solution:\nx = %lf\n", solution.x1);
        break;

    case (two_roots):
        printf("has two possible solutions:\nx = %lf or x = %lf\n", solution.x1, solution.x2);
        break;

    default:
        assert(false && "Unexpected solution type!\n");
    }
}
