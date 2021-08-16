#include <iostream>
#include <cmath>
#include <chrono>

#include "integral.cpp"

// f(x) = -x² + 1
double f(double x){
    return (-(x*x)+1);
};

// f(x, y) = e^(0.1(x²+y²))
double exponential_f(double x, double y){
    return exp(0.1 * (x * x + y * y));
};

double f_fimits[2] {0, 1};
