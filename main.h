#ifndef MAIN_H_
#define MAIN_H_


// TODO: Why do you have header file for main file?

//       You only need header files to use your library
//       in some other file. Hence no need to have it
//       for main.cpp file as it's not a library, but
//       an interactive program itself, and cannot be 
//       embedded in anything else than a literate
//       "equation solver".

// TODO: Why solution and coefficients definition is here? 

typedef struct solution {
    int flag; // TODO: is name flag the best you could come up with?
              //
              //       I mean, it's better than 0's element
              //       of some arbitrary array, but still not
              //       good, rename.
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
