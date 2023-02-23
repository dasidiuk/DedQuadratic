void solve_linear_equation(double* parameters, double* solution)
{
    // IEEE754 numbers are not like integers, they are not infinitely
    // precise, instead their precision wildely depends on the range 
    // and you can encounter lot's of rounding errors.

    // So it's not safe to compare the like integers, instead it's 
    // much better to use some "epsilon" value which will be greater
    // than zero and all values inside will be considered 0.

    // TODO: Compare double safely, not like integers:
    if (parameters[0]) {
        solution[0] = 1.0;
        solution[1] = -parameters[1] / parameters[0];
        //       ^ TODO: not very pretty that you have to explicitly
        //               address solution index when you save it. 
        //
        //               Since both solutions are equally right ones,
        //               there is no "first" or "second" one.
        //              
        //               Do you think you can work around it somehow?
    } else {
        if (!parameters[1]) // TODO: same thing about comparison
            solution[0] = 0.0;
        else
            solution[0] = -1.0;
    }
}
