#include "../lib/compare_floats.h"
#include "../lib/solve_equation.h"
#include <cstdio>
#include <string.h>

#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define NORMAL "\033[0m"
#define STRIKETHROUGH_BEGIN "\e[9m"
#define STRIKETHROUGH_END "\e[0m"

void do_test_linear(coefficients coefficients, linear_solution expected);
void do_test_quadratic(coefficients coefficients, quadratic_solution expected);

int main()
{
    do_test_linear({ .a = 0, .b = 0, .c = 0 }, { .solution_type = any_value, .x = 0 });
    do_test_linear({ .a = 0, .b = 0, .c = 1 }, { .solution_type = no_roots, .x = 0 });
    do_test_linear({ .a = 0, .b = 1, .c = 0 }, { .solution_type = one_root, .x = 0 });
    do_test_linear({ .a = 0, .b = 1, .c = 1 }, { .solution_type = one_root, .x = -1 });

    do_test_quadratic({ .a = 1, .b = 0, .c = 0 }, { .solution_type = one_root, .x1 = 0, .x2 = 0 });
    do_test_quadratic({ .a = 1, .b = 0, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test_quadratic({ .a = 1, .b = 1, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test_quadratic({ .a = 1, .b = 2, .c = 3 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test_quadratic({ .a = 3, .b = 2, .c = 1 }, { .solution_type = no_roots, .x1 = 0, .x2 = 0 });
    do_test_quadratic({ .a = 1, .b = -3, .c = 2 }, { .solution_type = two_roots, .x1 = 1, .x2 = 2 });
    do_test_quadratic({ .a = 1, .b = -3, .c = 2 }, { .solution_type = two_roots, .x1 = 1, .x2 = 2 });
    do_test_quadratic({ .a = 1, .b = 1, .c = -2 }, { .solution_type = two_roots, .x1 = 1, .x2 = -2 });
    do_test_quadratic({ .a = -0.75, .b = -167.2907655, .c = 15785.7720564555 }, { .solution_type = two_roots, .x1 = 71.464646, .x2 = -294.519 });
    do_test_quadratic({ .a = 10008.859, .b = 0, .c = -928878435.8986003 }, { .solution_type = two_roots, .x1 = 304.64016, .x2 = -304.64016 });
}

const char* convert_solution_type_to_str(enum solution_types solution_type)
{
    switch (solution_type) {
    case no_roots:
        return "no_roots";
    case any_value:
        return "any_value";
    case one_root:
        return "one_root";
    case two_roots:
        return "two_roots";
    }
}

void do_test_linear(coefficients coefficients, linear_solution expected)
{
    linear_solution calculated = solve_linear_equation(coefficients);
    if (calculated.solution_type == expected.solution_type && ((!compare_floats(expected.x, calculated.x) && !compare_floats(expected.x, calculated.x)) || (!compare_floats(expected.x, calculated.x) && !compare_floats(expected.x, calculated.x))))
        printf(GREEN "✔" NORMAL "  %2.9g %2.9g %2.9g " GREEN "->" NORMAL " %s: x = %2.9g\n", coefficients.a, coefficients.b, coefficients.c, convert_solution_type_to_str(calculated.solution_type), calculated.x);
    else
        printf(MAGENTA "✘" NORMAL "  %2.9g %2.9g %2.9g " MAGENTA "->" NORMAL " " STRIKETHROUGH_BEGIN MAGENTA "%s: x = %2.9g, x = %2.9g" NORMAL STRIKETHROUGH_END " %s: x = %.9g\n", coefficients.a, coefficients.b, coefficients.c, convert_solution_type_to_str(calculated.solution_type), calculated.x, calculated.x, convert_solution_type_to_str(expected.solution_type), expected.x);
}

void do_test_quadratic(coefficients coefficients, quadratic_solution expected)
{
    quadratic_solution calculated = solve_quadratic_equation(coefficients);
    if (calculated.solution_type == expected.solution_type && ((!compare_floats(expected.x2, calculated.x1) && !compare_floats(expected.x1, calculated.x2)) || (!compare_floats(expected.x1, calculated.x1) && !compare_floats(expected.x2, calculated.x2))))
        printf(GREEN "✔" NORMAL "  %2.9g %2.9g %2.9g " GREEN "->" NORMAL " %s: x = %2.9g, x = %2.9g\n", coefficients.a, coefficients.b, coefficients.c, convert_solution_type_to_str(calculated.solution_type), calculated.x1, calculated.x2);
    else
        printf(MAGENTA "✘" NORMAL "  %2.9g %2.9g %2.9g " MAGENTA "->" NORMAL " " STRIKETHROUGH_BEGIN MAGENTA "%s: x = %2.9g, x = %2.9g" NORMAL STRIKETHROUGH_END " %s: x = %.9g, x = %.9g\n", coefficients.a, coefficients.b, coefficients.c, convert_solution_type_to_str(calculated.solution_type), calculated.x1, calculated.x2, convert_solution_type_to_str(expected.solution_type), expected.x1, expected.x2);
}
