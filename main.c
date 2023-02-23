#include "headers.h"
#include <stdlib.h>

int main()
{
    double solution[3];

    double* parameters = read_stdin();
    solve_equation(parameters, solution);
    free(parameters);
    std_print(solution);
}
