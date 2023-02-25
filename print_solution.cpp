#include "print_solution.h"
#include <assert.h>
#include <stdio.h>

// TODO: I told you that you should make .cpp file bigger
//       in such way that they serv a common purpose and
//       actually useful together.

//       print_soulution.cpp as a separate file is too much
//       separation, because printing_solution is useless
//       on its own, you also need some way to get solution 
//       before you can print it, so it's only logical to 
//       store those together.

//       When I told you to separate function in files i didn't
//       mean to go as far as you did, instead I had in mind 
//       separation of two main things happening in your old
//       program:

//       1. Solving equation (completly fine to put everything
//          about it in single .cpp file, named, for example,
//          equation_solver.cpp)
//
//       2. Interacting with user (some might say frontend to
//          equation_solver.cpp).
//
//          I thought you would put it in something like 
//          interactive_equation_solver.cpp and included
//          equation_solver.h in it.
//
//          And you will have everything related to interaction
//          with user there. And such file doesn't even need .h
//          because you cannot reuse it.
//
//          Something with:
//          int main() { interact_with_user(); ... }
// 
//          Can only be used in your program, and cannot be included
//          as module in any other projects. Because every other
//          project will, at least, have different plans for main()...


void print_solution(solution solution)
{
    switch (solution.flag) {
    case (-1): // Why is it weird?)
               // TODO: I'm not forcing you to change it, it's 
               //       just that it's uncommon, and you'll 
               //       probably need to adapt if you ever want 
               //       to contribute to other project.
               //
               //       But it's probably going to be the case
               //       anyway, so I'll leave it to your judgement.
        printf("\nNo solutions on the set of real numbers.\n");
        break;
    case (0):
        printf("\nx can take any value.\n");
        break;
    case (1):
        printf("\nx = %lf\n", solution.x1);
        break;
    case (2):
        printf("\nx = %lf or x = %lf\n", solution.x1, solution.x2);
        break; // TODO: Maybe add a bit more space after cases?
               //       Now its just a bit "dushno" in here :) 
    default:
        assert(true);
        // TODO: Assert false always succeeds, pretty sure that's
        //       not what you wanted.

        //       assert(something you want to ensure is true);
        //       Asserts are for checking invariants, hence true
        //       is a success, false is a failure.

        // TODO: Also, when assert fails, it prints it's argument,
        //       can you make use of that and add some useful info
        //       to it, so developer gets something better than:

        //       Assert failed because "false".

        //       There's a common idiom that let's you add information
        //       to assert invokation, let's see if you can come up
        //       with it youself, and I will tell you if you can't.

    }
}
