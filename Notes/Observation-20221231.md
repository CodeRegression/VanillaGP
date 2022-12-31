# Notes #

# Background #

I created an experiment to use "Expression Tree" based Genetic Programming to try and "find" the expression `p[0] / p[1] - p[2]` from 500 training points. However, I made a mistake in creating the training data set, in that I "rounded" the answers. The next result was that my algorithm learned the following: `(p[0] / p[1]) * pow(1, -0.001p[1]) - p[2]`.

So the extra term (`pow(1, -0.001p[1])`) approximates the rounding error. 