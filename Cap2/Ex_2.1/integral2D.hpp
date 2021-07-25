#pragma once

typedef double(*Expression)(double);

class Integral {
  public:
    static double rectangleSum(Expression f, double integrationLimits[], int &numberOfDivisions);

    static double rectangleMean(Expression f, double integrationLimits[], int &numberOfDivisions);
};
