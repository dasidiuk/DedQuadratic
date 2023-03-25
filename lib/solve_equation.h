#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

enum solution_type : char {
    no_roots = 0,
    one_root = 1,
    two_roots = 2,
    any_value = -1,
};

enum roots : unsigned char {
    first = 0,
    second = 1,
};

typedef struct quadratic_solution {
    enum solution_type solution_type;
    double roots[2];
} quadratic_solution;

typedef struct linear_solution {
    enum solution_type solution_type;
    double x = 0;
} linear_solution;

typedef struct quadratic_coefficients {
    double a, b, c;
} quadratic_coefficients;

typedef struct linear_coefficients {
    double a, b;
} linear_coefficients;

// TODO: White about allowed input
/**
 * @brief Solve equations of the form Ax^2 + Bx + C = 0
 *
 * @param[in] coefficients
 *
 * @return solution
 */
quadratic_solution solve_equation(quadratic_coefficients coefficients);

/**
 * @brief Solve equations of the form Ax + B = 0
 *
 * @param[in] coefficients
 *
 * @return solution
 */
linear_solution solve_linear_equation(linear_coefficients coefficients);

/**
 * @brief Solve equations of the form Ax^2 + Bx + C = 0, where A is not zero
 *
 * @param[in] coefficients
 *
 * @return solution
 */
quadratic_solution solve_quadratic_equation(quadratic_coefficients coefficients);

/**
 * @brief Validate quadratic coefficients for NaN and Inf
 *
 * @param[in] coefficients
 */
void validate_quadratic_coefficients(quadratic_coefficients* coefficients);

/**
 * @brief Validate linear coefficients for NaN and Inf
 *
 * @param[in] coefficients
 */
void validate_linear_coefficients(linear_coefficients* coefficients);

#endif // SOLVE_EQUATION_H_
