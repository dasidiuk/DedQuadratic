#include <stdio.h>

void std_print(double* solution)
//   ^~~~~~~~~ TODO: Read read_stdin.c about naming.

//                   Because this name is pretty meaningless and,
//                   frankly, bold, how can function that describes
//                   solution be "standard print"?
{
    switch ((int)solution[0]) {
    //           ^~~~~~~~~~~ TODO: Oh no!
    //                             Don't use arrays for any values
    //                             that don't have uniform purpose.

    //                             solution[0] is clearly not a solution,
    //                             it's number of solutions, and should
    //                             be called that and separated from the
    //                             rest.

    //                             Use struct and make this right.

    case (-1):
    //   ^  ^ TODO: Weird syntastic choice, I have never seen such.
    //              Reconsider.
        printf("\nNo solutions on the set of real numbers.\n");
        break;
    case (0):
        printf("\nx can take any value.\n");
        break;
    case (1):
        printf("x = %lf\n", solution[1]);
        break;
    case (2):
        printf("x = %lf or x = %lf\n", solution[1], solution[2]);
        break;
    default:
        printf("If you see this, you weren't supposed to...\n");
        // TODO: If this code is reached it's a pretty bad programmer
        //       error (there was a solution's state that wasn't checked).

        //       And there is a specially utiliy in standard library for
        //       telling programmer about program's invariant violations (like such)
        //       ASAP. They are called asserts, use them (especially here!).

    }
}
