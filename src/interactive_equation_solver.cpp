/**
 * @file
 * @brief Implements the console interface for the \ref solve_equation.h library.
 */

#include "../lib/compare_floats.h"
#include "../lib/solve_equation.h"
#include <cassert>
#include <cmath>
#include <cstdio>

void print_solution(enum solution_types solution_type, double x1, double x2);

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
    if (is_zero(coefficients.a)) {
        linear_solution solution = solve_linear_equation(coefficients);
        print_solution(solution.solution_type, solution.x, 0);
    } else {
        quadratic_solution solution = solve_quadratic_equation(coefficients);
        print_solution(solution.solution_type, solution.x1, solution.x2);
    }
}

//! Prints the solution depending on it's type
void print_solution(enum solution_types solution_type, double x1, double x2)
{
    switch (solution_type) {
    case (no_roots):
        printf("has no solutions on the set of real numbers.\n");
        break;

    case (any_value):
        printf("can take any value.\n");
        break;

    case (one_root):
        printf("has one possible solution:\nx = %lf\n", x1);
        break;

    case (two_roots):
        printf("has two possible solutions:\nx = %lf or x = %lf\n", x1, x2);
        break;

    default:
        assert(false && "Unexpected solution type!\n");
    }
}
