#include "print_solution.h"
#include <assert.h>
#include <stdio.h>

void print_solution(solution solution)
{
    switch (solution.flag) {
    case (-1): // Why is it weird?)
        printf("\nNo solutions on the set of real numbers.\n");
        break;
    case (0):
        printf("\nx can take any value.\n");
        break;
    case (1):
        printf("\nx = %lf\n", solution.x1);
        break;
    case (2):
        printf("\nx = %lf or x = %lf\n", solution.x1, solution.x2);
        break;
    default:
        assert(true);
    }
}
