#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

//! Defines the type of a solution
enum solution_types {
    no_roots, ///< The equation has no solutions
    any_value, ///< The solution can take any value
    one_root, ///< The equation has one possible solution
    two_roots, ///< The equation has no possible solutions
};

//! The structure returned as the solution to the quadratic equation.
typedef struct quadratic_solution {
    enum solution_types solution_type; ///< Returned type of the solution
    double x1 = 0; ///< The value of a first possible solution
    double x2 = 0; ///< The value of a second possible solution
} quadratic_solution;

//! The structure returned as the solution to the linear equation.
typedef struct linear_solution {
    enum solution_types solution_type; ///< Returned type of the solution
    double x = 0; ///< The value of a possible solution
} linear_solution;

//! A structure containing the A, B and C coefficients of the equation
typedef struct coefficients {
    double a, b, c;
} coefficients;

/**
 * @brief Solves linear equation
 *
 * Solves equations of the form A + Bx + C = 0, where A is equal to zero
 *
 * @param coefficients the equation's \ref coefficients
 *
 * @return The \ref linear_solution structure
 */
linear_solution solve_linear_equation(coefficients coefficients);

/**
 * @brief Solves quadratic equations
 *
 * Solves equations of the form Ax^2 + Bx + C = 0, where A is not zero
 *
 * @param coefficients the equation's \ref coefficients
 *
 * @return The \ref quadratic_solution structure
 */
quadratic_solution solve_quadratic_equation(coefficients coefficients);

#endif // SOLVE_EQUATION_H_
