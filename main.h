#ifndef MAIN_H_
#define MAIN_H_

typedef struct solution {
    int flag;
    double x1;
    double x2;
} solution;

typedef struct coefficients {
    double a, b, c;
} coefficients;

void read_coefficients(coefficients* coefs);

solution solve_equation(coefficients coefficients);

void print_solution(solution solution);

#endif // MAIN_H_
