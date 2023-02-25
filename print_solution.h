#ifndef PRINT_SOLUTION_H_
#define PRINT_SOLUTION_H_

// TODO: Why are you defining the same thing twice?
//
//       You defined solution in two headers, there's 
//       never a reason to do this, violation of DRY
//       principle.

typedef struct solution {
    int flag;
    double x1;
    double x2;
} solution;

#endif // PRINT_SOLUTION_H_
