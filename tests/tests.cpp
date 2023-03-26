#include "ansi_colors.h"
#include "compare_floats.h"
#include "solve_equation.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct quadratic_equation_test {
    quadratic_coefficients coefficients;
    quadratic_solution expected_solution;
} quadratic_equation_test;

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

void test_equation_solver(quadratic_equation_test test)
{
    quadratic_solution calculated = solve_equation(test.coefficients);

    if (calculated.solution_type == test.expected_solution.solution_type && ((!compare_floats(test.expected_solution.roots[0], calculated.roots[0]) && !compare_floats(test.expected_solution.roots[1], calculated.roots[1])) || (!compare_floats(test.expected_solution.roots[0], calculated.roots[1]) && !compare_floats(test.expected_solution.roots[1], calculated.roots[0])))) {
        switch (calculated.solution_type) {
        case no_roots:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s.\n"), test.coefficients.a, test.coefficients.b < 0 ? "-" : "+", fabs(test.coefficients.b), test.coefficients.c < 0 ? "-" : "+", fabs(test.coefficients.c), "no roots");
            break;
        case any_value:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s.\n"), test.coefficients.a, test.coefficients.b < 0 ? "-" : "+", fabs(test.coefficients.b), test.coefficients.c < 0 ? "-" : "+", fabs(test.coefficients.c), "any value");
            break;
        case one_root:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s: x = %g.\n"), test.coefficients.a, test.coefficients.b < 0 ? "-" : "+", fabs(test.coefficients.b), test.coefficients.c < 0 ? "-" : "+", fabs(test.coefficients.c), "one root", calculated.roots[first]);
            break;
        case two_roots:
            printf(TEXT_SUCCESS("[    OK    ]") TEXT_BOLD(" %.9gx^2 %s %.9gx %s %.9g = 0  ==>  ") TEXT_SUCCESS("%s: x = %g or x = %g.\n"), test.coefficients.a, test.coefficients.b < 0 ? "-" : "+", fabs(test.coefficients.b), test.coefficients.c < 0 ? "-" : "+", fabs(test.coefficients.c), "two roots", calculated.roots[first], calculated.roots[second]);
            break;
        }
    } else {
        printf(TEXT_ERROR("[  FAILED  ] %.9gx^2 %s %.9gx %s %.9g = 0") TEXT_BOLD("\nExpected: ") TEXT_INFO("%s: x = %g or x = %g") TEXT_BOLD("\n  Actual: ") TEXT_ERROR("%s: x = %g or x = %g\n\n"), test.coefficients.a, test.coefficients.b < 0 ? "-" : "+", fabs(test.coefficients.b), test.coefficients.c < 0 ? "-" : "+", fabs(test.coefficients.c), convert_solution_type_to_str(test.expected_solution.solution_type), test.expected_solution.roots[first], test.expected_solution.roots[second], convert_solution_type_to_str(calculated.solution_type), calculated.roots[first], calculated.roots[second]);
    }
}

int main()
{
    quadratic_equation_test tests[] = {
        { .coefficients = { .a = 0, .b = 0, .c = 0 }, .expected_solution = { .solution_type = any_value, .roots = { 0, 0 } } },
        { .coefficients = { .a = 0, .b = 0, .c = 1 }, .expected_solution = { .solution_type = no_roots, .roots = { 0, 0 } } },
        { .coefficients = { .a = 0, .b = 1, .c = 0 }, .expected_solution = { .solution_type = one_root, .roots = { 0, 0 } } },
        { .coefficients = { .a = 0, .b = 1, .c = 1 }, .expected_solution = { .solution_type = one_root, .roots = { -1, 0 } } },
        { .coefficients = { .a = 1, .b = 0, .c = 0 }, .expected_solution = { .solution_type = one_root, .roots = { 0, 0 } } },
        { .coefficients = { .a = 1, .b = 0, .c = 1 }, .expected_solution = { .solution_type = no_roots, .roots = { 0, 0 } } },
        { .coefficients = { .a = 1, .b = 1, .c = 1 }, .expected_solution = { .solution_type = no_roots, .roots = { 0, 0 } } },
        { .coefficients = { .a = 1, .b = 2, .c = 3 }, .expected_solution = { .solution_type = no_roots, .roots = { 0, 0 } } },
        { .coefficients = { .a = 3, .b = 2, .c = 1 }, .expected_solution = { .solution_type = no_roots, .roots = { 0, 0 } } },
        { .coefficients = { .a = 1, .b = -3, .c = 2 }, .expected_solution = { .solution_type = two_roots, .roots = { 1, 2 } } },
        { .coefficients = { .a = 1, .b = -3, .c = 2 }, .expected_solution = { .solution_type = two_roots, .roots = { 1, 2 } } },
        { .coefficients = { .a = 1, .b = 1, .c = -2 }, .expected_solution = { .solution_type = two_roots, .roots = { 1, -2 } } },
        { .coefficients = { .a = -0.75, .b = -167.2907655, .c = 15785.7720564555 }, .expected_solution = { .solution_type = two_roots, .roots = { 71.464646, -294.519 } } },
        { .coefficients = { .a = 10008.859, .b = 0, .c = -928878435.8986003 }, .expected_solution = { .solution_type = two_roots, .roots = { 304.64016, -304.64016 } } }
    };

    for (uint i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        test_equation_solver(tests[i]);
}
