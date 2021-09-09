#pragma once

#include <random>

typedef double(*Expression2D)(double);
typedef double(*Expression3D)(double);

class Integral
{
public:
    static double monteCarlo2D(
        Expression2D f,
        double integrationLimits[],
        int &numberOfDivisions
    );
    static double monteCarlo3D(
        Expression3D f,
        double integrationLimitsX[],
        double integrationLimitsY[],
        int &numberOfDivisions
    );
};

