#ifndef SOLVE_LINEAR_EQUATION_H_
#define SOLVE_LINEAR_EQUATION_H_

// TODO: Why are you defining the same thing three times?

typedef struct solution {
    int flag;
    double x1;
    double x2;
} solution;

typedef struct coefficients {
    double a, b, c;
} coefficients;

#endif // SOLVE_LINEAR_EQUATION_H_
