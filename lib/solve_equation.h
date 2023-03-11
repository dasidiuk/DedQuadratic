#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

enum solution_types {
    no_roots,
    any_value,
    one_root,
    two_roots,
};

typedef struct solution {
    enum solution_types solution_type;
    double x1 = 0;
    double x2 = 0;
} solution;

typedef struct coefficients {
    double a, b, c;
} coefficients;

solution solve_equation(coefficients coefficients);
solution solve_linear_equation(coefficients coefficients);
solution solve_quadratic_equation(coefficients coefficients);

#endif // SOLVE_EQUATION_H_
