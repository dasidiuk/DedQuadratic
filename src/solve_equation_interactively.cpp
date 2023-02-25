#include "solve_equation_interactively.h" // NOTE: read main.cpp
#include <cassert>
#include <cstdio>

void solve_equation_interactively(coefficients* coefficients)
{
    scanf("%lf %lf %lf", &coefficients->a, &coefficients->b, &coefficients->c);

    solution solution = solve_equation(*coefficients);

    switch (solution.solution_type) {
    case (no_roots):
        printf("\nNo solutions on the set of real numbers.\n");
        break;

    case (any_value):
        printf("\nx can take any value.\n");
        break;

    case (one_root):
        printf("\nx = %lf\n", solution.x1);
        break;

    case (two_roots):
        printf("\nx = %lf or x = %lf\n", solution.x1, solution.x2);
        break;

    default:
        assert(false && "Unexpected solution type!");
    }
}
