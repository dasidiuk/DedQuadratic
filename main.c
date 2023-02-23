#include "headers.h"
#include <stdlib.h>

// TODO: rename files .cpp

// You're still using .c files for your code,
// since we write C++ code like it's C, but
// it's still C++ it's better to rename it .cpp

// Since some tools (including compilers) still
// look at extension. And compiling this code
// like C can cause problems.

int main()
{
    // TODO: Try to move your variables as
    // close to their usage as possible, it
    // makes your intentions clearer.

    double solution[3];
    // Why 3?       ^

    // TODO: Constants inserted in code without
    // any explanations are considered bad
    // practice as it's not obvious what this
    // number means.

    // ==> Consider the difference between:
    // int total = 15 * 21000 + 1600;
    // ====================================

    // ==> And:
    // const int number_of_employees = 15;
    // const int salary = 21000;

    // const int taxes = 1600;

    // int total = number_of_employees * salary + taxes;
    // ====================================

    // I think it's obvious in which your intentions
    // are clearer. So, try to make named constants
    // out of all "magic" numbers floating in your code.

    double* parameters = read_stdin();
    solve_equation(parameters, solution);
    free(parameters);
    std_print(solution);
}
