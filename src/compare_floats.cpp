#include "compare_floats.h"
#include <cmath>

bool is_equal(double a, double b)
{
    return fabs(a - b) < EPSILON;
}
bool is_less(double a, double b)
{
    return a - b < EPSILON;
}
bool is_greater(double a, double b)
{
    return a - b > EPSILON;
}
