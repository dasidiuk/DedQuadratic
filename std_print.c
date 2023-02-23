#include <stdio.h>

void std_print(double* solution)
{
    switch ((int)solution[0]) {
    case (-1):
        printf("\nNo solutions on the set of real numbers.\n");
        break;
    case (0):
        printf("\nx can take any value.\n");
        break;
    case (1):
        printf("x = %lf\n", solution[1]);
        break;
    case (2):
        printf("x = %lf or x = %lf\n", solution[1], solution[2]);
        break;
    default:
        printf("If you see this, you weren't supposed to...\n");
    }
}
