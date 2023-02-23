#ifndef HEADERS_H
#define HEADERS_H

double* read_stdin();

double discriminant(double* parameters);

void solve_equation(double* parameters, double* solution);

void solve_linear_equation(double* parameters, double* solution);

void solve_quadratic_equation(double* parameters, double* solution);

void std_print(double* solution);

#endif // HEADERS_H_
