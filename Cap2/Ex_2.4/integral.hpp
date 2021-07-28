#pragma once

typedef double(*Expression)(double, double);

class Integral
{
public:
    float monteCarlo(Expression f,
               double integrationLimitsX[],
               double integrationLimitsY[],
               int &numberOfDivisions);
};

