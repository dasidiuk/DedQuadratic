// TODO: make modules self-sufficientd

// It's good that you're trying to separate your program
// into small modules, but this is too much.

// Try to put in single .cpp file closely related function
// that together serve a common purpose. Each .cpp
// file should be complete in a way.

// Solving quadratic equation can be such purpose, but
// calculation discriminant -- probably not, because
// discriminant is just an implementation detail of 
// equation solving.

// I know, it's so well-know, we're forgetting what
// it really is. But it's nothing more than just a tool
// to solve equations, it has no purpose on its own,
// and hence doesn't deserve it's own file or module.

// I would even go as far as to making it a static
// function in some file like equation_solving.cpp
// and not providing function declaration in corresponding
// header file.

double discriminant(double* parameters)
//     ^~~~~~~~~~~~ TODO: Name functions with verbs, because they do stuff!
//                        calculate_discriminant would be better!
{
    return parameters[1] * parameters[1] - 4 * parameters[0] * parameters[2];
    //                ^               ^                   ^               ^
    // TODO: Read my parameter naming suggestions in read_stdin.c
}
