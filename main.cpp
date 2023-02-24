#include "main.h"
#include <stdlib.h>

int main()
{
    coefficients coefficients;
    read_coefficients(&coefficients);
    solution solution = solve_equation(coefficients);
    print_solution(solution);
}
