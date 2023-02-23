#ifndef HEADERS_H
#define HEADERS_H

// Using single header for all files is a weird choice.

// It's widely adopted that you need to have single
// .h for a single .cpp, otherwise you're going to confuse
// everybody.

// And it's actually a telling thing that you did it in
// such way, it means your .cpp files are too small now,
// they aren't whole, insufficient.

double* read_stdin();

// Headers used to be just a weird thing C language had
// to do in early days, but now some practices have been
// established that let you use them to your advantage.

// Consider headers public interface of your libraries,
// something that tells new programmer what he can do 
// with it, don't put in the anything that is used only
// inside libraries (e.g. discriminant)

double discriminant(double* parameters);

void solve_equation(double* parameters, double* solution);

void solve_linear_equation(double* parameters, double* solution);

void solve_quadratic_equation(double* parameters, double* solution);

void std_print(double* solution);

#endif // HEADERS_H_
