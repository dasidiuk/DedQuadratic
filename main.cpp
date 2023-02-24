#include "main.h" // TODO: read main.h, no one creates .h for main.cpp
#include <stdlib.h>

int main()
{
    coefficients coefficients;
    read_coefficients(&coefficients);
    solution solution = solve_equation(coefficients);
    print_solution(solution);
}
