#include "ansi_colors.h"
#include "compare_floats.h"
#include "solve_equation.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

const char* convert_solution_type_to_str(enum solution_type solution_type)
{
    switch (solution_type) {
    case no_roots:
        return "no roots";
    case any_value:
        return "any value";
    case one_root:
        return "one root";
    case two_roots:
        return "two roots";
    }
}

void do_test(quadratic_coefficients coefficients, quadratic_solution expected)
{
    quadratic_solution calculated = solve_equation(coefficients);

    if (calculated.solution_type == expected.solution_type && ((!compare_floats(expected.roots[0], calculated.roots[0]) && !compare_floats(expected.roots[1], calculated.roots[1])) || (!compare_floats(expected.roots[0], calculated.roots[1]) && !compare_floats(expected.roots[1], calculated.roots[0])))) {
        switch (calculated.solution_type) {
        case no_roots:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s.\n"), coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c), "no roots");
            break;
        case any_value:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s.\n"), coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c), "any value");
            break;
        case one_root:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s: x = %g.\n"), coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c), "one root", calculated.roots[first]);
            break;
        case two_roots:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s: x = %g or x = %g.\n"), coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c), "two roots", calculated.roots[first], calculated.roots[second]);
            break;
        }
    } else {
        printf(TEXT_ERROR("[  FAILED  ] %.9gx^2 %s %.9gx %s %.9g = 0") TEXT_BOLD("\nExpected: ") TEXT_INFO("%s: x = %g or x = %g") TEXT_BOLD("\n  Actual: ") TEXT_ERROR("%s: x = %g or x = %g\n\n"), coefficients.a, coefficients.b < 0 ? "-" : "+", fabs(coefficients.b), coefficients.c < 0 ? "-" : "+", fabs(coefficients.c), convert_solution_type_to_str(expected.solution_type), expected.roots[first], expected.roots[second], convert_solution_type_to_str(calculated.solution_type), calculated.roots[first], calculated.roots[second]);
    }
}

int main()
{
    do_test({ .a = 0, .b = 0, .c = 0 }, { .solution_type = any_value, .roots = { 0, 0 } });
    do_test({ .a = 0, .b = 0, .c = 1 }, { .solution_type = no_roots, .roots = { 0, 0 } });
    do_test({ .a = 0, .b = 1, .c = 0 }, { .solution_type = one_root, .roots = { 0, 0 } });
    do_test({ .a = 0, .b = 1, .c = 1 }, { .solution_type = one_root, .roots = { -1, 0 } });
    do_test({ .a = 1, .b = 0, .c = 0 }, { .solution_type = one_root, .roots = { 0, 0 } });
    do_test({ .a = 1, .b = 0, .c = 1 }, { .solution_type = no_roots, .roots = { 0, 0 } });
    do_test({ .a = 1, .b = 1, .c = 1 }, { .solution_type = no_roots, .roots = { 0, 0 } });
    do_test({ .a = 1, .b = 2, .c = 3 }, { .solution_type = no_roots, .roots = { 0, 0 } });
    do_test({ .a = 3, .b = 2, .c = 1 }, { .solution_type = no_roots, .roots = { 0, 0 } });
    do_test({ .a = 1, .b = -3, .c = 2 }, { .solution_type = two_roots, .roots = { 1, 2 } });
    do_test({ .a = 1, .b = -3, .c = 2 }, { .solution_type = two_roots, .roots = { 1, 2 } });
    do_test({ .a = 1, .b = 1, .c = -2 }, { .solution_type = two_roots, .roots = { 1, -2 } });
    do_test({ .a = -0.75, .b = -167.2907655, .c = 15785.7720564555 }, { .solution_type = two_roots, .roots = { 71.464646, -294.519 } });
    do_test({ .a = 10008.859, .b = 0, .c = -928878435.8986003 }, { .solution_type = two_roots, .roots = { 304.64016, -304.64016 } });
}
