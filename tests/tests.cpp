#include "../lib/compare_floats.h"
#include "../lib/solve_equation.h"
#include <cstdio>
#include <string.h>

#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define NORMAL "\033[0m"
#define STRIKETHROUGH_BEGIN "\e[9m"
#define STRIKETHROUGH_END "\e[0m"

void do_test(coefficients coefficients, solution expected);

int main()
{
    solution solution;
    do_test({ .a = 0, .b = 0, .c = 0 }, { .solution_type = any_value, .x1 = 0, .x2 = 0 });
    do_test({ .a = 0, .b = 0, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test({ .a = 0, .b = 1, .c = 0 }, { .solution_type = one_root, .x1 = 0, .x2 = 0 });
    do_test({ .a = 0, .b = 1, .c = 0 }, { .solution_type = one_root, .x1 = 0, .x2 = 0 });
    do_test({ .a = 0, .b = 1, .c = 1 }, { .solution_type = one_root, .x1 = -1, .x2 = 0 });
    do_test({ .a = 1, .b = 0, .c = 0 }, { .solution_type = one_root, .x1 = 0, .x2 = 0 });
    do_test({ .a = 1, .b = 0, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test({ .a = 1, .b = 1, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test({ .a = 1, .b = 2, .c = 3 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test({ .a = 3, .b = 2, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test({ .a = 1, .b = -3, .c = 2 }, { .solution_type = two_roots, .x1 = 1, .x2 = 2 });
    do_test({ .a = 1, .b = -3, .c = 2 }, { .solution_type = two_roots, .x1 = 1, .x2 = 2 });
    do_test({ .a = 1, .b = 1, .c = -2 }, { .solution_type = two_roots, .x1 = 1, .x2 = -2 });
    do_test({ .a = -0.75, .b = -167.2907655, .c = 15785.7720564555 }, { .solution_type = two_roots, .x1 = 71.464646, .x2 = -294.519 });
    do_test({ .a = 10008.859, .b = 0, .c = -928878435.8986003 }, { .solution_type = two_roots, .x1 = 304.64016, .x2 = -304.64016 });
}

void do_test(coefficients coefficients, solution expected)
{
    solution calculated = solve_equation(coefficients);

    char calculated_solution_type[10], expected_solution_type[10];
    switch (expected.solution_type) {
    case no_roots:
        strcpy(expected_solution_type, "no_roots");
        break;
    case any_value:
        strcpy(expected_solution_type, "any_value");
        break;
    case one_root:
        strcpy(expected_solution_type, "one_root");
        break;
    case two_roots:
        strcpy(expected_solution_type, "two_roots");
        break;
    }

    switch (calculated.solution_type) {
    case no_roots:
        strcpy(calculated_solution_type, "no_roots");
        break;
    case any_value:
        strcpy(calculated_solution_type, "any_value");
        break;
    case one_root:
        strcpy(calculated_solution_type, "one_root");
        break;
    case two_roots:
        strcpy(calculated_solution_type, "two_roots");
        break;
    }

    if (calculated.solution_type == expected.solution_type && ((!compare_floats(expected.x2, calculated.x1) && !compare_floats(expected.x1, calculated.x2)) || (!compare_floats(expected.x1, calculated.x1) && !compare_floats(expected.x2, calculated.x2))))
        printf(GREEN "✔" NORMAL "  %.9g %.9g %.9g " GREEN "->" NORMAL " %s: x = %.9g, x = %.9g\n", coefficients.a, coefficients.b, coefficients.c, calculated_solution_type, calculated.x1, calculated.x2);
    else
        printf(MAGENTA "✘" NORMAL "  %.9g %.9g %.9g " MAGENTA "->" NORMAL " " STRIKETHROUGH_BEGIN MAGENTA "%s: x = %.9g, x = %.9g" NORMAL STRIKETHROUGH_END " %s: x = %.9g, x = %.9g\n", coefficients.a, coefficients.b, coefficients.c, calculated_solution_type, calculated.x1, calculated.x2, expected_solution_type, expected.x1, expected.x2);
}
