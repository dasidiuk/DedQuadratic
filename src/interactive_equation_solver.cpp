/**
 * @file
 * @brief Implements the console interface for the \ref solve_equation.h library.
 */

#include "compare_floats.h"
#include "solve_equation.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

quadratic_coefficients read_coefficients()
{
    quadratic_coefficients coefficients = { 0, 0, 0 };

    printf("To solve an equation of the form Ax^2 + Bx + C = 0, enter the coefficients A, B and C, separated by a space:\n");

    // TODO: Validate each coefficient by loop
    if (scanf("%lf %lf %lf", &coefficients.a, &coefficients.b, &coefficients.c) != 3 || isnan(coefficients.a + coefficients.b + coefficients.c) || isinf(coefficients.a + coefficients.b + coefficients.c)) {
        printf("Invalid input.\n");
        // TODO:
        __asm__("movq $60, %rax\n"
                "movq $2 , %rdi\n"
                "syscall\n");
    }
    return coefficients;
}

//! Prints the solution depending on it's type
void print_equation_solution(quadratic_solution solution)
{
    // TODO: Use loop
    switch (solution.solution_type) {
    case (no_roots):
        printf("has no solutions on the set of real numbers.\n");
        break;

    case (any_value):
        printf("can take any value.\n");
        break;

    case (one_root):
        printf("has one possible solution:\nx = %g\n", solution.roots[first]);
        break;

    case (two_roots):
        printf("has two possible solutions:\nx = %g or x = %g\n", solution.roots[first], solution.roots[second]);
        break;

    default:
        assert(false && "Unexpected solution type!\n");
    }
}

void print_equation(quadratic_coefficients coefficients)
{
    printf("\nThe equation \033[1m%.9gx^2 %s %.9gx %s %.9g = 0\033[0m ", coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c));
}

int main()
{
    quadratic_coefficients coefficients = read_coefficients();

    quadratic_solution solution = solve_equation(coefficients);

    print_equation(coefficients);

    print_equation_solution(solution);
}
