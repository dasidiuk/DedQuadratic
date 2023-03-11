#include "compare_floats.h"
#include <cmath>

int compare_floats(double a, double b)
{
    //  0 - values are equal
    //  1 - a is greater than b
    // -1 - a is less than b

    if (is_zero(a) && is_zero(b)) // Checking for equality to zero
        return 0;
    else if (fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPSILON)) // If "a" is equal to "b"
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
