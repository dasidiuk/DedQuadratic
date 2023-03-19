#ifndef COMPARE_FLOATS_H_
#define COMPARE_FLOATS_H_

const float EPSILON = 1e-9f;

/**
 * @brief Compares a floating point numbers accurate to \ref EPSILON.
 *
 * @param a, b numbers to compare
 * @return
 *         - 0 — values are equal
 *         - 1 — a is greater than b
 *         - -1 — a is less than b
 */
int compare_floats(double a, double b);

/**
 * @brief Check if a floating point number is zero, accurate to \ref EPSILON.
 */
bool is_zero(double a);

#endif // COMPARE_FLOATS_H_
