#include "../lib/solve_equation.h"
#include <cassert>
#include <cmath>
#include <cstdio>

int main()
{
    coefficients coefficients;

    if (scanf("%lf %lf %lf", &coefficients.a, &coefficients.b, &coefficients.c) != 3 || std::isnan(coefficients.a) || std::isnan(coefficients.b) || std::isnan(coefficients.c) || std::isinf(coefficients.a) || std::isinf(coefficients.b) || std::isinf(coefficients.c)) {
        printf("Invalid input.\n");
        return 1;
    }

    solution solution = solve_equation(coefficients);

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
