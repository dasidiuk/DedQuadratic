#ifndef SOLVE_EQUATION_H_
#define SOLVE_EQUATION_H_

typedef struct solution {
    int flag;
    double x1;
    double x2;
} solution;

typedef struct coefficients {
    double a, b, c;
} coefficients;

solution solve_linear_equation(coefficients coefficients);

solution solve_quadratic_equation(coefficients coefficients);

#endif // SOLVE_EQUATION_H_
