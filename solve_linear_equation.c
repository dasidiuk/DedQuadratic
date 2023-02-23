void solve_linear_equation(double* parameters, double* solution)
{
    if (parameters[0]) {
        solution[0] = 1.0;
        solution[1] = -parameters[1] / parameters[0];
    } else {
        if (!parameters[1])
            solution[0] = 0.0;
        else
            solution[0] = -1.0;
    }
}
