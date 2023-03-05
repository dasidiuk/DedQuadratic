#include "compare_floats.h"
#include <cmath>

int compare_floats(double a, double b)
{
    // Knuth's algorithm
    if (fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPSILON)) // If "a" is equal to "b"
        return 0;
    else if ((a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON)) // If "a" is definitely greater than "b"
        return 1;
    else
        return -1;
}

bool is_zero(double a)
{
    return fabs(a) <= EPSILON;
}
