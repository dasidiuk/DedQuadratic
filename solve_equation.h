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

// TODO: Desing note: Both your solve_linear_equation and
//       solve_quadratic_equation return the same solution
//       struct.

//       This means that there's a lot of illegal states
//       'solution' can have if you use it to represent
//       linear equation solution (e.g. it can never have
//       two roots not matter what)

//       When you're writing programs your first intuition
//       should be to reduce number of invalid states
//       that are representable by your data, because it:

//       1. Leads to errors (i mean if illegal state is not
//          possible, you will never get it, that should be
//          pretty obvious)

//       2. Make your program harder to understand (it's not
//          clear at all that solve_linear_equations can never
//          return 2 roots, and you need to investigate to
//          know, now imagine this is a lot more complex program,
//          this would take a lot of time, I even have such
//          examples from my work, but it's a hassle to explain
//          here, ask me when we will talk in voice chat or irl, 
//          I will tell more you more about it).

//          You can even consider it a violation of static typing,
//          because set of options that typing tells can be returned
//          is a lot bigger than set of options that is actually
//          possible.

//       3. You use more memory, because you have more state 
//          to represent, event if's not actually a valid return
//          value.

//       Reconsider your design.

solution solve_linear_equation(coefficients coefficients);

solution solve_quadratic_equation(coefficients coefficients);

#endif // SOLVE_EQUATION_H_
