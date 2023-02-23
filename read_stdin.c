#include <stdio.h>
#include <stdlib.h>


double* read_stdin()
//      ^~~~~~~~~~ TODO: "read_stdin" is generic as f*ck for such niche function.
//                       It surely does "change double", but it's like calling:
//                       function "function":

//                       void function_that_does_stuff(...);

//                       Like yeah, it's true, but it doesn't actually mean anything!
//                       Same logic applies here. Name should not only be "true", it
//                       should be descriptive and actually useful. It shall be a brief
//                       description of function's functionality.

//                       Always think: can you guess function's purpose by name alone?
//                       If not, rename it. It's that simple.

//                       In this case something like read_coefficients would be much
//                       better, because it actually says something about it's purpose.
{
    // TODO: Just a tip, you can use sizeof on expressions, e.g.
    // sizeof(*parameters), this let's you write calloc in such a way,
    // that it becomes impossible to mismatch element size with  
    // pointer type and mess up your memory:

    // double* parameters = (double*) calloc(3, sizeof(*parameters));
    // If type changes, size changes:                  ^~~~~~~~~~~

    double* parameters = (double*)calloc(3, sizeof(double));
    // This is possible, but way to expensive, because dynamic allocation
    // is pretty expensive.

    // And I would strongly recommend to avoid it in such cases because
    // it will probably take more time than whole equation solving.

    // Imagine someone wants to use your thing to solve hundereds of
    // thousands of equations per second. It's certainly possible
    // considering it's a pretty simple task. 

    // Dynamic allocation would hurt perfomance badly in such case.

    // And, yeah, here you're interacting with user, and users are
    // slow, so it's probably fine. But I feel like dynamic allocation
    // for coefficient is a deliberate choice in your whole equaiton
    // solve, not just in user-interaction part. Am I right?

    // TODO: Try to avoid dynamic allocations during equation solving.

    // Your choice to make parameters elements of the array is feasible, 
    // but then you should probably treat them like an array.

    // TODO: For example using for loop to iterate and read them one
    // by one instead of using "magic" numbers to access them.

    // And I'm afraid this choice will lead this numbers to come up
    // a lot (you do the same thing during solving), so maybe it's
    // better to give them mathematical names "a", "b" and "c"?

    // It should be clearer than using unconventional indicies all
    // over the place. Agreed?
    scanf("%lf %lf %lf", &parameters[0], &parameters[1], &parameters[2]);

    return parameters;
}
