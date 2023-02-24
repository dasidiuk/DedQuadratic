#ifndef SOLVE_LINEAR_EQUATION_H_
#define SOLVE_LINEAR_EQUATION_H_

typedef struct solution {
    int flag;
    double x1;
    double x2;
} solution;

typedef struct coefficients {
    double a, b, c;
} coefficients;

#endif // SOLVE_LINEAR_EQUATION_H_
