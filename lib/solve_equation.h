#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

//! Defines the type of solution
enum solution_types {
    no_roots, ///< The equation has no solutions
    any_value, ///< The solution can take any value
    one_root, ///< The equation has one possible solution
    two_roots, ///< The equation has no possible solutions
};

//! The structure returned as a solution
typedef struct solution {
    enum solution_types solution_type; ///< Returned type of the solution
    double x1 = 0; ///< The value of the first possible solution
    double x2 = 0; ///< The value of the second possible solution
} solution;

//! A structure containing the A, B and C coefficients of the equation
typedef struct coefficients {
    double a, b, c;
} coefficients;

/**
 * @brief Solves equations of the form Ax^2 + Bx + C = 0
 *
 * @param coefficients the equation's \ref coefficients
 *
 * @return The \ref solution structure
 */
solution solve_equation(coefficients coefficients);

/**
 * @brief Solves linear equation
 *
 * Solves equations of the form A + Bx + C = 0, where A is equal to zero
 *
 * @param coefficients the equation's \ref coefficients
 *
 * @return The \ref solution structure
 */
solution solve_linear_equation(coefficients coefficients);

/**
 * @brief Solves quadratic equations
 *
 * Solves equations of the form Ax^2 + Bx + C = 0, where A is not zero
 *
 * @param coefficients the equation's \ref coefficients
 *
 * @return The \ref solution structure
 */
solution solve_quadratic_equation(coefficients coefficients);

#endif // SOLVE_EQUATION_H_
