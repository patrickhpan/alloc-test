A quick test for comparing alloca vs. malloc performance.
So far, just tests running alloca and malloc-free without doing anything.
In the future, I may test performance after doing something non-trivial.

To compile: just use gcc.
To use: alloca-test [num trials] [size of allocation] 
